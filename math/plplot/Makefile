PORTNAME=	plplot
DISTVERSION=	5.15.0
PORTREVISION=	8
CATEGORIES=	math science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20Source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scientific plotting package
WWW=		https://plplot.sourceforge.net/

LICENSE=	LGPL21+

BUILD_DEPENDS=	bash:shells/bash \
		${FREEFONT_DIR}/FreeMono.ttf:x11-fonts/freefont-ttf
LIB_DEPENDS=	libLASi.so:devel/lasi \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libltdl.so:devel/libltdl
RUN_DEPENDS=	bash:shells/bash \
		${FREEFONT_DIR}/FreeMono.ttf:x11-fonts/freefont-ttf

USES=		compiler:c11 cmake gettext-runtime ghostscript gnome \
		localbase perl5 pathfix pkgconfig shebangfix
USE_GNOME=	cairo pango
USE_PERL5=	build

SHEBANG_FILES=	${WRKSRC}/examples/python/* \
		${WRKSRC}/examples/tcl/* \
		${WRKSRC}/examples/tk/*
SHEBANG_LANG=	sh xtk01 xtk02 xtk04
sh_OLD_CMD=	@SH_EXECUTABLE@
sh_CMD=		${SH}
xtk01_OLD_CMD=	@xtk01_LOCATION@
xtk01_CMD=	${DATADIR}/examples/tk/xtk01
xtk02_OLD_CMD=	@xtk02_LOCATION@
xtk02_CMD=	${DATADIR}/examples/tk/xtk02
xtk04_OLD_CMD=	@xtk04_LOCATION@
xtk04_CMD=	${DATADIR}/examples/tk/xtk04

CMAKE_ARGS=	-DENABLE_java:BOOL=OFF \
		-DENABLE_octave:BOOL=OFF \
		-DENABLE_pdl:BOOL=OFF \
		-DENABLE_ada:BOOL=OFF \
		-DENABLE_d:BOOL=OFF \
		-DENABLE_ocaml:BOOL=OFF \
		-DENABLE_python:BOOL=OFF \
		-DENABLE_pyqt4:BOOL=OFF \
		-DPL_FREETYPE_FONT_PATH:PATH="${FREEFONT_DIR}" \
		-DCMAKE_INSTALL_PKG_CONFIG_DIR:PATH="${PREFIX}/libdata/pkgconfig" \
		-DPLD_plmeta:BOOL=OFF
CFLAGS+=	-D_IS_BUILDING_PLPLOT_PORT_ -DSHAPELIB_INCLUDE_DIR=/nonexistent
USE_LDCONFIG=	yes
CMAKE_OFF=	DEFAULT_NO_QT_DEVICES
LDFLAGS+=	-pthread
DATADIR=	${PREFIX}/share/${PORTNAME}${PORTVERSION}
PLIST_SUB=	PLPLOT_VERSION=${PORTVERSION}

FREEFONT_DIR=	${LOCALBASE}/share/fonts/freefont-ttf

OPTIONS_DEFINE=		DOCS FORTRAN GD LUA QHULL2020 QT5 TCLTK THREADS WXGTK X11
OPTIONS_DEFAULT=	QHULL2020 THREADS WXGTK X11
OPTIONS_SUB=		yes

FORTRAN_USES=		fortran
FORTRAN_CMAKE_BOOL=	ENABLE_fortran
FORTRAN_CONFIGURE_ENV=	CMAKE_Fortran_COMPILER="${FC}"

GD_LIB_DEPENDS=		libgd.so:graphics/gd \
			libpng.so:graphics/png
GD_USES=		jpeg
GD_CMAKE_BOOL=		PLD_png

LUA_USES=		lua
LUA_BUILD_DEPENDS=	swig:devel/swig
LUA_CMAKE_BOOL=		ENABLE_lua
LUA_CMAKE_ON=		-DLUA_EXECUTABLE:FILEPATH="${LUA_CMD}"

QHULL2020_DESC=		Latest Qhull support
QHULL2020_LIB_DEPENDS=	libqhull_r.so:math/qhull
QHULL2020_CMAKE_BOOL=	PL_HAVE_QHULL HAS_LIBQHULL_INCLUDE
QHULL2020_CMAKE_ON=	-DQHULL_RPATH=:FILEPATH="${LOCALBASE}/lib/libqhull_r.so"

TCLTK_LIB_DEPENDS=	libitk.so:x11-toolkits/itk
TCLTK_RUN_DEPENDS=	iwidgets>0:x11-toolkits/iwidgets
TCLTK_USES=		tk
TCLTK_CMAKE_BOOL=	ENABLE_itcl ENABLE_itk ENABLE_tcl ENABLE_tk
TCLTK_IMPLIES=		X11
ITCL_VER=		3.4.1
ITK_VER=		3.3
IWIDGETS_VER=		4.0.1
TCLTK_CMAKE_ON=		-DPLPLOT_TK_VERSION:STRING="${TK_VER}" \
			-DPLPLOT_ITCL_VERSION:STRING="${ITCL_VER}" \
			-DPLPLOT_ITK_VERSION:STRING="${ITK_VER}" \
			-DIWIDGETS_VERSIONS_LIST:STRING="${IWIDGETS_VER};${ITK_VER};${ITCL_VER}" \
			-DTCL_TCLSH:FILEPATH="${TCLSH}" \
			-DTCL_INCLUDE_PATH:PATH="${TCL_INCLUDEDIR}" \
			-DITCL_INCLUDE_PATH:PATH="${LOCALBASE}/include/itcl${ITCL_VER}" \
			-DITCL_LIBRARY:FILEPATH="${LOCALBASE}/lib/libitcl.so" \
			-DTK_INCLUDE_PATH:PATH="${TK_INCLUDEDIR}" \
			-DITK_INCLUDE_PATH:PATH="${LOCALBASE}/include/itk${ITK_VER}" \
			-DITK_LIBRARY:FILEPATH="${LOCALBASE}/lib/libitk.so"

THREADS_CMAKE_BOOL=	THREADS_HAVE_PTHREAD_ARG

QT5_USES=		qt:5
QT5_USE=		QT=core,gui,printsupport,svg,xml,widgets,buildtools:build,qmake:build
QT5_CMAKE_BOOL=		ENABLE_qt

WXGTK_LIB_DEPENDS=	libagg.so:graphics/agg
WXGTK_USE=		WX=3.0+
WXGTK_CMAKE_BOOL=	ENABLE_wxwidgets
WXGTK_CMAKE_ON=		-DwxWidgets_CONFIG_EXECUTABLE:FILEPATH="${WX_CONFIG}"

X11_USES=		xorg
X11_USE=		XORG=ice,sm,x11,xext
X11_CMAKE_BOOL=		PLD_xcairo PLD_xwin

pre-configure:
	${REINPLACE_CMD} -e \
		's|dl dlopen|c dlopen|' \
		${WRKSRC}/cmake/modules/FindLTDL.cmake
	${GREP} -lR "/usr/local" ${WRKSRC}/cmake/modules | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g'
	${REINPLACE_CMD} -e \
		's|shapefil.h|do_not_want_shapefil.h|' \
		${WRKSRC}/cmake/modules/FindShapelib.cmake

.include <bsd.port.mk>

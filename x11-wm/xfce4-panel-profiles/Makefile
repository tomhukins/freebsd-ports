PORTNAME=	xfce4-panel-profiles
PORTVERSION=	1.0.15
CATEGORIES=	x11-wm xfce
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce's panel multiple layouts manager
WWW=		https://docs.xfce.org/apps/xfce4-panel-profiles/start

LICENSE=	GPLv3

USES=		gettext-tools gmake gnome python shebangfix tar:bz2 xfce
USE_GNOME=	gtk30
USE_XFCE=	libmenu panel

SHEBANG_FILES=	xfce4-panel-profiles/panelconfig.py \
		xfce4-panel-profiles/xfce4-panel-profiles.py
HAS_CONFIGURE=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext-runtime
NLS_INSTALL_TARGET=	install-locale

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/share/locale ${STAGEDIR}${PREFIX}/share/${PORTNAME}/locale

.include <bsd.port.mk>

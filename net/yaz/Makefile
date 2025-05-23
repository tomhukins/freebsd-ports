PORTNAME=	yaz
DISTVERSION=	5.31.1
PORTREVISION=	8
CATEGORIES=	net
MASTER_SITES=	https://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Z39.50/SR client and API library
WWW=		https://www.indexdata.com/resources/software/yaz/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libgnutls.so:security/gnutls

USES=		autoreconf gnome iconv libtool ncurses pathfix \
		localbase:ldflags pkgconfig readline shebangfix tcl
SHEBANG_FILES=	src/yaz-asncomp
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes

LIBS+=		-lexecinfo

PORTDOCS=	*

CONFIGURE_ARGS=	--enable-shared \
		--enable-tcpd \
		--with-iconv=${ICONV_PREFIX} \
		--with-icu \
		--with-xml2 \
		--with-xslt

OPTIONS_DEFINE=	DOCS MEMCACHED REDIS

MEMCACHED_DESC=		Memcached distributed cache system support

MEMCACHED_CONFIGURE_WITH=	memcached
MEMCACHED_LIB_DEPENDS=	libmemcached.so:databases/libmemcached

REDIS_CONFIGURE_WITH=	redis
REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis

post-configure:
	@${REINPLACE_CMD} -e 's,[$$]{datarootdir}/man,${PREFIX}/share/man,' \
		${WRKSRC}/doc/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*

.include <bsd.port.mk>

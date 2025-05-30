PORTNAME=	jna
PORTVERSION=	5.15.0
PORTREVISION=	2
CATEGORIES=	devel java

MAINTAINER=	ports@markdixon.name
COMMENT=	Java access to native shared libraries
WWW=		https://github.com/java-native-access/jna

LICENSE=	APACHE20 LGPL21+
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/AL2.0
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LGPL2.1
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	makeinfo:print/texinfo

USES=		autoreconf:build gmake java:ant libtool xorg
USE_GITHUB=	yes
GH_ACCOUNT=	java-native-access
GH_TAGNAME=	0a33062e1971962ca6b283c397ed1de5cc053d33
USE_XORG=	x11 xt
MAKE_ARGS=	-DCC="${CC}" \
		-DLD="${LD}"
MAKE_ENV=	ANT_OPTS="-Drelease -DARCH=${ANT_ARCH}"
ALL_TARGET=	native jar
TEST_TARGET=	test

PLIST_FILES=	${JAVAJARDIR}/jna-platform.jar \
		${JAVAJARDIR}/jna.jar
PORTDOCS=	javadoc platform-${PORTVERSION}-javadoc.jar

OPTIONS_DEFINE=	DOCS

ANT_ARCH=	${ARCH:S/amd64/x86-64/:S/armv6/arm/:S/armv7/arm/:S/i386/x86/:S/powerpc/ppc/}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/native/Makefile

post-build-DOCS-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${ANT} javadoc

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-${ANT_ARCH}.jar \
		${STAGEDIR}${JAVAJARDIR}/jna-platform.jar
	${INSTALL_DATA} ${WRKSRC}/build/jna.jar \
		${STAGEDIR}${JAVAJARDIR}/jna.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} javadoc ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/platform-${PORTVERSION}-javadoc.jar \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

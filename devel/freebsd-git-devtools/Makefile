PORTNAME=	freebsd-git-devtools
PORTVERSION=	20250115
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/freebsd/freebsd-src/${_REV}/tools/tools/git/
DISTFILES=	git-arc.sh \
		git-arc.1 \
		mfc-candidates.lua
DIST_SUBDIR=	${PORTNAME}_${_REV}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Simple Git tools from the FreeBSD src repository
WWW=		https://github.com/freebsd/freebsd-src/tree/main/tools/tools/git

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	arc:devel/arcanist \
		git:devel/git \
		jq:textproc/jq

USES=		lua shebangfix
SHEBANG_FILES=	mfc-candidates.lua
lua_OLD_CMD=	/usr/libexec/flua

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/git-arc \
		bin/mfc-candidates \
		share/man/man1/git-arc.1.gz

_REV=		1132466b56bc87dbdcc32bdf84b93d2fabe67776

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/git-arc.sh ${STAGEDIR}${PREFIX}/bin/git-arc
	${INSTALL_SCRIPT} ${WRKSRC}/mfc-candidates.lua ${STAGEDIR}${PREFIX}/bin/mfc-candidates
	${INSTALL_MAN} ${WRKSRC}/git-arc.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>

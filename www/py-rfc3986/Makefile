PORTNAME=	rfc3986
DISTVERSION=	1.5.0 # before updating to 2.0.0 make sure that dependencies listed in bug#261243 build
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python implementation of RFC 3986
WWW=		https://github.com/python-hyper/rfc3986

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sigmavirus24

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>

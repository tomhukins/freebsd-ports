PORTNAME=	PySCIPOpt
DISTVERSIONPREFIX=	v
DISTVERSION=	5.4.1
PORTREVISION=	1
CATEGORIES=	math python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface and modeling environment for SCIP
WWW=		https://github.com/SCIP-Interfaces/PySCIPOpt

LICENSE=	MIT

LIB_DEPENDS=	libscip.so:math/SCIP
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist cython3 distutils pytest # 1 test fails, see https://github.com/scipopt/PySCIPOpt/issues/840

USE_GITHUB=	yes
GH_ACCOUNT=	scipopt

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyscipopt/scip*.so

# tests as of 5.3.0: 310 passed, 106 skipped, 11 xfailed, 4 warnings in 127.77s (0:02:07)

.include <bsd.port.mk>

PORTNAME=	pyserial
PORTVERSION=	3.5
PORTREVISION=	3
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Serial port encapsulation library for Python
WWW=		https://github.com/pyserial/pyserial

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python shebangfix
SHEBANG_FILES=	examples/*.py

USE_PYTHON=	distutils autoplist concurrent

PORTEXAMPLES=   at_protocol.py port_publisher.py rfc2217_server.py \
		setup-miniterm-py2exe.py setup-rfc2217_server-py2exe.py \
		setup-wxTerminal-py2exe.py tcp_serial_redirect.py \
		wxSerialConfigDialog.py wxTerminal.py

EXAMPLESDIR=    ${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

NO_ARCH=	yes

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} \
	    ${STAGEDIR}${EXAMPLESDIR}

do-test:
	${SETENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
	    ${PYTHON_CMD} ${WRKSRC}/test/test.py

.include <bsd.port.mk>

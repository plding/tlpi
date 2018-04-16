# Makefile.inc - common definitions used by all makefiles

TLPI_DIR = ..
TLPI_LIB = ${TLPI_DIR}/libtlpi.a
TLPI_INC_DIR = ${TLPI_DIR}/lib

# "-Wextra" is a more descriptive synonym for "-W", but only
# available in more recent gcc versions

# Defining _DEFAULT_SOURCE is a workaround to avoid the warnings that
# would otherwise be produced when compiling code that defines _BSD_SOURCE
# or _SVID_SOURCE against glibc headers in version 2.20 and later.
# (The alternative would be to replace each instance of "#define _SVID_SOURCE"
# or "#define _BSD_SOURCE" in the example programs with
# "#define _DEFAULT_SOURCE".)

CFLAGS = -std=c99 -D_XOPEN_SOURCE=600 \
    -D_DEFAULT_SOURCE \
    -g -I${TLPI_INC_DIR} \
    -Wall \
    -W \
    -Wmissing-prototypes \
    -Wno-sign-compare \
    -Wno-unused-parameter

LDLIBS = ${TLPI_LIB} -lm

RM = rm -f

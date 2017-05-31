include ../Makefile.inc

GEN_EXE = copy seek_io bad_exclusive_open atomic_append \
		multi_descriptors t_writev t_readv t_truncate \
		t_mkstemp

EXE = ${GEN_EXE}

all: ${EXE}

allgen: ${GEN_EXE}

${EXE}: ${LIBS}

clean:
	${RM} ${EXE} ${CLEANFILES}

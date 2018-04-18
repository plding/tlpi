include ../Makefile.inc

GEN_EXE = ouch intquit t_kill t_strsignal sig_sender sig_receiver \
	nonreentrant

LINUX_EXE =

EXE = ${GEN_EXE} ${LINUX_EXE}

all: ${EXE}

allgen: ${GEN_EXE}

nonreentrant: nonreentrant.o
	${CC} -o $@ nonreentrant.o ${CFLAGS} ${LDLIBS} ${LINUX_LIBCRYPT}

clean:
	${RM} ${EXE} *.o

showall:
	@echo ${EXE}

${EXE}: ${TLPI_LIB}

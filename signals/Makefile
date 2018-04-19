include ../Makefile.inc

GEN_EXE = ouch intquit t_kill t_strsignal sig_sender sig_receiver \
	nonreentrant sigmask_longjmp t_sigaltstack \
	sig_sender_2 sig_receiver_2 sigmask_longjmp_2 \
	sigmask_longjmp_3

LINUX_EXE =

EXE = ${GEN_EXE} ${LINUX_EXE}

all: ${EXE}

allgen: ${GEN_EXE}

nonreentrant: nonreentrant.o
	${CC} -o $@ nonreentrant.o ${CFLAGS} ${LDLIBS} ${LINUX_LIBCRYPT}

sigmask_longjmp.o: sigmask_longjmp.c
	${CC} -o $@ -DUSE_SIGSETJMP -c sigmask_longjmp.c ${CFLAGS}

sig_receiver_2: sig_receiver_2.o signal_functions_2.o
	${CC} -o $@ sig_receiver_2.o signal_functions_2.o ${CFLAGS} ${LDLIBS}

sigmask_longjmp_2: sigmask_longjmp_2.o signal_functions_2.o

sigmask_longjmp_2.o: sigmask_longjmp_2.c
	${CC} -o $@ -DUSE_SIGSETJMP -c sigmask_longjmp_2.c ${CFLAGS}

sigmask_longjmp_3: sigmask_longjmp_3.o

sigmask_longjmp_3.o: sigmask_longjmp_3.c
	${CC} -o $@ -DUSE_SIGSETJMP -c sigmask_longjmp_3.c ${CFLAGS}

clean:
	${RM} ${EXE} *.o

showall:
	@echo ${EXE}

${EXE}: ${TLPI_LIB}

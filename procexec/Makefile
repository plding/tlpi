include ../Makefile.inc

GEN_EXE = t_fork t_vfork fork_file_sharing fork_whos_on_first \
	fork_sig_sync

LINUX_EXE =

EXE = ${GEN_EXE} ${LINUX_EXE}

all: ${EXE}

allgen: ${GEN_EXE}

clean:
	${RM} ${EXE} *.o

showall:
	@echo ${EXE}

${EXE}: ${TLPI_LIB}

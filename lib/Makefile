include ../Makefile.inc

all: *.c ename.c.inc
	${CC} -c ${CFLAGS} *.c
	${RM} ${LIBTLPI_NAME}
	${AR} rs ${LIBTLPI_NAME} *.o

ename.c.inc:
	sh Build_ename.sh > ename.c.inc
	echo 1>&2 "ename.c.inc built"

clean:
	${RM} ename.c.inc ${LIBTLPI_NAME} ${CLEANFILES}

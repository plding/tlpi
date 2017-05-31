CC = gcc
CFLAGS = -I../lib -std=c99 -D_XOPEN_SOURCE=600 -g -O2 -Wall -W -Wno-unused-parameter -Wno-unused-result
LIBTLPI_NAME = ../libtlpi.a
LIBS = ${LIBTLPI_NAME}
RM = rm -f
CLEANFILES = *.o core.* *.core

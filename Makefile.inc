CC = gcc
CFLAGS = -I../lib -std=c99 -g -O2 -Wall -W -Wno-unused-parameter
LIBTLPI_NAME = ../libtlpi.a
LIBS = ${LIBTLPI_NAME}
RM = rm -f
CLEANFILES = *.o core.* *.core

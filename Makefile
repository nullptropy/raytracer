.POSIX:


CC?=cc
CFLAGS=-Wall -O0
LDFLAGS=-I./canvas

BUILDDIR=build
BINDIR=${BUILDDIR}/bin
OBJDIR=${BUILDDIR}/obj


all: setup ${BINDIR}/canvas_test
${BINDIR}/canvas_test: ${OBJDIR}/canvas.o ${OBJDIR}/test.o
	${CC} ${LDFLAGS} -o $@ ${OBJDIR}/canvas.o ${OBJDIR}/test.o
${OBJDIR}/canvas.o: canvas/canvas.c canvas/canvas.h
	${CC} ${CFLAGS} -c -o $@ canvas/canvas.c
${OBJDIR}/test.o: canvas/test.c canvas/canvas.h
	${CC} ${CFLAGS} -c -o $@ canvas/test.c


clean:
	rm -rf build/
setup:
	mkdir -p build/{bin,obj}

.PHONY: all clean setup

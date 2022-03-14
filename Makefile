.POSIX:


FORMAT=n
CC?=cc
CFLAGS=-Wall -O0
LDFLAGS=-I./canvas

BUILDDIR=build
BINDIR=${BUILDDIR}/bin
OBJDIR=${BUILDDIR}/obj


all: setup ${BINDIR}/canvas_test
${BINDIR}/canvas_test: ${OBJDIR}/canvas.o ${OBJDIR}/test.o ${OBJDIR}/bmp.o
	${CC} ${LDFLAGS} -o $@ ${OBJDIR}/canvas.o ${OBJDIR}/test.o ${OBJDIR}/bmp.o
${OBJDIR}/canvas.o: canvas/canvas.c canvas/canvas.h
	${CC} ${CFLAGS} -c -o $@ canvas/canvas.c
${OBJDIR}/bmp.o: canvas/bmp.c canvas/canvas.h
	${CC} ${CFLAGS} -c -o $@ canvas/bmp.c
${OBJDIR}/test.o: canvas/test.c canvas/canvas.h
	${CC} ${CFLAGS} -c -o $@ canvas/test.c


clean:
	rm -rf build/
setup:
	mkdir -p build/{bin,obj}
format:
	@[[ "${FORMAT}" = "y" ]] && \
		find . -type f -name '*.[ch]' -exec clang-format -i {} + || \
		echo "'make format FORMAT=y' to format."

.PHONY: all clean setup format

CC?=cc
CFLAGS=-Wall -O0
LDFLAGS=-I./canvas

canvas_test: canvas.o canvas/test.c
	${CC} ${LDFLAGS} -o $@ canvas.o canvas/test.c

canvas.o: canvas/canvas.c canvas/canvas.h
	${CC} ${CFLAGS} -c -o $@ canvas/canvas.c

clean:
	rm -f *.o canvas_test

.PHONY: clean

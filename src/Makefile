CC?=cc

bin=a.out

all: $(bin)

$(bin): main.c canvas.h
	${CC} -o $(bin) main.c -Wall -O0

clean:
	rm $(bin)

.PHONY: clean

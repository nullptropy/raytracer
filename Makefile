CC?=cc

bin=a.out

all: $(bin)

$(bin): src/main.c src/canvas.c include/canvas.h
	${CC} -o $(bin) src/main.c src/canvas.c -I./include -Wall -O0

clean:
	rm $(bin)

.PHONY: clean

CFLAGS=-Wall -Wextra -lm -I ./include -I ./src

prep:
	@mkdir -p bin



test1: tests/test1.c
	$(CC) $^ -o bin/$@ $(CFLAGS)
	./bin/$@

clean:
	@rm -rf bin

tests: prep test1

test: prep test1

all: clean prep test



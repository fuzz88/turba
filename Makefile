.PHONY: build

build: main.c
	cc -ggdb -o turba main.c chunk.c memory.c debug.c value.c vm.c compiler.c scanner.c

optimized: main.c
	cc -Wextra -Wall -O3 -o turba main.c chunk.c memory.c debug.c value.c vm.c compiler.c scanner.c

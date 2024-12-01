.PHONY: build

build: main.c
	cc -o turbo main.c chunk.c memory.c debug.c

optimized: main.c
	cc -Wextra -Wall -O3 -o turbo main.c chunk.c memory.c debug.c

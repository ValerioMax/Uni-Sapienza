
all: main.c
	gcc -Wall main.c -o main

clean:
	rm -rf *.o main *.tar.gz

fuzzer: main.c
	clang -g -DFUZZER -O1 -fsanitize=fuzzer,address main.c -o fuzzer

build/main: src/main.c
	gcc -I./raylib/src/ -o build/main src/main.c -L./raylib/src -lraylib -lm

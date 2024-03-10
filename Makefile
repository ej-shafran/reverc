build/main: src/main.c
	gcc -ggdb -Werror -Wall -Wextra -pedantic -I./raylib/src/ -o build/main src/main.c -L./raylib/src -lraylib -lm

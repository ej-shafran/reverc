#include "raylib.h"

int main(void)
{
	InitWindow(800, 800, "Hello, world!");
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RED);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

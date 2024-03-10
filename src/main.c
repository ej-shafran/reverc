#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define SCREEN_PADDING 20
#define SCREEN_COLOR GetColor(0x22bb22)

#define CELL_WIDTH 100
#define CELL_HEIGHT 100
#define CELL_PADDING 10
#define CELL_COLOR GetColor(0xbb22bb)

int main(void)
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "reverc");

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(SCREEN_COLOR);

		Rectangle bounding_box = {
			.x = SCREEN_PADDING,
			.y = SCREEN_PADDING,
			.width = SCREEN_WIDTH - (SCREEN_PADDING * 2),
			.height = SCREEN_HEIGHT - (SCREEN_PADDING * 2),
		};

		for (int x = bounding_box.x; x < bounding_box.width;
		     x += CELL_WIDTH + CELL_PADDING) {
			for (int y = bounding_box.y; y < bounding_box.height;
			     y += CELL_HEIGHT + CELL_PADDING) {
				Rectangle rec = { .y = y,
						  .x = x,
						  .width = CELL_WIDTH,
						  .height = CELL_HEIGHT };

				DrawRectangleRec(rec, CELL_COLOR);
			}
		}

		EndDrawing();

		if (IsKeyReleased(KEY_Q))
			break;
	}

	CloseWindow();
	return 0;
}

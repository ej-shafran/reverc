#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define BOARD_WIDTH 9
#define BOARD_HEIGHT 9

#define CELL_WIDTH_PX 50
#define CELL_HEIGHT_PX 50
#define CELL_PADDING_PX 10

typedef enum {
	CELL_EMPTY = 0,
	CELL_WHITE,
	CELL_BLACK,
} CellState;

int main(void)
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "reverc");

	CellState board[BOARD_WIDTH][BOARD_HEIGHT] = { 0 };

	while (!WindowShouldClose()) {
		if (IsKeyReleased(KEY_Q))
			break;

		BeginDrawing();
		ClearBackground(RED);

		int screenPaddingX =
			(SCREEN_WIDTH -
			 (BOARD_WIDTH * (CELL_WIDTH_PX + CELL_PADDING_PX))) /
			2;
		int screenPaddingY =
			(SCREEN_HEIGHT -
			 (BOARD_HEIGHT * (CELL_HEIGHT_PX + CELL_PADDING_PX))) /
			2;

		for (int x = 0; x < BOARD_WIDTH; ++x) {
			for (int y = 0; y < BOARD_HEIGHT; y++) {
				Rectangle rec = {
					.x = x * (CELL_WIDTH_PX +
						  CELL_PADDING_PX) +
					     screenPaddingX,
					.y = y * (CELL_HEIGHT_PX +
						  CELL_PADDING_PX) +
					     screenPaddingY,
					.width = CELL_WIDTH_PX,
					.height = CELL_HEIGHT_PX,
				};

				Color color;
				switch (board[x][y]) {
				case CELL_WHITE:
					color = WHITE;
				case CELL_BLACK:
					color = BLACK;
				default:
					color = GRAY;
				}

				DrawRectangleRec(rec, color);
			}
		}
		EndDrawing();
	}

	CloseWindow();

	return 0;
}

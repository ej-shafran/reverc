#include "raylib.h"
#include <assert.h>
#include <stdbool.h>

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
	CellState turn = CELL_BLACK;

	while (!WindowShouldClose()) {
		if (IsKeyReleased(KEY_Q))
			goto EXIT;

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
			for (int y = 0; y < BOARD_HEIGHT; ++y) {
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

				bool isEmpty = board[x][y] == CELL_EMPTY;
				bool isClicked =
					IsMouseButtonReleased(
						MOUSE_BUTTON_LEFT) &&
					CheckCollisionPointRec(
						GetMousePosition(), rec);

				if (isEmpty && isClicked) {
					board[x][y] = turn;
					switch (turn) {
					case CELL_BLACK:
						turn = CELL_WHITE;
						break;
					case CELL_WHITE:
						turn = CELL_BLACK;
						break;
					default:
						assert(false && "Invalid turn");
						goto EXIT;
					}
				}

				Color color;
				switch (board[x][y]) {
				case CELL_WHITE:
					color = WHITE;
					break;
				case CELL_BLACK:
					color = BLACK;
					break;
				default:
					color = GRAY;
					break;
				}

				DrawRectangleRec(rec, color);
			}
		}
		EndDrawing();
	}

EXIT:
	CloseWindow();

	return 0;
}

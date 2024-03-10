#include "raylib.h"
#include "./othello.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define CELL_WIDTH_PX 50
#define CELL_HEIGHT_PX 50
#define CELL_PADDING_PX 10

int main(void)
{
	OthelloContext c = {
		.board = { { 0 } },
		.isBlack = true,
	};

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "reverc");

	while (!WindowShouldClose()) {
		if (IsKeyReleased(KEY_Q))
			goto EXIT;

		BeginDrawing();
		ClearBackground(RED);

		int screenPaddingX =
			(SCREEN_WIDTH - (OTHELLO_BOARD_SIZE *
					 (CELL_WIDTH_PX + CELL_PADDING_PX))) /
			2;
		int screenPaddingY =
			(SCREEN_HEIGHT - (OTHELLO_BOARD_SIZE *
					  (CELL_HEIGHT_PX + CELL_PADDING_PX))) /
			2;

		for (int x = 0; x < OTHELLO_BOARD_SIZE; ++x) {
			for (int y = 0; y < OTHELLO_BOARD_SIZE; ++y) {
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

				bool isEmpty = c.board[x][y] ==
					       OTHELLO_CELL_EMPTY;
				bool isClicked =
					IsMouseButtonReleased(
						MOUSE_BUTTON_LEFT) &&
					CheckCollisionPointRec(
						GetMousePosition(), rec);

				if (isEmpty && isClicked) {
					c.board[x][y] =
						c.isBlack ? OTHELLO_CELL_BLACK :
							    OTHELLO_CELL_WHITE;
					c.isBlack = !c.isBlack;
				}

				Color color;
				switch (c.board[x][y]) {
				case OTHELLO_CELL_WHITE:
					color = WHITE;
					break;
				case OTHELLO_CELL_BLACK:
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

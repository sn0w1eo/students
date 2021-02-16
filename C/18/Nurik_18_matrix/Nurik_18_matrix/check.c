#include "check.h"

int check_next_position(int i, int y, int max_height) {
	if (y + i == max_height) {
		y = -i;
	}
	return y;
}

void ExitOnError(int rc, int lineNumber) {
	if (rc) {
		printf("Error: %d. Line: %d.\n", rc, lineNumber);
		_getch();
		exit(rc);
	}
}
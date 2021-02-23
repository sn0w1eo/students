#include "check.h"
#include "stdio.h"
#include "object.h"
#include "stdlib.h"

void exit_on_error(int rc, int lineNumber) {
	if (rc) {
		printf("Error: %d. Line: %d.\n", rc, lineNumber);
		_getch();
		exit(rc);
	}
}


int is_thread_close(int* flag)
{
	switch (*flag)
	{
	case MINUS:
		// if flag == '-' change flag and destroy this thread
		*flag = -1;
		return 1;

	case QUIT:
		// destroy all threads
		return 1;

	default:
		return 0;
	}
}
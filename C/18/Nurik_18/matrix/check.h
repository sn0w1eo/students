#ifndef CHECK_H
#define CHECK_H

// check function result
void exit_on_error(int rc, int lineNumber);

// check flag
int is_thread_close(int* flag);

#endif // !CHECK_H

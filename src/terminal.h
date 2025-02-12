#ifndef TERMINAL_H
#define TERMINAL_H

void die(const char *s);
void enableRawMode(void);
int editorReadKey(void);
int getWindowSize(int *rows, int *cols);
void editorOpen(char *filename);

#endif
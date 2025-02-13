#ifndef TERMINAL_H
#define TERMINAL_H

void die(const char *s);

void enableRawMode(void);

int editorReadKey(void);

int getWindowSize(int *rows, int *cols);

int editorRowCxToRx(erow *row, int cx);

void editorOpen(char *filename);

#endif

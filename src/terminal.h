#ifndef TERMINAL_H
#define TERMINAL_H

void die(const char *s);

void enableRawMode(void);

int editorReadKey(void);

int getWindowSize(int *rows, int *cols);

int editorRowCxToRx(erow *row, int cx);

void editorInsertRow(int at, char *s, size_t len);

void editorInsertChar(int c);

void editorInsertNewline(void);

void editorDelChar(void);

#endif

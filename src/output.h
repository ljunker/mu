#ifndef OUTPUT_H
#define OUTPUT_H
#include "abuf.h"

void editorDrawRows(abuf *ab);

void editorRefreshScreen(void);

void editorSetStatusMessage(const char *fmt, ...);

#endif

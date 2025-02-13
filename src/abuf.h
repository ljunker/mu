#ifndef ABUF_H
#define ABUF_H

typedef struct abuf {
    char *b;
    int len;
} abuf;

#define ABUF_INIT {NULL, 0}

void abAppend(abuf *ab, const char *s, int len);

void abFree(abuf *ab);

#endif

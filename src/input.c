#include "defines.h"
#include "terminal.h"
#include <stdlib.h>
#include <unistd.h>

#include "io.h"
#include "output.h"

void editorMoveCursor(int key) {
    erow *row = (E.cy >= E.numrows) ? NULL : &E.row[E.cy];
    switch (key) {
        case ARROW_LEFT:
            if (E.cx != 0)
                E.cx--;
            else if (E.cy > 0) {
                E.cy--;
                E.cx = E.row[E.cy].size;
            }
            break;
        case ARROW_RIGHT:
            if (row && E.cx < row->size)
                E.cx++;
            else if (row && E.cx == row->size) {
                E.cy++;
                E.cx = 0;
            }
            break;
        case ARROW_UP:
            if (E.cy != 0)
                E.cy--;
            break;
        case ARROW_DOWN:
            if (E.cy < E.numrows)
                E.cy++;
            break;
        default: break;
    }

    row = E.cy >= E.numrows ? NULL : &E.row[E.cy];
    const int rowlen = row ? row->size : 0;
    if (E.cx > rowlen) {
        E.cx = rowlen;
    }
}

void editorProcessKeypress(void) {
    static int quitTimes = MU_QUIT_TIMES;
    const int c = editorReadKey();
    switch (c) {
        case '\r':
            break;
        case CTRL_KEY('q'):
            if (E.dirty && quitTimes > 0) {
                editorSetStatusMessage("WARNING: File has unsaved changes. "
                                       "Press c-q %d more times to quit", quitTimes);
                quitTimes--;
                return;
            }
            write(STDOUT_FILENO, "\x1b[2J", 4);
            write(STDOUT_FILENO, "\x1b[H", 3);
            exit(0);
        case CTRL_KEY('s'):
            editorSave();
            break;
        case HOME_KEY:
            E.cx = 0;
            break;
        case END_KEY:
            if (E.cy < E.numrows)
                E.cx = E.row[E.cy].size;
            break;
        case BACKSPACE:
        case CTRL_KEY('h'):
        case DEL_KEY:
            if (c == DEL_KEY) editorMoveCursor(ARROW_RIGHT);
            editorDelChar();
            break;
        case PAGE_UP:
        case PAGE_DOWN: {
            if (c == PAGE_UP) {
                E.cy = E.rowoff;
            } else if (c == PAGE_DOWN) {
                E.cy = E.rowoff + E.screenrows - 1;
                if (E.cy > E.numrows)
                    E.cy = E.numrows;
            }
            int times = E.screenrows;
            while (times--) {
                editorMoveCursor(c == PAGE_UP ? ARROW_UP : ARROW_DOWN);
            }
        }
        break;
        case ARROW_UP:
        case ARROW_DOWN:
        case ARROW_LEFT:
        case ARROW_RIGHT:
            editorMoveCursor(c);
            break;
        case CTRL_KEY('l'):
        case '\x1b':
            break;
        default:
            editorInsertChar(c);
            break;
    }
    quitTimes = MU_QUIT_TIMES;
}

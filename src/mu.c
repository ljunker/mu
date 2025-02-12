/*** includes ***/
#include "defines.h"
#include "terminal.h"
#include "abuf.h"
#include "input.h"
#include "output.h"

/*** init ***/

void initEditor(void) {
    E.cx = 0;
    E.cy = 0;
    E.numrows = 0;
    if (getWindowSize(&E.screenrows, &E.screencols) == -1) die("getWindowSize");
}

int main(int argc, char *argv[]) {
    enableRawMode();
    initEditor();
    if (argc >= 2) {
        editorOpen(argv[1]);
    }
    while (1) {
        editorRefreshScreen();
        editorProcessKeypress();
    }
    return 0;
}

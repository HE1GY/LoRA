#include <sys/stat.h>
#include <errno.h>
#include <stdint.h>

caddr_t _sbrk(int incr) {
    extern char _end;       // Defined in linker script
    static char *heap_end;
    char *prev_heap_end;

    if (heap_end == 0) {
        heap_end = &_end;
    }
    prev_heap_end = heap_end;
    heap_end += incr;
    return (caddr_t) prev_heap_end;
}

int _write(int file, char *ptr, int len) {
    (void)file;
    (void)ptr;
    return len;
}

int _read(int file, char *ptr, int len) {
    (void)file;
    (void)ptr;
    return 0;
}

int _close(int file) {
    (void)file;
    return -1;
}

int _fstat(int file, struct stat *st) {
    (void)file;
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file) {
    (void)file;
    return 1;
}

int _lseek(int file, int ptr, int dir) {
    (void)file;
    (void)ptr;
    (void)dir;
    return 0;
}

void _exit(int status) {
    (void)status;
    while (1) {}
}

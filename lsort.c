#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define FATAL(msg) perror(msg); exit(1)

int cmp_char(const void *a, const void *b) {
    return *(char *) a - *(char *)b;
}

int main(int argc, char *argv[]) {
    FILE *file = stdin;

    if (argc > 1 && strcmp(argv[1], "-"))
        if ((file = fopen(argv[1], "r")) == NULL) FATAL("cannot open");

    size_t linecapp = 1024;
    char *linep = malloc(linecapp);
    ssize_t nread;

    while ((nread = getline(&linep, &linecapp, file)) != -1) {
        qsort(linep, nread - 1, 1, cmp_char);
        fputs(linep, stdout);
    }

    if (ferror(file)) FATAL("error");
}


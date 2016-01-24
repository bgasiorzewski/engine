#include "error.h"

#include <stdlib.h>

#include "cl.h"

void die(char *context, char *detail, int code) {
    fprintf(stderr, "FATAL ERROR: %s: %s (%d)\n", context, detail, code);
    exit(1);
}

void check_nn(void *ptr, char *msg) {
    if (ptr == NULL)
        die(msg, "null", 0);
}

void check_ferror(FILE *stream, char *msg) {
    int errord = ferror(stream);
    if (errord)
        die(msg, "ferror", errord);
}

void check_cl(cl_int status, char *msg) {
    if (status != CL_SUCCESS)
        die(msg, "opencl error", status);
}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "(%d) %s\n", error, description);
}

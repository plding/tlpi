#include <signal.h>
#include <string.h>
#include "tlpi_hdr.h"

int
main(int argc, char **argv)
{
    int i;

    for (i = 1; i < NSIG; i++)
        printf("%d: %s\n", i, strsignal(i));

    exit(EXIT_SUCCESS);
}

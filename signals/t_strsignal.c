#include <signal.h>
#include <string.h>
#include "tlpi_hdr.h"

int
main(int argc, char **argv)
{
    printf("SIGINT: %s\n", strsignal(SIGINT));
    printf("SIGTERM: %s\n", strsignal(SIGTERM));

    exit(EXIT_SUCCESS);
}

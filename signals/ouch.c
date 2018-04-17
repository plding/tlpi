/* ouch.c

   Catch the SIGINT signal, generated by typing control-C (^C).

   Note that although we use signal() to establish the signal handler in this
   program, the use of sigaction() is always preferable for this task.
*/
#include <signal.h>
#include "tlpi_hdr.h"

static void
sigHandler(int sig)
{
    printf("Ouch!\n");      /* UNSAFE */
}

int
main(int argc, char **argv)
{
    int j;

    if (signal(SIGINT, sigHandler) == SIG_ERR)
        errExit("signal");

    for (j = 0; ; j++) {
        printf("%d\n", j);
        sleep(3);
    }
}

/* intquit.c

   Catch the SIGINT and SIGQUIT signals, which are normally generated
   by the control-C (^C) and control-\ (^\) keys respectively.

   Note that although we use signal() to establish signal handlers in this
   program, the use of sigaction() is always preferable for this task.
*/
#include <signal.h>
#include "tlpi_hdr.h"

static void
sigHandler(int sig)
{
    static int count = 0;

    if (sig == SIGINT) {
        count++;
        printf("Caught SIGINT (%d)\n", count);
        return;
    }

    printf("Caught SIGQUIT - that's all folks!\n");
    exit(EXIT_SUCCESS);
}

int
main(int argc, char **argv)
{
    /* Establish same handler for SIGINT and SIGQUIT */

    if (signal(SIGINT, sigHandler) == SIG_ERR)
        errExit("signal");
    if (signal(SIGQUIT, sigHandler) == SIG_ERR)
        errExit("signal");

    for (;;)            /* Loop forever, waiting for signals */
        pause();        /* Block until a signal is caught */
}

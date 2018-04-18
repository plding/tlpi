/* sigmask_longjmp.c

   Demonstrate the different effects of longjmp() and siglongjmp()
   on the process signal mask.

   By default, this program uses setjmp() + longjmp(). Compile with
   -DUSE_SIGSETJMP to use sigsetjmp() + siglongjmp().
*/
#define _GNU_SOURCE
#include <string.h>
#include <setjmp.h>
#include <signal.h>
#include "signal_functions.h"
#include "tlpi_hdr.h"

static volatile sig_atomic_t canJump = 0;
                        /* Set to 1 once "env" buffer has been
                           initialized by [sig]setjmp() */
#ifdef USE_SIGSETJMP
static sigjmp_buf env;
#else
static jmp_buf env;
#endif

static void
handler(int sig)
{
    printf("Received signal %d (%s), signal mask is:\n", sig,
            strsignal(sig));
    printSigMask(stdout, NULL);

    if (!canJump) {
        printf("'env' buffer not yet set, doing a simple return\n");
        return;
    }

#ifdef USE_SIGSETJMP
    siglongjmp(env, 1);
#else
    longjmp(env, 1);
#endif
}

int
main(int argc, char **argv)
{
    struct sigaction sa;

    printSigMask(stdout, "Signal mask at startup:\n");

    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_handler = handler;
    if (sigaction(SIGINT, &sa, NULL) == -1)
        errExit("sigaction");

#ifdef USE_SIGSETJMP
    printf("Calling sigsetjmp()\n");
    if (sigsetjmp(env, 1) == 0)
#else
    printf("Calling setjmp()\n");
    if (setjmp(env) == 0)
#endif
        canJump = 1;                    /* Executed after [sig]setjmp() */

    else                                /* Executed after [sig]longjmp() */
        printSigMask(stdout, "After jump from handler, signal mask is:\n");

    for (;;)                            /* Wait for signals until killed */
        pause();
}

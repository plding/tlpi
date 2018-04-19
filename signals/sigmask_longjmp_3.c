#include <signal.h>
#include <setjmp.h>
#include "signal_functions.h"
#include "tlpi_hdr.h"

static volatile sig_atomic_t canJump = 0;
#ifdef USE_SIGSETJMP
static sigjmp_buf env;
#else
static jmp_buf env;
#endif

static void
handler(int sig)
{
    printf("Received signal %d (%s), signal mask is:\n",
            sig, strsignal(sig));
    printSigMask(stdout, NULL);

    if (!canJump) {
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
    printf("Calling sigsetjmp()\n");
    if (setjmp(env) == 0)
#endif
        canJump = 1;
    else
        printSigMask(stdout, "After jump from handler, signal mask is:\n");

    for (;;)
        pause();

    exit(EXIT_SUCCESS);
}

#ifndef SIGNAL_FUNCTIONS_2_H
#define SIGNAL_FUNCTIONS_2_H

#include <signal.h>
#include "tlpi_hdr.h"

void printSigset(FILE *of, const char *prefix, sigset_t *mask);

#endif

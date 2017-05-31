#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
    int fd;
    char template[] = "/tmp/somestringXXXXXX";
    char buf[6] = {0};

    fd = mkstemp(template);
    if (fd == -1)
        errExit("mkstemp");

    printf("Generated filename was: %s\n", template);

    if (write(fd, "hello", 5) != 5)
        fatal("write failed or partly write");

    if (lseek(fd, 0, SEEK_SET) == -1)
        errExit("lseek");

    if (read(fd, buf, 5) == -1)
        errExit("read");

    printf("File content: %s\n", buf);
    
    if (unlink(template) == -1)
        errExit("unlink");

    if (close(fd) == -1)
        errExit("close");

    exit(EXIT_SUCCESS);
}

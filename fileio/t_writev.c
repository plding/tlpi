#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
    int fd;
    struct iovec iov[3];
    struct stat myStruct;
    int x = 7;
    char str[] = "hello world";
    int numWrite, totRequired;

    if (argc != 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file\n", argv[0]);

    fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
        errExit("open");

    if (stat(argv[1], &myStruct) == -1)
        errExit("stat");

    totRequired = 0;

    iov[0].iov_base = &myStruct;
    iov[0].iov_len = sizeof(struct stat);
    totRequired += iov[0].iov_len;

    iov[1].iov_base = &x;
    iov[1].iov_len = sizeof(x);
    totRequired += iov[1].iov_len;

    iov[2].iov_base = str;
    iov[2].iov_len = sizeof(str);
    totRequired += iov[2].iov_len;

    numWrite = writev(fd, iov, 3);
    if (numWrite != totRequired)
        fatal("couldn't write whole buffer");

    if (close(fd) == -1)
        errExit("close");

    exit(EXIT_SUCCESS);
}

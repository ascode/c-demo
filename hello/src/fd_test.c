#include <stdio.h>
#include <fcntl.h>

int main (int argc, char *argv[])
{
    int fd=open("/etc/passwd",O_RDONLY);
    printf("fd: %d\n" , fd);
    return 0;
}

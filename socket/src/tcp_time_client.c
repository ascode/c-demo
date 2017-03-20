#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>

int sockfd;

int main(int argc,char *argv[])
{
    if(argc < 3)
    {
        fprintf(stderr,"usage: %s port\n",argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd < 0)
    {
        fprintf(stderr,"socket:%s\n",strerror(errno));
        exit(1);
    }

    struct sockaddr_in sockaddr;
    memset(&sockaddr,0,sizeof(sockaddr));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET,argv[1],&sockaddr.sin_addr.s_addr);
    socklen_t len = sizeof(sockaddr);

    if(connect(sockfd,(struct sockaddr*)&sockaddr,len) < 0)
    {
        fprintf(stderr,"connect: %s\n",strerror(errno));
        exit(1);
    }
    char buffer[1024];
    memset(buffer,0,sizeof(buffer));
    ssize_t n;
    if((n = read(sockfd,buffer,1024)) < 0)
    {
        fprintf(stderr,"read: %s\n",strerror(errno));
        exit(1);
    }
    else
    {
        printf("%s\n",buffer);
    }

    return 0;
}

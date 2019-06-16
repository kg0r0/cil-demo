#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include 
#include 
#include 
#include 
#include 
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int listen_fd = 0, connect_fd = 0;
    struct sockaddr_in serv_addr; 

    char sendBuff[1025];
    FILE *fpin;
    char s[256];

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(80); 

    bind(listen_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 

    listen(listen_fd, 10); 

    while(1)
    {
        connect_fd = accept(listen_fd, (struct sockaddr*)NULL, NULL); 

	if ((fpin = fopen("/etc/fstab","r")) == NULL) {
                printf("Input file open error!!\n");
        exit(1);
        }

	while (fgets(s, 256, fpin) != NULL) {
		snprintf(sendBuff, sizeof(sendBuff), "%s", s);
		write(connect_fd, sendBuff, strlen(sendBuff)); 
	}
	fclose(fpin);

	if ((fpin = fopen("/proc/cpuinfo","r")) == NULL) {
                printf("Input file open error!!\n");
        exit(1);
        }

	while (fgets(s, 256, fpin) != NULL) {
		snprintf(sendBuff, sizeof(sendBuff), "%s", s);
		write(connect_fd, sendBuff, strlen(sendBuff)); 
	}


	fclose(fpin);
        close(connect_fd);
        sleep(1);
     }
}

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <string.h>
#include <sys/time.h>
struct user_info
{
char username[50];
char password[50];
}a,store[100];

void usage(const char *progname) {
	fprintf(stderr, "Usage: %s <server-port>\n", progname);
} // End usage()

int sock(int port) {
	int sock_fd = socket(AF_INET, SOCK_DGRAM, 0); // socket call
	if(sock_fd == -1) { // Check error condition
		perror("socket failed");
		return -1;
	}
	struct sockaddr_in serv_addr;

	/* bind call, populate struct */
	bzero((char *) &serv_addr, sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);

	if(bind(sock_fd, (const struct sockaddr *)(&serv_addr), sizeof(serv_addr)) < 0) {
		perror("bind");
		close(sock_fd);
		return -1;
	}
	return sock_fd;
}

int main(int argc, char *argv[]) {
	if(argc != 2) {
		usage(argv[0]);
		exit(1);
	}
	int key, i,recv_from_value,send_to_value,f = 0; // 1-register , 2-login, 3-text
	char c[3];
	// Get the server & client port from the command-line
	int server_port = atoi(argv[1]);

	// socket, bind
	int listen_sock_fd = -1;

	listen_sock_fd = sock(server_port);
	if(listen_sock_fd == -1) {
		perror("sock_and_listen");
		exit(100); 
	}
	
	struct sockaddr_in client_addr;	
	int cl_addr_size;
	cl_addr_size = sizeof(client_addr);
	char buf[256], sendbuf[256];
	do
	{
		for ( i = 0; i < 256; i++)
		{
			buf[i] = '\0';
			sendbuf[i] = '\0';
		}
		
		recv_from_value = recvfrom(listen_sock_fd,c,2,0,(struct sockaddr *)(&client_addr),&(cl_addr_size));
		send_to_value = sendto(listen_sock_fd,sendbuf,sizeof(sendbuf),0,(const struct sockaddr *)(&client_addr),(cl_addr_size));
		if(strcmp(c,"1")==0)
		key = 1;
		if(strcmp(c,"2")==0)
		key = 2;
		if(strcmp(c,"3")==0)
		key = 3;	
		if(strcmp(c,"4")==0)
		key = 4;
		switch(key)
		{
		case 1:
			recv_from_value = recvfrom(listen_sock_fd,&a,sizeof(a),0,(struct sockaddr *)(&client_addr),&(cl_addr_size));
			strcpy(store[f].username,a.username);
			strcpy(store[f].password,a.password);
			f++;
			strcpy(sendbuf,"Registration Successful");
			send_to_value = sendto(listen_sock_fd,sendbuf,sizeof(sendbuf),0,(const struct sockaddr *)(&client_addr),(cl_addr_size));
		break;
		case 2:
			recv_from_value = recvfrom(listen_sock_fd,&a,sizeof(a),0,(struct sockaddr *)(&client_addr),&(cl_addr_size));
			for ( i = 0; i < f; i++)
			{
			if(strcmp(a.username,store[i].username)==0)
			{
			if(strcmp(a.password,store[i].password)==0)
			{
			strcpy(sendbuf,"Login Successful");
			break;
			}
			}
			}
			if(i == f)
			{
			strcpy(sendbuf,"Login Unsuccessful");
			}
			send_to_value = sendto(listen_sock_fd,sendbuf,sizeof(sendbuf),0,(const struct sockaddr *)(&client_addr),(cl_addr_size));
		break;	
		case 3:
			recv_from_value = recvfrom(listen_sock_fd,buf,255,0,(struct sockaddr *)(&client_addr),&(cl_addr_size));
			printf("Received : %s\n",buf); 
			printf("Enter the response message to client : ");
			scanf("%[^\n]", sendbuf);
			send_to_value = sendto(listen_sock_fd,sendbuf,sizeof(sendbuf),0,(const struct sockaddr *)(&client_addr),(cl_addr_size));
			break;
		case 4:
			printf("Thank you, Ciao!");
			break;
		default:
			printf("\n Wrong Choice!");
		}
	}while(key!=4);
} // End main()

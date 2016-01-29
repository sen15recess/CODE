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
}a;

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
	serv_addr.sin_port = ntohs(port);

	if(bind(sock_fd, (const struct sockaddr *)(&serv_addr), sizeof(serv_addr)) < 0) {
		perror("bind");
		close(sock_fd);
		return -1;
	}
	return sock_fd;
} 

int main(int argc, char *argv[]) {
	if(argc != 4) {
		usage(argv[0]);
		exit(1);
	}
	int ch=0,send_to_value,recv_from_value,i,l=0,r=0;
	char c[3];
	char buf[256],sendbuf[256];
	// Get the server & client port from the command-line
	int server_port = atoi(argv[2]);
	int client_port = atoi(argv[1]);

	// socket, bind
	int listen_sock_fd = -1;

	listen_sock_fd = sock(client_port);
	if(listen_sock_fd == -1) {
		perror("sock_and_listen");
		exit(100); 
	}

		
	struct sockaddr_in server_addr;	
	bzero((char *) &server_addr, sizeof(server_addr));
	int server_addr_size;
	const char *server_str = argv[3];
	struct in_addr server_addr_udp;
	if (inet_aton(server_str, &server_addr_udp) == 0) {
		fprintf(stderr, "Invalid address: %s\n", server_str);
		exit(2);
	}



	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = server_addr_udp.s_addr;
	server_addr.sin_port = htons(server_port);
	server_addr_size = sizeof(server_addr);
	printf("\nWELCOME TO HOGWARTS\n");	
		do
	{
		printf("\nYour choices :");
		printf("\n1. REGISTER");
		printf("\n2. LOGIN");
		printf("\n3. INTERACT");
		printf("\n4.ESCAPE");
		printf("\nChoose wisely.\n");
		scanf("%d",&ch);
		for ( i = 0; i < 256; i++)
		{
		buf[i] = '\0';
		a.username[i] = '\0';
		a.password[i] = '\0';
		sendbuf[i] = '\0';
		}
		
		switch(ch)
		{
		//register
		case 1:
			strcpy(c,"1");
			send_to_value = sendto(listen_sock_fd,c,sizeof(c),0,(const struct sockaddr *)(&server_addr),(server_addr_size));
			recv_from_value = recvfrom(listen_sock_fd,buf,255,0,(struct sockaddr *)(&server_addr),&(server_addr_size));
			printf("\n---Registration desk---");
			printf("\nEnter an username :");
			scanf("%s",a.username);
			printf("\nEnter a password :");
			scanf("%s",a.password);
			send_to_value = sendto(listen_sock_fd,&a,sizeof(a),0,(const struct sockaddr *)(&server_addr),(server_addr_size)); 
			recv_from_value = recvfrom(listen_sock_fd,buf,255,0,(struct sockaddr *)(&server_addr),&(server_addr_size));
			printf("Received : %s\n",buf); 	
			r = 1;
		break;

		//login
		case 2:
			strcpy(c,"2");
			send_to_value = sendto(listen_sock_fd,c,sizeof(c),0,(const struct sockaddr *)(&server_addr),(server_addr_size));
			recv_from_value = recvfrom(listen_sock_fd,buf,255,0,(struct sockaddr *)(&server_addr),&(server_addr_size));
			if ( r == 1)
			{
			printf("\n---Login Portal---");
			printf("\nEnter username :");
			scanf("%s",a.username);
			printf("\nEnter password :");
			scanf("%s",a.password);
			send_to_value = sendto(listen_sock_fd,&a,sizeof(a),0,(const struct sockaddr *)(&server_addr),(server_addr_size)); 
			recv_from_value = recvfrom(listen_sock_fd,buf,255,0,(struct sockaddr *)(&server_addr),&(server_addr_size));
			printf("Received : %s\n",buf); 	
			l = 1;
			}
			else
			printf("No registered users yet.");
		break;

		//interact
		case 3:
			strcpy(c,"3");
			send_to_value = sendto(listen_sock_fd,c,sizeof(c),0,(const struct sockaddr *)(&server_addr),(server_addr_size));
			recv_from_value = recvfrom(listen_sock_fd,buf,255,0,(struct sockaddr *)(&server_addr),&(server_addr_size));
			if ( l == 1)
			{
			printf("\nEnter request message to send to Server : ");
			scanf("\n%[^\n]", sendbuf);
			send_to_value = sendto(listen_sock_fd,sendbuf,sizeof(sendbuf),0,(const struct sockaddr *)(&server_addr),(server_addr_size)); 
			recv_from_value = recvfrom(listen_sock_fd,buf,255,0,(struct sockaddr *)(&server_addr),&(server_addr_size));
			printf("Received : %s\n",buf); 	
			}
			else
			printf("\nCan't interact without login.");
		break;
		//exit
		case 4:
			strcpy(c,"4");
			send_to_value = sendto(listen_sock_fd,c,sizeof(c),0,(const struct sockaddr *)(&server_addr),(server_addr_size));
			recv_from_value = recvfrom(listen_sock_fd,buf,255,0,(struct sockaddr *)(&server_addr),&(server_addr_size));	
		break;
		default:
			printf("Wrong choice.");
	}
	}while(ch!=4);

} // End main()

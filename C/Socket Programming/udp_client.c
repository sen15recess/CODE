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
	char buf[256], sendbuf[256];
	printf("Enter the message to server : ");
	scanf("%s", sendbuf);
	int send_to_value = sendto(listen_sock_fd,sendbuf,strlen(sendbuf),0,(const struct sockaddr *)(&server_addr),(server_addr_size)); 

	int recv_from_value = recvfrom(listen_sock_fd,buf,255,0,(struct sockaddr *)(&server_addr),&(server_addr_size));
	printf("Received : %s\n",buf); 	
} // End main()

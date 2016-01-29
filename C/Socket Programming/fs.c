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
	fprintf(stderr, "Usage: %s <server-IP> <server-port>\n", progname);
} // End usage()

int sock_and_connect(struct in_addr server_ip, int port) {
	int sock_fd = socket(AF_INET, SOCK_STREAM, 0); // Make appropriate socket(...) call
	if(sock_fd == -1) { // Check error condition
		perror("socket failed");
		return -1;
	}

	//---------- Checkpoint-1: comment out the rest of this function to test until here ----------//
	struct sockaddr_in serv_addr;

	/* blocking connect */
	serv_addr.sin_addr.s_addr = server_ip.s_addr;//INADDR_ANY;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);

	int res = connect(sock_fd,(const struct sockaddr *)(&serv_addr), sizeof(serv_addr));
	if(res == 0) {
		return sock_fd;
	} // connection formed
	else { 
		perror("connect failed");
		return -1;
	}
} // End sock_and_connect()

int main(int argc, char *argv[]) {
	if(argc != 3) {
		usage(argv[0]);
		exit(1);
	}

	// Get the IP address as an in_addr structure, from the string
	const char *server_str = argv[1];
	struct in_addr server_addr;
	if (inet_aton(server_str, &server_addr) == 0) {
		fprintf(stderr, "Invalid address: %s\n", server_str);
		exit(2);
	}

	// Get the server port from the command-line
	int server_port = atoi(argv[2]);

	//---------- Checkpoint-0: comment out the code below to test until here ----------//

	int loop = 0;
	do {
		// Make connection to server
		int sock_fd = sock_and_connect(server_addr, server_port);
		if(sock_fd == -1) {
			fprintf(stderr, "Unable to connect to server\n");
			continue;
		}
		//---------- Checkpoint-2: comment out the code below to test until here ----------//

		char msg_buf[256];
		// Get the message from STDIN
		printf("Enter the request message to server: ");
		scanf("%[^\n]", msg_buf);
		int msg_len = strlen(msg_buf);

		// Send filename via TCP connection to server
		send(sock_fd, msg_buf, msg_len, 0);

		//---------- Checkpoint-3: comment out the code below to test until here ----------//

		char recv_buf[256];
		int num_recd;
		while((num_recd = recv(sock_fd,recv_buf,sizeof(recv_buf),0)) > 0) {
			recv_buf[num_recd]='\0';
			printf("received response message from server:: %s \n", recv_buf);
		}
		close(sock_fd);
		//---------- Checkpoint-5: If you've completed until here then you can test the whole functionality once ----------//

		//---------- Checkpoint-6: UNCOMMENT the line below to test forever loop ----------//
		//loop = 1;

	} while(loop);
} // End main()

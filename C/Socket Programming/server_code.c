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

int sock_and_listen(int port) {
	int sock_fd = socket(AF_INET, SOCK_STREAM, 0); // Make appropriate socket(...) call
	if(sock_fd == -1) { // Check error condition
		perror("socket failed");
		return -1;
	}
	struct sockaddr_in serv_addr;

	//---------- Checkpoint-1a: comment out the rest of this function to test until here ----------//

	/* bind, listen */
	bzero((char *) &serv_addr, sizeof(serv_addr));
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(port);

	if(bind(sock_fd, (const struct sockaddr *)(&serv_addr), sizeof(serv_addr)) < 0) {
		perror("bind");
		close(sock_fd);
		return -1;
	}

	//---------- Checkpoint-1b: comment out the rest of this function to test until here ----------//

	if(listen(sock_fd, SOMAXCONN) < 0) {
		perror("listen");
		close(sock_fd);
		return -1;
	}
	return sock_fd;
} // End sock_and_listen()

int main(int argc, char *argv[]) {
	if(argc != 2) {
		usage(argv[0]);
		exit(1);
	}

	// Get the server port from the command-line
	int server_port = atoi(argv[1]);

	// socket, bind and listen
	int listen_sock_fd = -1;

	listen_sock_fd = sock_and_listen(server_port);
	if(listen_sock_fd == -1) {
		perror("sock_and_listen");
		exit(100); 
	}
	fprintf(stderr, "Listening on port %d\n", server_port);
	//---------- Checkpoint-1: comment out the code below to test until here ----------//

	int loop = 0;
	do {
		printf("Waiting for connection from client...\n");
		// Accept connection from client
		struct sockaddr_in cl_addr;
		int cl_addr_size = sizeof(cl_addr);
		char cl_str[1024];
		int conn_sock_fd = accept(listen_sock_fd,(struct sockaddr *)(&cl_addr),&(cl_addr_size)); // Make appropriate accept(...) call
		if(conn_sock_fd < 0) {
			perror("accept");
			continue;
		}

		//---------- Checkpoint-2: comment out the code below to test until here ----------//

		strcpy(cl_str, inet_ntoa(cl_addr.sin_addr)); // Convert IP address to string for printing
		printf("Connection from %s:%d\n", cl_str, ntohs(cl_addr.sin_port));

		//---------- Checkpoint-3: comment out the code below to test until here ----------//

		// Read message from client
		char msg_buf[256];
		int recd_len = recv(conn_sock_fd,msg_buf,sizeof(msg_buf),0); // Make appropriate recv(...) call
		if(recd_len < 0) {
			perror("recv");
			close(conn_sock_fd);
			continue;
		}
		if(recd_len == 0) {
			fprintf(stderr, "Recd empty message from client\n");
			close(conn_sock_fd);
			continue;
		}
		printf("received request message from client:: %s \n", msg_buf);

		char buf[256];
		printf("Enter the response message to client : ");
		scanf("%[^\n]", buf);
		int msg_len = strlen(buf);

		//---------- Checkpoint-4: comment out the code below to test until here ----------//
		int kc = send(conn_sock_fd,buf,msg_len,0); // Make appropriate send(...) call

		printf("Done sending message:: %s\n", buf);

		close(conn_sock_fd);

		//---------- Checkpoint-5: If you've completed until here then you can test the whole functionality once ----------//

		//---------- Checkpoint-6: UNCOMMENT the line below to test forever loop ----------//
		//loop = 1;
	} while(loop);
} // End main()

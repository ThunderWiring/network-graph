/*
 * server.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: bassam
 */

#include "server.h"

typedef struct sockaddr_in SockAddr_in;


ServerResult Server::connect_to_server() {
	int socket_fd = socket(domain, type, protocol);
	CHECK_EXPR_AND_RETURN(socket_fd < 0, SERVER_SOCKET_ERR);

	SockAddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons((port_number));
	int bind_res = bind(socket_fd, (const struct sockaddr*)&server_addr, sizeof(server_addr));
	CHECK_EXPR_AND_RETURN(bind_res<0, SERVER_BIND_ERR);

	listen(socket_fd, max_backlog_queue_size);

	SockAddr_in client_addr;
	socklen_t client_len(sizeof(client_addr));
	int new_socket_fd = accept(socket_fd, (struct sockaddr*)&client_addr, &client_len);
	CHECK_EXPR_AND_RETURN(new_socket_fd<0, SERVER_ACCEPT_ERR);

	/* server should get client's message here */
	printf("server: got connection from %s port %d\n",
			inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

	return SERVER_NO_ERROR;
}

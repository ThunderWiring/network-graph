/*
 * client.cpp
 *
 *  Created on: Jun 20, 2017
 *      Author: bassam
 */

#include "client.h"

/***************************************************/
/*             Methods' implementation             */
/***************************************************/
 ClientResult Client::get_next_port_num(PortNumber_t* portno) {
	 CHECK_EXPR_AND_RETURN(portno == NULL, CLIENT_ARGUMENT_ERROR);
	 CHECK_EXPR_AND_RETURN(next_port >= port_numbers.size(),
			 	 	 	 	 	 	 	 	 CLIENT_PORT_NUM_ERR);
	 *portno = port_numbers.at(next_port++);
	return CLIENT_NO_ERROR;
}
/******************************************************************************/
 Client::Client( PortNumber_t port_num) {
	this->port_numbers = vector<PortNumber_t>();
	port_numbers.push_back(port_num);
	this->domain = AF_INET;
	this->type = SOCK_STREAM;
	this->protocol = 0;
}

 Client::Client( PortNumber_t port_num,
 			int domain=AF_INET, int type=SOCK_STREAM, int protocol=0) {
	this->port_numbers = vector<PortNumber_t>();
	port_numbers.push_back(port_num);
	this->domain = domain;
	this->type = type;
	this->protocol = protocol;
}
 //----------------------------------------------------------------------------
ClientResult Client::connect_to_server(const char* hostname) {
	CHECK_EXPR_AND_RETURN(hostname == NULL, CLIENT_ARGUMENT_ERROR);

	int socket_fd = socket(domain, type, protocol);
	CHECK_EXPR_AND_RETURN(socket_fd < 0, CLIENT_SOCKET_ERR);

	struct hostent* server = gethostbyname(hostname);
	CHECK_EXPR_AND_RETURN(server == NULL, CLIENT_FINDING_SERVER_ERR);

	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	PortNumber_t portno(0);
	ClientResult res = get_next_port_num(&portno);
	CHECK_EXPR_AND_RETURN(res != CLIENT_NO_ERROR, res);
	bcopy((char *)server->h_addr,
			(char *)&server_addr.sin_addr.s_addr,server->h_length);
	server_addr.sin_port = htons(portno);

	int conn_res = connect(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));
	CHECK_EXPR_AND_RETURN(conn_res < 0, CLIENT_CONNECT_ERR);
	return CLIENT_NO_ERROR;
}

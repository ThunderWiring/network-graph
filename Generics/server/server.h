/*
 * node.h
 *
 *  Created on: Jun 16, 2017
 *      Author: bassam
 */

#ifndef GENERICS_SERVER_H_
#define GENERICS_SERVER_H_

#include <netinet/in.h>
#include <arpa/inet.h>
#include "../utility_using.h"


typedef enum Server_Result_t {
	SERVER_NO_ERROR,
	SERVER_SOCKET_ERR,
	SERVER_BIND_ERR,
	SERVER_ACCEPT_ERR
} ServerResult;
/******************************************************************************/
/*
 * Generic implementation of a server
 * */
class Server {
private: //variables
	PortNumber_t port_number;
	int max_backlog_queue_size;
	//for socket creating:
	int domain;
	int type; /*SOCK_STREAM for TCP and SOCK_DGRAM for UDP*/
	int protocol;

public:
	Server(PortNumber_t port_num);
	Server(PortNumber_t port_num, int max_blocking_size);
	Server(PortNumber_t port_num, int max_blocking_size , int domain , int type , int protcol);

	ServerResult recieve_request();

};




#endif /* GENERICS_SERVER_H_ */

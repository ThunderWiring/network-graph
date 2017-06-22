/*
 * client.h
 *
 *  Created on: Jun 20, 2017
 *      Author: bassam
 */

#ifndef GENERICS_CLIENT_CLIENT_H_
#define GENERICS_CLIENT_CLIENT_H_


#include <netinet/in.h>
#include <netdb.h>
#include "../server/server.h"
#include "../utility_using.h"

typedef enum clientResult_t {
	CLIENT_NO_ERROR,
	CLIENT_ARGUMENT_ERROR,
	CLIENT_SOCKET_ERR,
	CLIENT_FINDING_SERVER_ERR,
	CLIENT_PORT_NUM_ERR,
	CLIENT_CONNECT_ERR
} ClientResult;
/*****************************************************************************/
class Client {
private:
	vector<PortNumber_t> port_numbers; /*the ports that the servers which this client can connect to, are listening.*/
	vector<string> hosts; /*names of the hosts-servers, that client can connect to.*/

	int next_port; //init to 0

	//for socket creating:
	int domain;
	int type; /*SOCK_STREAM for TCP and SOCK_DGRAM for UDP*/
	int protocol;

	void add_host(string& new_host_name); //TODO: surround with try-catch.
	ClientResult get_next_port_num(PortNumber_t* portno);
public:
	/* c'tor */
	Client( PortNumber_t port_num);
	Client( PortNumber_t port_num, int domain, int type, int protocol);

	ClientResult connect_to_server(const char* hostname);
	ClientResult brodcast(); /*send request to all hosts in the 'hosts' vector*/
};



#endif /* GENERICS_CLIENT_CLIENT_H_ */

/*
 * user.h
 *
 *  Created on: Jun 16, 2017
 *      Author: bassam
 */

#ifndef USER_H_
#define USER_H_
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

class User {
private:
	struct addrinfo socket;
public:
	User();
};

#endif /* USER_H_ */

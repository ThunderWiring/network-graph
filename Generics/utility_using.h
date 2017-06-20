/*
 * utility_using.h
 *
 *  Created on: Jun 17, 2017
 *      Author: bassam
 */

/***************************************************/
/* No logic should be implemented in this file.    */
/***************************************************/
#ifndef GENERICS_UTILITY_USING_H_
#define GENERICS_UTILITY_USING_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <vector>

using std::vector;
using std::string;

#define CHECK_EXPR_AND_RETURN(expr, ret_val) \
	if((expr)) return ret_val

typedef uint16_t PortNumber_t;

#endif /* GENERICS_UTILITY_USING_H_ */

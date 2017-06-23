
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
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

typedef uint16_t PortNumber_t;

#define CHECK_EXPR_AND_RETURN(expr, ret_val) \
	if((expr)) return ret_val

#define DEBUG__PRINT_MSG(msg) \
	cout << (msg) << endl

#endif /* GENERICS_UTILITY_USING_H_ */

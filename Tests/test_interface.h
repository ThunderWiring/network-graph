/*
 * test_interface.h
 *
 *  Created on: Jun 22, 2017
 *      Author: bassam
 */

#ifndef TESTS_TEST_INTERFACE_H_
#define TESTS_TEST_INTERFACE_H_

#include <iostream>
#include <string.h>
using std::string;

typedef enum test_res_t {
	PASS,
	FAIL,
	TIMEOUT
} TestResult;


class Test {
public:
	Test(string testname) {std::cout << "running " + testname + "..."<< "\n";}
	virtual ~Test() {}
	virtual TestResult run() = 0;
};


#endif /* TESTS_TEST_INTERFACE_H_ */

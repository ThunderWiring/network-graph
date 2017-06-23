
#ifndef TESTS_TEST_INTERFACE_H_
#define TESTS_TEST_INTERFACE_H_

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using std::string;
using std::cout;
using std::endl;

typedef enum test_res_t {
	PASS,
	FAIL,
	TIMEOUT
} TestResult;

typedef enum test_monitor_status_res_t {
	TEST_MONITOR__SUCCESS,
	TEST_MONITOR__BAD_ARGS
} TestMonitorStatus;

static const int HOSTNAME_LEN = 100;
class Test {
private:
	char buffer[HOSTNAME_LEN];
	string test_name;
protected:
	TestMonitorStatus get_hostname(char* name) {
			if(name == NULL) {
				return  TEST_MONITOR__BAD_ARGS;
			}
			gethostname(buffer, HOSTNAME_LEN);
			strcpy(name, buffer);
			return TEST_MONITOR__SUCCESS;
		}

	void err_report(const char* err_msg) {
		cout << "[ ERROR ] - " + test_name + ":: " + err_msg << endl;
	}

	void dbg_report(const char* msg) {
		cout << "[ DBG INFO ] - " + test_name + ":: " + msg << endl;
	}
public:
	Test(string testname) : buffer ({'\0'}){
		cout << "running " + testname + "..."<< endl;

		test_name = testname;
	}

	virtual ~Test() {}
	virtual TestResult run() = 0;
};


#endif /* TESTS_TEST_INTERFACE_H_ */

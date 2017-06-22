/*
 * main.cpp
 *
 *  Created on: Jun 20, 2017
 *      Author: bassam
 */

#include "test_interface.h"
#include "../Generics/server/server.h"
#include "../Generics/client/client.h"

#define DEFAULT_TEXT_MSG "/_ --> this is a default test msg <-- _/"

/*
 * @Test: Client connects to port via a given port, and passes a given text to
 * 		  server.
 * @input: <port> [text message]
 * */
class Test_SendText : public Test {
private:
	PortNumber_t portno;
	string text;
public:
	Test_SendText(PortNumber_t port_num, string& msg) : Test(string("Test_SendText")),
		portno(port_num), text(msg) {}

	Test_SendText(PortNumber_t port_num):  Test(string("Test_SendText")),
			portno(port_num), text(DEFAULT_TEXT_MSG) {}

	TestResult run() {
		Server server = Server(portno);
		Client client = Client(portno);
		server.recieve_request();
		client.connect_to_server("ubuntu"); //hostname = ubuntu
		return PASS;
	}
};
/******************************************************************************/
//static vector<Test> test_list {
//	Test_SendText(54321)
//};
int main() {
//	for(auto& test : test_list) {
//		test.run();
//	}
	Test_SendText test  = Test_SendText((PortNumber_t)54321);
	test.run();
	return 0;
}

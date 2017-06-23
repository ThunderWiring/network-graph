
#include "test_interface.h"
#include "../Generics/server/server.h"
#include "../Generics/client/client.h"

#define DEFAULT_TEXT_MSG ("/_ --> this is a default test msg <-- _/")

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
		pid_t pid(-1);
		if((pid = fork()) == 0) {
			Server server = Server(portno);
			server.recieve_request();
			dbg_report("server is set");
		} else if (pid > 0) {
			Client client = Client(portno);
			char* name = (char*) malloc(HOSTNAME_LEN * sizeof(char));
			if(name == NULL) {
				err_report("memory allocation for hostname failed.");
				return FAIL;
			}
			get_hostname(name);
			dbg_report("client is establishing connection ... ");
			client.connect_to_server(name);
			dbg_report("client is set");
		} else {

		}
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

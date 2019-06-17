#include "TestSuite.h"

TestSuite* TestSuite::instance = nullptr;
using namespace std;
int main() {
	cout << "HelloW"<<endl;
	
	TestSuite *su = TestSuite::getInstance();
	su->addTestCase({"Test1", "Test2", "Test3","Test4"});
	su->run();
	su->printSummary();
	TestSuite::delInstance();
	cin.get();
	while (1) {}
	return 0;
}

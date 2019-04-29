#include <map>
#include<string>

#include "TestSuite.h"

TestSuite* TestSuite::instance = nullptr;

int main() {
	TestSuite *su = TestSuite::getInstance();
	su->addTestCase({"Test1","Test2"});
	su->run();
	su->printSummary();
	TestSuite::delInstance();
	while (1) {}
	return 0;
}
# README

TestSuite is the test framework that is made so user can maintain their test scalability.

- [What is TestSuite?](#what-is-testsuite)
- [HOW TO add a new test case into the TestSuit](#how-to-add)
- [HOW TO compile](#how-to-compile)

## What is TestSuite?

TestSuite is a scalable test automation framework built in console app using c++.
At the end of the test execution, the user will be able to generate the
summary of test result. Status and the execution result are printed and
shown as a console.

## HOW TO add a new test case into the TestSuite:
_Let's say, the user want to add a test case called "Test3" into TestSuite_**
1. Create Test3.hpp
1. In Test3.hpp include "TestCaseBase.h" header file, and
	declare Test3 class as below to inherit everything from TestCaseBase class
		class Test3 :public TestCaseBase
1. Inside Test3.hpp define macro CREATE_OBJECT(Test3) inside Test3 class,
	which till call clone()
1. In Test3.hpp, also define constructor with is, name and descriptor parameter:
		 Test3(std::string id, std::string na, std::string de);
	, and methods that need to be overridden:
	 	enum TestSuite::ret init() override;
	 	enum TestSuite::ret exec() override;
1. Create Test3.cpp
1. In Test3.cpp, define macro
	 	INSTANTIATE_CLASS(Test3, "Test3_id", "Test3_name", "Test3_desc");
	, where you list the object (Test3), string of test case ID as a string ("Test3_id"), string of test case name
	("Test3_name"), string of test case description ("Test3_desc").
1. Define the rest of the functions in Test3.hpp in Test3.cpp
1. In main.cpp, add Test3 in the list of the test cases to be run
	 	addTestCase({"Test1","Test2","Test3"});

## HOW TO compile:

To compile the code, you would need g++.

### Use command line
1. Open terminal
1. Enter the following command pattern
	 	g++ -o <output file> <list of input file> -I.
	For example:
	 	g++ -o auto main.cpp TestSuite.cpp TestCaseBase.cpp Test1.cpp Test2.cpp Test3.cpp -I.
1. Run ./auto

### Use Makefile
1. Create a Makefile (also available in the repository)
	For example:
	 	auto: main.cpp TestSuite.cpp Test1.cpp TestCaseBase.cpp
			g++ -o auto main.cpp TestSuite.cpp Test1.cpp TestCaseBase.cpp -I.
1. Open terminal
1. Run ./auto
1. Run make

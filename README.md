# README

TestSuite is the test framework that is made so user can maintain their tests to be more scalability.

- [What is TestSuite?](#what-is-testsuite)
- [HOW TO add a new test case into the TestSuit](#how-to-add)
- [HOW TO compile](#how-to-compile)

## What is TestSuite?

TestSuite is a scalable test automation framework built in console app using c++.
At the end of the test execution, the user will be able to generate the
summary of test result. Status and the execution result are printed and
shown as a console.

## HOW TO add a new test case into the TestSuite:
_Let's say, the user want to add a test case called "Test5 into TestSuite_**
1. Create Test5.h
1. In Test5.h include "TestCaseBase.h" header file, and
	declare Test5 class as below to inherit everything from TestCaseBase class
		class Test5 :public TestCaseBase
1. Inside Test5.hpp, define macro CREATE_OBJECT(Test5) inside Test5 class,
	which will call clone()
1. In Test5.hpp, also define constructor with test id, name and descriptor parameter:
		 Test5(std::string id, std::string na, std::string de);
	, and methods that need to be overridden:
	 	enum TestSuite::ret init() override;
	 	enum TestSuite::ret exec() override;
1. Create Test5.cpp
1. In Test5.cpp, define macro
	 	INSTANTIATE_CLASS(Test5, "Test5_id", "Test5_name", "Test5_desc");
	, where you list the object (Test5), string of test case ID as a string ("Test5_id"), string of test case name
	("Test5_name"), string of test case description ("Test5_desc").
1. Define the rest of the functions in Test5.hpp in Test5.cpp
1. Add "Test5.h" in TestSuite.cpp
1. In main.cpp, add Test5 in the list of the test cases to be run
	 	addTestCase({"Test1","Test2","Test3","Test4","Test5"});

## HOW TO compile:

To compile the code, you would need g++.

### Use command line
1. Open terminal
1. Enter the following command pattern
	 	g++ -o <output file> <list of input file> -I.
	For example:
	 	g++ -o auto2 main.cpp TestSuite.cpp Test1.cpp Test2.cpp Test3.cpp Test4.cpp Test5.cpp TestCaseBase.cpp -I. -static-libstdc++
1. Run ./auto

### Use Makefile
1. Create a Makefile (also available in the repository)
	For example:
	 	auto: main.cpp TestSuite.cpp Test1.cpp Test2.cpp Test3.cpp Test4.cpp Test5.cpp TestCaseBase.cpp
			g++ -o auto main.cpp TestSuite.cpp Test1.cpp Test2.cpp Test3.cpp Test4.cpp Test5.cpp TestCaseBase.cpp -I. -static-libstdc++
1. Open terminal
1. Run ./auto
1. Run make

#include "Test1.h"
#include "TestSuite.h"
#include "TestCaseBase.h"

// Public function to add test cases into map
//================= TestCaseBase *addTestType(std::string tcID, TestCaseBase *b) =================
//Purpose:	Add Test 1 object into the tcMap
//PRE: 
//PARAM:
//POST: Calls addTestType and add the test case into the tcMap
//================================================================================================
INSTANTIATE_CLASS(Test1, "1_id", "Test_1_name", "Test_1_des");

// Constructor
//============ TestCaseBase(std::string id, std::string na, std::string de) ================
//Purpose:	Assign test cases values from base function
//PRE:
//PARAM: tcList: List of test cases
//POST: Assigning the test case id, test case name and test case descriptor from base class
//==========================================================================================
Test1::Test1(std::string id, std::string na, std::string de): TestCaseBase(id,na,de)
{
}


// Override initialization function for each test cases 
//========================= enum TestSuite::ret init() =====================================
//Purpose:	Function to initialize the current test case
//PRE:
//PARAM: 
//POST: Returns enum value depending on result of run test case
//==========================================================================================
TestSuite::ret Test1::init() {
	std::cout << "Initializing Test 1" << std::endl;
	doSomething();
	return TestSuite::ret::Success;
}

// Override execution function for each test cases 
//========================= enum TestSuite::ret exec() =====================================
//Purpose:	Function to execute the current test case
//PRE:
//PARAM: 
//POST: Returns enum value depending on result of run test case
//==========================================================================================
TestSuite::ret Test1::exec() {
	std::cout << "Executing Test 1" << std::endl;
	return TestSuite::ret::Success;
}

// Helper function for Test1
//========================= void doSomething() =====================================
//Purpose:	Helper function specifically for Test1
//PRE:
//PARAM: 
//POST: 
//==========================================================================================
void Test1::doSomething() {
	std::cout << "DoSomething Test 1" << std::endl;
}

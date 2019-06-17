#include "Test3.h"
#include "TestSuite.h"
#include "TestCaseBase.h"

// Public function to add test cases into map
//================= TestCaseBase *addTestType(std::string tcID, TestCaseBase *b) =================
//Purpose:	Add Test 1 object into the tcMap
//PRE: 
//PARAM:
//POST: Calls addTestType and add the test case into the tcMap
//================================================================================================
INSTANTIATE_CLASS(Test3, "3_id", "Test_3_name", "Test_3_des");

// Constructor
//============ TestCaseBase(std::string id, std::string na, std::string de) ================
//Purpose:	Assign test cases values from base function
//PRE:
//PARAM: tcList: List of test cases
//POST: Assigning the test case id, test case name and test case descriptor from base class
//==========================================================================================
Test3::Test3(std::string id, std::string na, std::string de): TestCaseBase(id,na,de)
{
}


// Override initialization function for each test cases 
//========================= enum TestSuite::ret init() =====================================
//Purpose:	Function to initialize the current test case
//PRE:
//PARAM: 
//POST: Returns enum value depending on result of run test case
//==========================================================================================
TestSuite::ret Test3::init() {
	std::cout << "Initializing Test 3" << std::endl;
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
TestSuite::ret Test3::exec() {
	std::cout << "Executing Test 3" << std::endl;
	return TestSuite::ret::Failure;
}

// Helper function for Test1
//========================= void doSomething() =====================================
//Purpose:	Helper function specifically for Test1
//PRE:
//PARAM: 
//POST: 
//==========================================================================================
void Test3::doSomething() {
	std::cout << "DoSomething Test 3" << std::endl;
}

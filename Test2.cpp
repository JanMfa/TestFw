#include "Test2.h"
#include "TestSuite.h"


// Public function to add test cases into map
//================= TestCaseBase *addTestType(std::string tcID, TestCaseBase *b) =================
//Purpose:	Add Test 1 object into the tcMap
//PRE: 
//PARAM:
//POST: Calls addTestType and add the test case into the tcMap
//================================================================================================
INSTANTIATE_CLASS(Test2, "2_id", "Test_2_name", "Test_2_des");

// Constructor
//============ TestCaseBase(std::string id, std::string na, std::string de) ================
//Purpose:	Assign test cases values from base function
//PRE:
//PARAM: tcList: List of test cases
//POST: Assigning the test case id, test case name and test case descriptor from base class
//==========================================================================================
Test2::Test2(std::string id, std::string na, std::string de) : TestCaseBase(id, na, de)
{
}


// Override initialization function for each test cases 
//========================= enum TestSuite::ret init() =====================================
//Purpose:	Function to initialize the current test case
//PRE:
//PARAM: 
//POST: Returns enum value depending on result of run test case
//==========================================================================================
TestSuite::ret Test2::init() {
	std::cout << "Initializing Test 2" << std::endl;
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
TestSuite::ret Test2::exec() {
	std::cout << "Executing Test 2" << std::endl;
	return TestSuite::ret::Success;
}

// Helper function for Test2
//========================= void doSomething() =====================================
//Purpose:	Helper function specifically for Test2
//PRE:
//PARAM: 
//POST: 
//==========================================================================================
void Test2::doSomething() {
	std::cout << "DoSomething Test 2" << std::endl;
}

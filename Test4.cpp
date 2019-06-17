#include "Test4.h"
#include "TestSuite.h"
#include "TestCaseBase.h"

// Public function to add test cases into map
//================= TestCaseBase *addTestType(std::string tcID, TestCaseBase *b) =================
//Purpose:	Add Test 1 object into the tcMap
//PRE: 
//PARAM:
//POST: Calls addTestType and add the test case into the tcMap
//================================================================================================
INSTANTIATE_CLASS(Test4, "4_id", "Test_4_name", "Test_4_des");

// Constructor
//============ TestCaseBase(std::string id, std::string na, std::string de) ================
//Purpose:	Assign test cases values from base function
//PRE:
//PARAM: tcList: List of test cases
//POST: Assigning the test case id, test case name and test case descriptor from base class
//==========================================================================================
Test4::Test4(std::string id, std::string na, std::string de): TestCaseBase(id,na,de)
{
}


// Override initialization function for each test cases 
//========================= enum TestSuite::ret init() =====================================
//Purpose:	Function to initialize the current test case
//PRE:
//PARAM: 
//POST: Returns enum value depending on result of run test case
//==========================================================================================
TestSuite::ret Test4::init() {
	std::cout << "Initializing Test 4" << std::endl;
	doSomething();
	return TestSuite::ret::unknown;
}

// Override execution function for each test cases 
//========================= enum TestSuite::ret exec() =====================================
//Purpose:	Function to execute the current test case
//PRE:
//PARAM: 
//POST: Returns enum value depending on result of run test case
//==========================================================================================
TestSuite::ret Test4::exec() {
	std::cout << "Executing Test 4" << std::endl;
	return TestSuite::ret::unknown;
}

// Helper function for Test1
//========================= void doSomething() =====================================
//Purpose:	Helper function specifically for Test1
//PRE:
//PARAM: 
//POST: 
//==========================================================================================
void Test4::doSomething() {
	std::cout << "DoSomething Test 4" << std::endl;
}

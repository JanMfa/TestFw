#ifndef _TEST2_HPP_
#define _TEST2_HPP_

#include "TestCaseBase.h"
class Test2 :
	public TestCaseBase
{
public:
	// Macro to create clone of the Test1 object type
	//============== CREATE_OBJECT(Test2) =============================
	//Purpose: Creates a deep copy of Test2
	//PRE: 
	//PARAM:
	//POST:	Returns covariant return type
	//========================================================================
	CREATE_OBJECT(Test2)

	// Default constructor
	//========================== Test2() =============================
	//Purpose:	Explicitly declare the default constructor to ensure the there is no
	//			uninitialized values for an aggregate class
	//PRE:
	//PARAM:
	//POST:	Compile eror is throwed if value is not initialized 
	//========================================================================
	Test2() = delete;

	// Constructor
	//============ TestCaseBase(std::string id, std::string na, std::string de) ================
	//Purpose:	Assign test cases values from base function
	//PRE:
	//PARAM: tcList: List of test cases
	//POST: Assigning the test case id, test case name and test case descriptor from base class
	//==========================================================================================
	Test2(std::string id, std::string na, std::string de);

	// Override initialization function for each test cases 
	//========================= enum TestSuite::ret init() =====================================
	//Purpose:	Function to initialize the current test case
	//PRE:
	//PARAM: 
	//POST: Returns enum value depending on result of run test case
	//==========================================================================================
	enum TestSuite::ret init() override;


	// Override execution function for each test cases 
	//========================= enum TestSuite::ret exec() =====================================
	//Purpose:	Function to execute the current test case
	//PRE:
	//PARAM: 
	//POST: Returns enum value depending on result of run test case
	//==========================================================================================
	enum TestSuite::ret exec() override;
private:
	// Helper function for Test2
	//========================= void doSomething() =====================================
	//Purpose:	Helper function specifically for Test 2
	//PRE:
	//PARAM: 
	//POST: 
	//==========================================================================================
	void doSomething();
};

#endif // _TEST2_HPP_
#ifndef _TEST4_HPP_
#define _TEST4_HPP_

#include "TestCaseBase.h"


class Test4 :
	public TestCaseBase
{
public:
	// Macro to create clone of the Test1 object type
	//============== CREATE_OBJECT(Test1) =============================
	//Purpose: Creates a deep copy of Test1
	//PRE: 
	//PARAM:
	//POST:	Returns covariant return type
	//========================================================================
	CREATE_OBJECT(Test4)

	// Default constructor
	//========================== Test1() =============================
	//Purpose:	Explicitly declare the default constructor to ensure the there is no
	//			uninitialized values for an aggregate class
	//PRE:
	//PARAM:
	//POST:	Compile eror is throwed if value is not initialized 
	//========================================================================
	Test4() = delete;

	// Constructor
	//============ TestCaseBase(std::string id, std::string na, std::string de) ================
	//Purpose:	Assign test cases values from base function
	//PRE:
	//PARAM: tcList: List of test cases
	//POST: Assigning the test case id, test case name and test case descriptor from base class
	//==========================================================================================
	Test4(std::string id, std::string na, std::string de);

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
	// Helper function for Test1
	//========================= void doSomething() =====================================
	//Purpose:	Helper function specifically for Test 1
	//PRE:
	//PARAM: 
	//POST: 
	//==========================================================================================
	void doSomething();
};

#endif // _TEST3_HPP_

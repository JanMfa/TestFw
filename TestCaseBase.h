// File Description: Class Definition of TestCaseBase Class
// Class Description: TestSuite class is an abstract class which is a test case base class of test cases derived class. 					  
//					  These test cases then will be stored in map tcMap, where it will be use in the TestSuite to add the test case into map suite. 

#ifndef _TESTCASEBASE_HPP_
#define _TESTCASEBASE_HPP_

#include"TestSuite.h"
#include <iostream>
#include <string>

//  This macro returns a deep copy of derived type of the test case base (test case)
#define CREATE_OBJECT(TYPE) \
	TestCaseBase* clone() const { return new TYPE(*this); }

//  This macro calls addTestType and add the test case into the tcMap
#define INSTANTIATE_CLASS(TYPE, NAME, DESC, ID) \
	TestCaseBase* TYPE ## _myBaseCaseClass = \
	TestCaseBase::addTestType(#TYPE, new TYPE(NAME, DESC, ID))


class TestCaseBase
{
public:
	// Constructor
	//============ TestCaseBase(std::string id, std::string na, std::string de) ================
	//Purpose:	Passing test cases values to the derived function
	//PRE:
	//PARAM: id : tcID, na:tcNa, std::string de
	//POST: Passing the test case id, test case name and test case description into derived class
	//==========================================================================================
	TestCaseBase(std::string id, std::string na, std::string de);

	// Initialization function for each test cases 
	//========================= enum TestSuite::ret init() =====================================
	//Purpose:	Function to initialize the current test case
	//PRE:
	//PARAM: 
	//POST: Returns enum value depending on result of run test case
	//==========================================================================================
	virtual enum TestSuite::ret init() = 0;

	// Execution function for each test cases 
	//========================= enum TestSuite::ret exec() =====================================
	//Purpose:	Function to execute the current test case
	//PRE:
	//PARAM: 
	//POST: Returns enum value depending on result of run test case
	//==========================================================================================
	virtual enum TestSuite::ret exec() = 0;

	// Public function to get test case ID
	//================================= getID() ===============================
	//Purpose:	Accessing private variable tcId from other classes
	//PRE:
	//PARAM:
	//POST: Return test case ID
	//=========================================================================
	std::string getID();

	// Public function to get test case name
	//================================= getName() ===============================
	//Purpose:	Accessing private variable tcName from other classes
	//PRE:
	//PARAM:
	//POST: Return test case name
	//=========================================================================
	std::string getName();

	// Public function to get test case description
	//================================= getDesc() ===============================
	//Purpose:	Accessing private variable tcDesc from other classes
	//PRE:
	//PARAM:
	//POST: Return test case description
	//=========================================================================
	std::string getDesc();

	// Public function to creates copy of derived classes
	//======================TestCaseBase *makeBase(std::string tcID)====================
	//Purpose:	Create a copy of the test cases (derived class)
	//PRE:
	//PARAM:
	//POST: Return test case pointer
	//==================================================================================
	static TestCaseBase *makeBase(std::string tcID);

	// Public function to add test cases 
	//================= TestCaseBase *addTestType(std::string tcID, TestCaseBase *b) =================
	//Purpose:	Create a copy of the test cases (derived class)
	//PRE: INSTANTIATE_CLASS macro
	//PARAM:
	//POST: Instantiate the tcMap test case name and test case base pointer and returns TestCaseBase pointer
	//================================================================================================
	static TestCaseBase *addTestType(std::string tcID, TestCaseBase *b);
	
protected:
	// Protected default constructor
	//========================== TestCaseBase() =============================
	//Purpose:	Explicitly declare the default constructor to ensure the there is no
	//			uninitialized values for an aggregate class
	//PRE:
	//PARAM:
	//POST:	Compile eror is throwed if value is not initialized 
	//========================================================================
	TestCaseBase() = delete;

	// Virtual destructor
	//========================== virtual ~TestCaseBase() =========================
	//Purpose: Avoid memory leak in case deletion off a base class pointer problem
	//PRE:
	//PARAM:
	//POST: Allow the derived classes to destroy themselves properly
	//========================================================================
	virtual ~TestCaseBase() = default;

	// Pure virtual function for cloning derived class
	//============== TestCaseBase* clone() const =============================
	//Purpose: Creates a deep copy of derived type of the test case base (test case)
	//PRE: CREATE_OBJECT(tc_name) macro
	//PARAM:
	//POST:	Returns covariant return type
	//========================================================================
	virtual TestCaseBase* clone() const = 0;

private:
	// String variable of test case name
	std::string tcName;

	// String variable of test case description
	std::string tcDesc;

	// String variable of test case ID
	std::string tcId;

	// Static map variable of test case map which consist of test case name and test case base pointer
	static std::map <std::string, TestCaseBase *> tcMap;
};

#endif // _TESTCASEBASE_HPP_


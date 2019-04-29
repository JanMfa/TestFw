#include "TestCaseBase.h"

// Intialization of test case map which consist of test case name and test case base pointer
std::map <std::string, TestCaseBase *> TestCaseBase::tcMap;

// Constructor
//============ TestCaseBase(std::string id, std::string na, std::string de) ================
//Purpose:	Passing test cases values to the derived function
//PRE:
//PARAM: id : tcID, na:tcNa, std::string de
//POST: Passing the test case id, test case name and test case description into derived class
//==========================================================================================
TestCaseBase::TestCaseBase(std::string id, std::string na, std::string de):tcId(id), tcName(na),tcDesc(de)
{
}

// Public function to get test case ID
//================================= getID() ===============================
//Purpose:	Accessing private variable tcId from other classes
//PRE:
//PARAM:
//POST: Return test case ID
//=========================================================================
std::string TestCaseBase::getID() {
	return tcId;
}

// Public function to get test case name
//================================= getName() ===============================
//Purpose:	Accessing private variable tcName from other classes
//PRE:
//PARAM:
//POST: Return test case name
//=========================================================================
std::string TestCaseBase::getName() {
	return tcName;
}

// Public function to get test case description
//================================= getDesc() ===============================
//Purpose:	Accessing private variable tcDesc from other classes
//PRE:
//PARAM:
//POST: Return test case description
//=========================================================================
std::string TestCaseBase::getDesc() {
	return tcDesc;
}


// Public function to creates copy of derived classes
//======================TestCaseBase *makeBase(std::string tcID)====================
//Purpose:	Create a copy of the test cases (derived class)
//PRE:
//PARAM:
//POST: Return test case pointer
//==================================================================================
TestCaseBase* TestCaseBase::makeBase(std::string tcName) {
	TestCaseBase* p = nullptr;
	// Find test case name into tcMap
	auto iter = tcMap.find(tcName);
	// If test case name cannot be found in tcMap return null
	if (iter == tcMap.end()) {
		std::cout << "Test Case " + tcName + " cannot be found";
		return nullptr;
	}
	// Take the TestCaseBase pointer of the particular tcName
	p = iter->second;
	// Returns test case base pointer
	return p->clone();
}

// Public function to add test cases 
//================= TestCaseBase *addTestType(std::string tcID, TestCaseBase *b) =================
//Purpose:	Create a copy of the test cases (derived class)
//PRE: INSTANTIATE_CLASS macro
//PARAM:
//POST: Instantiate the tcMap test case name and test case base pointer and returns TestCaseBase pointer
//================================================================================================
TestCaseBase* TestCaseBase::addTestType(std::string tcName, TestCaseBase* base) {
	// Inserting tcName and TestCaseBase pointer into tcMap
	tcMap.emplace(tcName, base);
	return base;
}
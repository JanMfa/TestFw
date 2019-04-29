// File Description: Class Definition of TestSuite Class
// Class Description: TestSuite class is a class where the test framework started and ended. TestSuite class is designed to be Singleton Class, because there should not
//					  have more than one instance at one time. To create a Singleton class, two conditions need to be fullfilled. They are private 
//					  constructor and static method to return the type of the object of the Singleton class. Accessing this class outside will be occur by
//					  getting the returned value of the instance of this class. TestSuite class is where the user specified test cases are added to the map, executed, 
//					  and generate the report at the end of the test

#ifndef _TESTSUITE_HPP_
#define _TESTSUITE_HPP_

#include<list>
#include<map>
#include<iostream>

class TestCaseBase;

class TestSuite
{
public:
	// Enum of result after the test case finished running 
	enum ret
	{
		Success,
		Failure,
		unknown
	};

	// Enum of status of the test case 
	enum state {
		executed,
		not_executed,
		skipped
	};

	// Struct of test case attribute for test results
	//=========================== struct tc_attr ========================
	// Purpose:	Struct to populate several test cases attributes; 
	//			test case id,test case name, test case description,
	//			test result, and test case status
	//===================================================================
	struct tc_attr {
		std::string tc_id;	// test case id
		std::string tc_name;	// test case name
		std::string tc_desc;	// test case description
		enum ret result = ret::unknown;		// test result
		enum state status = state::not_executed;	// test case status
	};

	// Get Singleton class instance
	//=========================== TestSuite *getInstance() ==================
	//Purpose:	Public static method  to get the instance of singleton class
	//PRE:
	//PARAM:
	//POST: Limiting the number of object creation to only one
	//========================================================================
	static TestSuite *getInstance();

	// Delete Singleton class instance
	//=========================== delInstance() =============================
	//Purpose:	Public static method  to delete the instance of singleton class
	//PRE:
	//PARAM:
	//POST: Delete singleton instance pointer
	//========================================================================
	static void delInstance();

	// Add the test cases in the list into the map
	//============ addTestCase(std::list<std::string>tcList) ================
	//Purpose:	Public method to add the test cases into map suite
	//PRE:
	//PARAM: tcList: List of test cases
	//POST: Inserts a new element in the map if its key is unique
	//========================================================================
	void addTestCase(std::list<std::string>tcList);

	// Run the test cases in the map suite
	//=========================== run() ======================================
	//Purpose:	Public method to run the test cases in the map
	//PRE: map suite cannot be empty
	//PARAM: 
	//POST: Run the test cases inside the map suite and 
	//		inserts a new element in map result if its key is uniue
	//========================================================================
	void run();

	// Print the test cases return values and state of the map result
	//=========================== printSummary() ==================
	//Purpose:	Public method to print the the test suite summary giveb by map result 
	//PRE: map result cannot be empty
	//PARAM: 
	//POST: Run the test cases result inside the map and print the result
	//========================================================================
	void printSummary();

private:
	// Default Constructor
	//=========================== TestSuite() = default ==================
	//Purpose:	Private constructor to serve singleton class
	//PRE:
	//PARAM:
	//POST: Limiting the number of object creation to only one
	//====================================================================
	TestSuite() = default;

	// Default Destructor
	//=========================== ~TestSuite() = default ==================
	//Purpose:	Private destructor to serve singleton class
	//PRE:
	//PARAM:
	//POST: Limiting the number of object creation to only one
	//=====================================================================
	~TestSuite() = default;

	// Static variable single_instance of type Singleton 
	static TestSuite *instance;

	// Map variable that consist of key of the test case id and value of test case attributes 
	std::map<std::string, struct tc_attr> result;

	// Map variable that consist of key of the test case id and value of TestCaseBase class
	std::map<std::string, TestCaseBase*>suite;
};

#endif // _TESTSUITE_HPP_
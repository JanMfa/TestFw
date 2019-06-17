#include "TestSuite.h"
#include "Test1.h"
#include "Test2.h"
#include "Test3.h"
#include "Test4.h"

// Get Singleton class instance
//=========================== TestSuite *getInstance() ==================
//Purpose:	Public static method  to get the instance of singleton class
//PRE:
//PARAM:
//POST: Limiting the number of object creation to only one
//========================================================================
TestSuite * TestSuite::getInstance() {
	// To ensure only one instance is created 
	if (instance == nullptr) {
		instance = new TestSuite();
	}
	return instance;
}

// Delete Singleton class instance
//=========================== delInstance() =============================
//Purpose:	Public static method  to delete the instance of singleton class
//PRE:
//PARAM:
//POST: Delete singleton instance pointer
//========================================================================
void TestSuite::delInstance(){
	if (instance) {
		delete instance;
	}
}

// Add the test cases in the list into the map
//============ addTestCase(std::list<std::string>tcList) ================
//Purpose:	Public method to add the test cases into map suite
//PRE:
//PARAM: tcList: List of test cases
//POST: Inserts a new element in the map if its key is unique
//========================================================================
void TestSuite::addTestCase(std::list<std::string> tcList) {
	for (const auto &tc : tcList)
	{
		TestCaseBase *p = nullptr;
		std::cout << "Adding tc" << tc << std::endl;
		p = TestCaseBase::makeBase(tc);
		/*if (tc == "1") {
			p = new Test1(tc, "Test1" , "Running Test1");
		}
		if (tc == "2") {
			p = new Test2(tc, "Test2", "Running Test2");
		}*/
		suite.emplace(tc, p);
	}
}

// Run the test cases in the map suite
//=========================== run() ======================================
//Purpose:	Public method to run the test cases in the map
//PRE: map suite cannot be empty
//PARAM: 
//POST: Run the test cases inside the map suite and 
//		inserts a new element in map result if its key is uniue
//========================================================================
void TestSuite::run() {
	// for every test case stored in map suite
	for (const auto &entry : suite)
	{
		struct tc_attr attr;
		attr.tc_id = entry.second->getID();
		attr.tc_name = entry.second->getName();
		attr.tc_desc = entry.second->getDesc();
		// initialize the test case
		attr.result = entry.second->init();
		// if the test case is initialized properly
		attr.status = (TestSuite::ret::unknown == attr.result) ? state::not_executed : state::executed;
		if (attr.result == TestSuite::ret::Success )
		{
			// execute the test case
			attr.result = entry.second->exec();
		}
		
		// store the test case result to map result
		result.emplace(entry.first, attr);
	}
}


// Print the test cases return values and state of the map result
//=========================== printSummary() ==================
//Purpose:	Public method to print the the test suite summary giveb by map result 
//PRE: map result cannot be empty
//PARAM: 
//POST: Run the test cases result inside the map and print the result
//========================================================================
void TestSuite::printSummary() {
	std::cout << "======================= SUMMARY ===============================\n";
	for (const auto & entry : result)
	{
		std::string executed = (TestSuite::state::executed == entry.second.status) ? "executed" : "not_executed";
		//std::string result = (TestSuite::ret::Success == entry.second.result) ? "Sucess" : "Failure";
		std::string result;
		if (TestSuite::ret::unknown == entry.second.result){
			result = "Unknown";
		}
		if (TestSuite::ret::Success == entry.second.result){
			result = "Success";
		}
		if (TestSuite::ret::Failure == entry.second.result){
			result = "Failure";
		}
			
		//	std::string result = entry.second.result;
		std::cout << "Test case id " << entry.second.tc_id << ", name " << entry.second.tc_name <<
			", description " << entry.second.tc_desc << ", status " << executed << ", result " << result << std::endl;
	}
}
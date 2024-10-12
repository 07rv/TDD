#include <iostream>
#include <cassert>
using namespace std; 


class StringCalculator {
    public:
    int add(string numbers) {
        if (numbers.empty()) {
            return 0;
        }
        
        return 0;
    }
};


class TestCalculator {
    public:
    void checkTest(string testName, bool testStatus) {
        if (testStatus) 
            cout << testName << " - Pass" << endl;
        else
            cout << testName << " - Fail" << endl;
    }
    
    void testAdd(){
        StringCalculator calculator;

       checkTest("Test 1: Empty string", calculator.add("") == 1);
    }
};


int main(){
    try
    {   TestCalculator test;
        test.testAdd();
        return 0;
    }
    catch(const exception& e)
    {
        cout<< e.what() <<endl;
    }   
}
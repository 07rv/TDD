#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std; 


class StringCalculator {
    public:
    int add(string numbers) {
        if (numbers.empty()) {
            return 0;
        }

        string delimiter = ",";
        vector<int> negativeNumbers;
        int sum = 0;
        stringstream ss(numbers);
        string token;

        while (getline(ss, token, delimiter[0])) {
            if (!token.empty()) {
                int number = stoi(token);
                if (number < 0) {
                    negativeNumbers.push_back(number);
                } else {
                    sum += number;
                }
            }
        }
        return sum;
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

        checkTest("Test 1: Empty string", calculator.add("") == 0);
        
        checkTest("Test 2: Single number", calculator.add("1") == 1);
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
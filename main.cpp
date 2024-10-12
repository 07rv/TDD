#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <iostream>

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

        if (numbers.substr(0, 2) == "//") {
            size_t delimiterIndex = numbers.find("\n");
            delimiter = numbers.substr(2, delimiterIndex - 2);
            numbers = numbers.substr(delimiterIndex + 1);
        }

        replace(numbers.begin(), numbers.end(), '\n', delimiter[0]);

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

        if (!negativeNumbers.empty()) {
            string errorMessage = "negative numbers not allowed ";
            for (int neg : negativeNumbers) {
                errorMessage += to_string(neg) + " ";
            }
            throw runtime_error(errorMessage);
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

        checkTest("Test 3: With ',' delimiter", calculator.add("2,4,6,1") == 14);

        checkTest("Test 4: Newline and comma", calculator.add("1\n2,3") == 6);
        
        checkTest("Test 5: Support custom delimiter", calculator.add("//;\n1;2;3") == 6);

        bool test7Passed = false;
        try {
            calculator.add("1,-2,3");
        } catch (const exception& ex) {
            test7Passed = string(ex.what()) == "negative numbers not allowed -2 ";
        }
        checkTest("Test 6: Negative numbers", test7Passed);

        bool test7Passed = false;
        try {
            calculator.add("1,-2,-3");
        } catch (const exception& ex) {
            test7Passed = string(ex.what()) == "negative numbers not allowed -2 -3 ";
        }
        checkTest("Test 8: Multiple negative numbers", test7Passed);
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
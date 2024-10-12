#include <iostream>
using namespace std; 


class StringCalculator {
    public:
    int add(string numbers) {
        int sum = 0;
        return sum;
    }
};


int main(){
    try
    {
        string inputString = "";
        StringCalculator calculator;

        int sum = calculator.add(inputString);
        cout<<sum<<endl;
    }
    catch(const exception& e)
    {
        cout<< e.what() <<endl;
    }   
}
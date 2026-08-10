#include <iostream>
#include <complex>

using namespace std;

string makeString(string, string);

int main(int, char**){
    string printThis = makeString("I am", "Perry");

    double x = {4.4};
    double y = {5.2};

    cout << x + y << "\n";
    cout << printThis;
}

string makeString(string str1, string str2) {
    return str1 + " " + str2 + "!\n";
}
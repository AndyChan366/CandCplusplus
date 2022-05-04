#include <string>
#include <sstream>
#include <iostream> 
using namespace std;
int main(){
    double a = 123.32;
    string res;
    stringstream ss;
    ss << a;
    ss >> res;//或 res = ss.str();
    cout<<res; 
    return 0;
}


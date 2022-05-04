#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
vector<string> splitString(string str)
{
    istringstream ss(str);
    string s;
    vector<string> res;
    while (ss >> s)
        res.push_back(s);
    return res;
}

int main()
{
    string test;
    getline(cin,test);
    vector<string> ret = splitString(test);
    for (int i=0;i<ret.size();i++)
        cout << ret[i] << endl;
    cout << endl;
    return 0;
}


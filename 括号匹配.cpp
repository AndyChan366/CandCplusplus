#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    int len = s.size();
    map <char, char> m;
    m['('] = ')';
    m['['] = ']';
    m['{'] = '}';
    stack <char> vis;
    int flag = 1;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            vis.push(s[i]);
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (vis.size() && m[vis.top()] == s[i])
                vis.pop();
            else
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag && vis.size() == 0)
        printf("True");
    else
        printf("False");
}









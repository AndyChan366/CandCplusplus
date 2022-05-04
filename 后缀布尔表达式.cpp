/*A同学阅读了后缀表达式后，觉得这种表达式虽然对人不太友好，但是还是蛮有趣的，特别是计算的方法很简单。于是他做了一个布尔表达式计算程序。
一个布尔表达式是包含常量0和1、变量和并、交和补的式子，其中用小写英文字母表示布尔变量，+, *, -分别表示布尔并、交和补。例如，"ab+-", "a-b+1+"等。
实现函数bool eval_BE(const string & exp, map<char, bool> f)；其中串exp表示一个后缀布尔表达式；map表示对布尔表达式中每个变量的赋值。
假定表达式exp均为合法的表达式，只包含以上所述字符，表达式中每个变量均可在f中找到相应的值。
例如，对于exp="ab0++-", f['a']=true, f['b']=true, eval_BE(exp,f) == false。
再如，对于任意赋值映射f, eval_BD("01+", f) == true。
*/
//注：该实现未考虑与或非之间优先级（即没有括号参与进来）。
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

bool eval_BE(const string & exp, map<char, bool> f){
    stack<bool> oper;
    bool x1,x2;
    int i=0;
    while(i!=exp.size()){
        if(exp[i]=='0'){
            oper.push(false);
            i++;
        }
        else if(exp[i]=='1'){
            oper.push(true);
            i++;
        }
        else if(exp[i]>='a' and exp[i]<='z'){
            oper.push(f[exp[i]]);
            i++;
        }
        else if(exp[i]=='+'){
            x1=oper.top();
            oper.pop();
            x2=oper.top();
            oper.pop();
            oper.push(x1 or x2);
            i++;
        }
        else if(exp[i]=='-'){
            x1=oper.top();
            oper.pop();
            oper.push(!x1);
            i++;
        }
        else if(exp[i]=='*'){
            x1=oper.top();
            oper.pop();
            x2=oper.top();
            oper.pop();
            oper.push(x1 and x2);
            i++;
        }
    }
    return oper.top();
}

int main(){
    //测试用例
    string ex="ab0++-";
    map<char,bool> f;
    f['a']=true;
    f['b']=true;
    cout<<eval_BE(ex,f);
}
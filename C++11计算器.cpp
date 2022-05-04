/*传入一个字符串s，计算并返回表达式s的值
各运算符运算结果满足c++11标准的规定
s由整数和运算符'+', '-', '*', '/', '%'组成
保证s有效，s中的操作数、中间结果、最后结果均为整数且在int范围内
例：
"3+2*2-2"    -> 5
"+3/-2"       -> -1
"3+5/2"      -> 5
"89*41%-67+6/-5"    -> 30
"++++5"     -> 5
*/
#include<iostream>
#include<vector>
#include<stack>
#include<numeric>
#include<cstring>
using namespace std;
int symbol(int i,char preSign){
    if(preSign=='-'){
        return -i;
    }
    return i;
}
int calculate(const string &s){
    stack<int> st;
    char preSign='+';
    char oper='+';
    bool isPreSign=true;
    int num=0;
    for(int i=0;i<s.size();++i){
        if(isdigit(s[i])){
            num=num*10+int(s[i]-'0');
            isPreSign=false;
        }
        if(!isdigit(s[i])&&s[i]!=' '||i==s.size()-1){
            if(isPreSign){
                if(s[i]=='-')
                    preSign=(preSign=='+'?'-':'+');
            }
            else{
                switch(oper){
                case '+':
                    st.push(symbol(num,preSign));
                    break;
                case '-':
                    st.push(-symbol(num,preSign));
                    break;
                case '*':
                    st.top()*=symbol(num,preSign);
                    break;
                case '/':
                    st.top()/=symbol(num,preSign);
                    break;
                case '%':
                    st.top()%=symbol(num,preSign);
                    break;
                }
                oper=s[i];
                num=0;
                isPreSign=true;
                preSign='+';
            }
        }
    }
    int res=0;
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}
int main(){
    string s;
    cin>>s;
    int ans=calculate(s);
    cout<<ans<<endl;
}

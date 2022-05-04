#include <iostream>
#include <stack>
using namespace std;
int Priority(char ch){
    switch(ch){
        case '(':
        return 3;
        case '*':
        case '/':
        return 2;
        case '+':
        case '-':
        return 1;
        default:
        return 0;
    }
}
int main(){
    long i = 0, tmp = 0, num1, num2, result;
    stack<long> s_opt, s_num;
    char opt[64] = {0};
    char ch;
    cin >> opt;
    while (opt[i] != '\0' || s_opt.empty() != true){
        if (opt[i] >= '0' && opt[i] <= '9'){
            tmp = tmp * 10 + opt[i] - '0';
            i++;
            if (opt[i] > '9' || opt[i] < '0'){
                s_num.push(tmp);
                tmp = 0;
            }
        }
        else{
            if (s_opt.empty() || (s_opt.top() == '(' && opt[i] != ')')|| Priority(opt[i]) > Priority(s_opt.top())){
            s_opt.push(opt[i]);
            i++;
            continue;
            }
            if (s_opt.top() == '(' && opt[i] == ')'){
                s_opt.pop();
                i++;
                continue;
            }
            if ((opt[i] == ')' && s_opt.top() != '(') ||Priority(opt[i]) <= Priority(s_opt.top()) || (opt[i] == '\0' && !s_opt.empty())){
                ch = s_opt.top();
                s_opt.pop();
                switch(ch){
                    case '+':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num1 + num2);
                        break;
                    case '-':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num2 - num1);
                        break;
                    case '*':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num1 * num2);
                        break;
                    case '/':
                        num1 = s_num.top();
                        s_num.pop();
                        num2 = s_num.top();
                        s_num.pop();
                        s_num.push(num2 / num1);
                        break;
                }
            }
        }
    }
    result = s_num.top();
    cout << result;
}






/*给定一个仅包含数字0-9的字符串num和一个目标值整数target，在num的数字之间添加二元运算符（不是一元）+、- 或*，按字典序输出所有能够得到目标值的表达式。
输入：
两行，分别为num与target。
输出：
大于等于0行，每行一个目标表达式
输入样例：
123
6
输出样例：
1*2*3
1+2+3
*/
#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
#include<cstring>
using namespace std;
vector<string> addop(string num, int target){
    vector<pair<int,string>> cur,temp;
    cur.emplace_back(atoi(num.substr(0,1).c_str()),num.substr(0,1));
    for(int i=1;i<num.length();i++){
        temp.clear();
        for(pair<int,string> it:cur){
            string curstr=it.second;
            int curnum=it.first;
            int pos=curstr.length()-1;
            temp.emplace_back(curnum+(num[i]-'0'),curstr+"+"+num[i]);
            temp.emplace_back(curnum-(num[i]-'0'),curstr+"-"+num[i]);
            while(pos>=0&&curstr[pos]>='0'&&curstr[pos]<='9') pos--;
            if(pos<0){
                if(curstr[0]!='0'){
                    stringstream str;
                    str<<num.substr(0,i+1);
                    long long val;
                    str>>val;
                    if(val<=INT_MAX&&val>=INT_MIN)temp.emplace_back(val,num.substr(0,i+1));
                }
                temp.emplace_back(curnum*(num[i]-'0'),curstr+"*"+num[i]);
                
            }
            else{
                int lastval=atoi(curstr.substr(pos+1,curstr.length()-pos-1).c_str());
                if(curstr[pos]=='+'){
                    if(lastval!=0){
                        temp.emplace_back(curnum-lastval+(lastval*10+num[i]-'0'),curstr+num[i]);
                    }
                    temp.emplace_back(curnum-lastval+lastval*(num[i]-'0'),curstr+"*"+num[i]);
                }
                else if(curstr[pos]=='-'){
                    if(lastval!=0){
                        temp.emplace_back(curnum+lastval-(lastval*10+num[i]-'0'),curstr+num[i]);
                    }
                    temp.emplace_back(curnum+lastval-lastval*(num[i]-'0'),curstr+"*"+num[i]);
                }
                else{
                    long long timesNum=lastval;
                    while(pos>=0&&curstr[pos]=='*'){
                        int t=pos-1;
                        int val=0;
                        while(t>=0&&curstr[t]>='0'&&curstr[t]<='9'){
                            t--;
                        }
                        val=atoi(curstr.substr(t+1,pos-1-t).c_str());
                        pos=t;
                        timesNum*=val;
                    }
                    if(pos<0||(pos>=0&&curstr[pos]=='+')){
                        if(lastval!=0){
                            long long cur=curnum-timesNum+timesNum/lastval*((long long)lastval*10+num[i]-'0');
                            if(cur<=INT_MAX&&cur>=INT_MIN)
                                temp.emplace_back((int)cur,curstr+num[i]);
                            
                        }
                        temp.emplace_back(curnum-timesNum+timesNum*(num[i]-'0'),curstr+"*"+num[i]);
                            
                    }
                    else if(curstr[pos]=='-'){
                        if(lastval!=0){
                            long long cur=curnum+timesNum-timesNum/lastval*((long long)lastval*10+num[i]-'0');
                            if(cur<=INT_MAX&&cur>=INT_MIN)
                                temp.emplace_back((int)cur,curstr+num[i]);
                            
                        }
                        temp.emplace_back(curnum+timesNum-timesNum*(num[i]-'0'),curstr+"*"+num[i]);
                    }
                }
            }
        }
        cur=temp;
    }
    vector<string> ans;
    for(pair<int,string> it:cur){
        if(it.first==target)ans.push_back(it.second); 
    }
    return ans;
}

int main(){
    string s;
    int target;
    cin>>s;
    cin>>target;
    vector<string> res=addop(s,target); 
    sort(res.begin(),res.end());
    for(auto c:res){
        cout<<c<<endl;
    }
}

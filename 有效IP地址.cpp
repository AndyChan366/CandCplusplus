/*给定一个字符串s，按字典序输出从s可能的所有合法ip地址。
合法的ip地址有四个整数（每个整数位于0到255之间组成，且不含有前导0），整数用.分隔。
输入:
一个字符串
输出:
共x行，每行一个合法的ip地址，按字典序排列，x>0
示例:
"25525511133"
["255.255.11.133", "255.255.111.33"]
"0000"
["0.0.0.0"]
*/
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


bool check(string s){
    if(stoi(s)<=255)
        if(s[0]!='0'||(s[0]=='0'&&s.size()==1))return true;
        return false;
}


vector<string> ipaddress(string s){
    vector<string> res;
    for(int a=1;a<4;a++)
        for(int b=1;b<4;b++)
            for(int c=1;c<4;c++)
                for(int d=1;d<4;d++){
                    if(a+b+c+d==s.size()){
                        string s1=s.substr(0,a);     
                        string s2=s.substr(a,b);
                        string s3=s.substr(a+b,c);
                        string s4=s.substr(a+b+c);
                        if(check(s1)&&check(s2)&&check(s3)&&check(s4)){
                            string ip=s1+'.'+s2+'.'+s3+'.'+s4;
                            res.push_back(ip);
                        }
                    }
                }
    return res;
}


int main(){
    string s;
    while(cin>>s){
        vector<string> v=ipaddress(s);
        cout<<"[";
        for(int i=0;i<v.size();i++){
            cout<<v[i];
            if(i!=v.size()-1)cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
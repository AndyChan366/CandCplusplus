#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<ctype.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string res="$#";
    for(int i=0;i<s.size();++i)
    {
        res+=s[i];
        res+="#";
    }
    vector<int> P(res.size(),0);
    int mi=0,right=0;   
    int maxLen=0,maxPoint=0;    
    for(int i=1;i<res.size();++i)
    {
        P[i]=right>i ?min(P[2*mi-i],right-i):1;     
        while(res[i+P[i]]==res[i-P[i]])
            ++P[i];
        if(right<i+P[i])    
        {
            right=i+P[i];
            mi=i;
        }

        if(maxLen<P[i])     
        {
            maxLen=P[i];
            maxPoint=i;
        }
    }
    cout<<s.substr((maxPoint-maxLen)/2,maxLen-1);
}

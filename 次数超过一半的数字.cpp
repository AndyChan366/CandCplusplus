/*问题描述：
正整数数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组[1,2,3,2,2,2,5,4,2]。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
该问题时间复杂度可为O(n)，空间复杂度可为O(1)。
输入：
第一行为测试样例个数n，下面n行分别为输入的正整数数组。
输出：
次数超过一半的数字或者0。
输入样例：
2
1 2 3 2 2 2 5 4 2
3 3 3 3 4 6 7
输出样例：
2
3
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
int main(){
    int t,a,num;
    vector<int> arr;
    cin>>t;
    while(t--){
        while(cin>>num){
            arr.push_back(num);
            if(getchar()=='\n')break;
        }
        // for(auto ch:arr){
        //     cout<<ch<<" ";
        // }
        sort(arr.begin(),arr.end());
        int num=count(arr.begin(),arr.end(),arr[arr.size()/2-1]);
        cout<<arr.size()<<" "<<arr[arr.size()/2-1]<<endl;
        num>=(arr.size()+1)/2?cout<<arr[arr.size()/2-1]<<endl:cout<<0<<endl;//上面两行需考虑size的奇偶性，以及不同奇偶性时下标位置
        arr.clear();
    }  
}
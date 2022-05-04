/*arr是一个可能包含重复元素的整数数组，我们将这个数组按原序分割成几个“块”。
将这些块分别进行排序，再连接起来，使得连接的结果和按升序排序后的原数组相同。
求最多能将数组分成多少块。
输入：
第一行输入N，表示arr长度，第二行输入N个数。
输出：
一个数，最多能完成排序的块数目。
输入样例
# input 1
5
5 4 3 2 1
# input 2
9
4 5 3 2 6 7 8 9 6
输出样例
# output 1
1
# [5,4,3,2,1]
# output 2
3
# [2,3,4,5], [6], [6,7,8,9]
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int block(vector<int>& v){
    stack<int> st;
    for(auto &it:v){
        if(st.empty()||it>=st.top()){
            st.push(it);
        }
        else{
            auto top = st.top();
            st.pop();
            while(!st.empty()&&it<st.top()){
                st.pop();
            }
            st.push(top);
        }
    }
    return st.size();
}
int main(){
    int n,a;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    cout<<block(v)<<endl;
}


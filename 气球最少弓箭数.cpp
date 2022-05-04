/*在二维空间中有许多圆形的气球。对于每个气球，提供水平方向气球直径的开始和结束坐标。开始坐标总是小于结束坐标。
一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为x_start, x_end；
且满足x_start ≤ x ≤ x_end，则该气球会被引爆。可以射出的弓箭的数量没有限制。
弓箭一旦被射出之后，可以无限地前进。找到使得所有气球全部被引爆，所需的弓箭的最小数量。
输入：
第一行输入N，表示有N个气球。
接下来N行，每行有两个数，为该行气球的x_start和x_end。
输出：
一个数，引爆所有气球所必须射出的最小弓箭数。
输入样例：
# input 1
4
10 16
2 8
1 6
7 12
# input 2
5
1 2
3 4
5 6
7 8
9 10
输出样例：
# output 1
2
# output 2
5*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static bool cmp(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}
int minnumber(vector<vector<int>>& points){
    int n=points.size(),minnum=1;
    if(n==0) return 0;
    sort(points.begin(),points.end(),cmp);
    int end=points[0][1]; 
    for(int i=1;i<n;++i){
        if(points[i][0]>end){
            minnum+=1;
            end=points[i][1];
        }   
    }
    return minnum;
}
int main(){
    vector<vector<int>> v;
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
	    vector<int> temp;
        cin>>a>>b;
	    temp.push_back(a);
        temp.push_back(b);
	    v.push_back(temp);
	 }
    cout<<minnumber(v)<<endl;
}


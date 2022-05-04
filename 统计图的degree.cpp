/*给定无向图邻接表，求该图的度数序列。
注：无向图的度数序列是其顶点度数的非递增序列。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ALGraph{
    vector<vector<int> > adj; //adjacency list of the graph
    int order;// number of vertices
    int size;//number of edges
    //A simple initialization.
    ALGraph(int n=0, int m=0):order(n), size(m){
        adj.resize(n);
   }
} ;
//假定n个结点分别用0,1,..., n-1表示。例如，3个结点的无向图的结点分别是0,1和2.
vector<int> degreeSequence(const ALGraph &g){
    vector<int> res;
    vector<vector<int> > d=g.adj;
    // for(int i=0;i<d.size();i++){
    //     for(int j=0;j<d[i].size();j++){
    //         cout<<d[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int n=g.order;
    for(int i=0;i<n;i++){
        res.push_back(d[i].size());
    }
    sort(res.begin(),res.end(),greater<int>());
    // for(auto ch:res){
    //     cout<<ch<<" ";
    // }
    return res;
}
int main(){
    //测试用例：
    int n=4,m=3;
    vector<vector<int> > adv={{1},{0,2},{1,3},{2}};
    ALGraph g;
    g.adj=adv;
    g.order=n;
    g.size=m;
    vector<int> a=degreeSequence(g);
    for(auto ch:a){
        cout<<ch<<" ";
    }
}

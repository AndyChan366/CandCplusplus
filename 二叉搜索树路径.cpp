/*
定义二叉搜索树的root-to-leaf路径长度为：路径上所有结点key值之和。
现在给定一个由n个元素组成的序列和路径长度m，请先根据序列构造出来一棵二叉搜索树，然后找出所有root-to-leaf路径等于m的路径。
输入:
有多个测试案例，以EOF结束。
每个测试案例有两行：
第一行由n和m组成，n和m之间以空格隔开，n (0<=n<=1000)代表序列中元素个数，m (INT_MIN<=m<=INT_MAX)代表要找到的路径的长度。
第二行是输入的序列，由n个整数组成，以空格隔开。
输出:
对于每个测试案例，每一行按序输出一条路径；如果没有符合条件的路径就输出NULL，单独占一行，路径的顺序类似于字符串的的比较。
样例输入：
7 28
13 15 7 3 8 -2 5
7 -10
13 15 7 3 8 -2 5
样例输出：
13->7->3->5
13->7->8
13->15
NULL
*/
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution{
    public:
    TreeNode* TreeConstruction(vector<int> v){
        if(v.size()==0)return NULL;
        TreeNode* root=new TreeNode(v.front());
        if(v.size()==1)return root;
        else{
            TreeNode* tmp=root;
            for(int i=1;i<v.size();i++){
                tmp=root;
                while(1){
                    if(v[i]<tmp->val){
                        if(tmp->left==NULL){
                            TreeNode* newnode=new TreeNode(v[i]);
                            tmp->left=newnode;
                            break;
                        }
                        else if(tmp->left!=NULL){
                            tmp=tmp->left;
                        }
                    }
                    else if(v[i]>=tmp->val){
                        if(tmp->right==NULL){
                            TreeNode* newnode=new TreeNode(v[i]);
                            tmp->right=newnode;
                            break;
                        }
                        else if(tmp->right!=NULL){
                            tmp=tmp->right;
                        }
                    }
                }
            }
        }
        return root;
    }
    vector<vector<int>> FindPath(TreeNode* root,int sum){
        vector<vector<int>> res;
        if(!root)return res;
        vector<int> temp;
        dfs(root,sum,res,temp);
        return res;
    }
    void dfs(TreeNode* root,int sum,vector<vector<int>> &res,vector<int> temp){
        temp.push_back(root->val);
        if(!root->left&&!root->right&&0==sum-root->val)res.push_back(temp);
        if(root->left)dfs(root->left,sum-root->val,res,temp);
        if(root->right)dfs(root->right,sum-root->val,res,temp);
    }
};
int main(){
    int N,len,num;
    while(cin>>N>>len){
        vector<int> v;
        for(int i=0;i<N;i++){
            cin>>num;
            v.push_back(num);
        }
        Solution s;
        TreeNode* searchTree=s.TreeConstruction(v);
        vector<vector<int>> ans;
        ans=s.FindPath(searchTree,len);
        // cout<<ans.size()<<endl;
        if(ans.size()==0)cout<<"NULL"<<endl;
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[i].size();j++){
                    if(j!=ans[i].size()-1)cout<<ans[i][j]<<"->";
                    else cout<<ans[i][j]<<endl;
                }
            }
        }
    }
}


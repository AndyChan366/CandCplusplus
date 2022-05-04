/*
定义一棵二叉树的宽度为各层结点数的最大值。请你求一棵给定二叉查找树的宽度。
输入：
第一行是测试样例数。对应每个测试样例，第一行是结点数，接下来是所有结点关键字的排列。假定所有关键字不相同。
二叉查找树通过关键字输入的顺序插入构建。
输出：
对于每个测试样例，打印其宽度，每个输出占一行。
输入样例：
2
3
10 5 15
7
10 5 1 8 15 30 20
输出样例：
2
3
*/
#include<iostream>
#include<vector>
#include<queue>
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
    int WidthOfTheTree(TreeNode* root){  
    if(root==NULL) return 0;  
    queue<TreeNode*> layerorder;  
    layerorder.push(root);  
    int width=1;  
    int curwidth=1;  
    int nextwidth=0;  
    while(!layerorder.empty()){  
        while(curwidth!=0){  
            TreeNode* tmp=layerorder.front();  
            layerorder.pop();  
            curwidth--;  
            if(tmp->left!=NULL){  
                layerorder.push(tmp->left);  
                nextwidth++;  
            }  
            if(tmp->right!=NULL){  
                layerorder.push(tmp->right);  
                nextwidth++;  
            }  
        }  
        if(nextwidth>width)width=nextwidth;  
        curwidth=nextwidth;  
        nextwidth=0;  
    }  
    return width;  
}  
};
int main(){
    int N,len,num;
    cin>>len;
    for(int i=0;i<len;i++){
        cin>>N;
        vector<int> v;
        for(int i=0;i<N;i++){
            cin>>num;
            v.push_back(num);
        }
        Solution s;
        TreeNode* searchTree=s.TreeConstruction(v);
        int maxwidth=s.WidthOfTheTree(searchTree);
        cout<<maxwidth<<endl;
    }
}

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
    bool zhengze(TreeNode* root){
        if(!root)return false;
        else if(root->left!=NULL&&root->right!=NULL)return (zhengze(root->left)&&zhengze(root->right));
        else if(root->left==NULL&&root->right==NULL) return true;
        else return false;
    }
};
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        Solution s;
        TreeNode* searchTree=s.TreeConstruction(v);
        if(s.zhengze(searchTree))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        v.clear();
    }
}
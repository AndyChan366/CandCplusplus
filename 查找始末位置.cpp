#include<iostream>
#include<vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target){
    vector<int> res;
    int n=nums.size();
    if(n==0) return {-1,-1};
    for(int i=0;i<n;i++){
        if(nums[i]==target){
            res.push_back(i);
            int j=i+1;
            while(j<n&&nums[j]==target)j++;
            res.push_back(j-1);
            return res;
        }
    }
    return {-1,-1};
}
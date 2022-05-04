/*输入一个整型数组S，以及一个目标整数target，从数组中找出三个数，使得他们的和最接近target，假设对于每一组输入，均对应唯一一个结果。
输入：
输入为三行，第一行为数组大小N；第二行为int数组；第三行为目标整数target。
输出：
一行，输出最接近target的三个数的和（假设输出的结果唯一）。
输入样例：
4
-1 1 2 4
1
输出样例：
2
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int sumnear(vector<int>nums, int target){
    int min = 1e9;
    int sum = 0;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size() - 2; i++){
        int left = i + 1, right = nums.size() - 1;
        if(i > 0 && nums[i] == nums[i - 1]){
            continue;
        }
        while(left < right){
            sum = nums[i] + nums[left] + nums[right];
            if(abs(sum - target) < abs(min - target)){
                min = sum;
            }
            if(sum == target){
                return sum;
            }
            else if(sum < target){
                int temp = left + 1;
                while(temp < right && nums[temp] == nums[left]){
                    temp++;
                }
                left = temp;
            }
            else if(sum > target){
                int temp = right - 1;
                while(temp > left && nums[temp] == nums[right]){
                    temp--;
                }
                right = temp;
            }
        }
    }
    return min;
}

int main(){
    int n,target,a;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    cin>>target;
    cout<<sumnear(v,target)<<endl;
}

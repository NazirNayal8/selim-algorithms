#include <iostream>

using namespace std;
int longest (int x, vector<int>& nums,int y){
       if (x==nums.size()){
        return 0;
       }
    if (nums[x]<=y){
        return longest(x+1, nums, y);
    }
    if (nums[x]>y){
        int take = 1 + longest(x+1,nums,nums[x]);
        int not_take = longest(x+1, nums, y);
        
        return max(take, not_take);
    }

 
}
    
int lengthOfLIS(vector<int>& nums) {
    return longest(0,nums,-1);   
}

int main(){
    
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(7);
    // nums.push_back(101);
    // nums.push_back(18);
    cout << lengthOfLIS(nums) << endl;
    return 0;

}
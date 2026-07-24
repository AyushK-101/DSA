1class Solution {
2public:
3    int rob(vector<int>& nums) {
4        if(nums.size()==1) return nums[0];
5        if(nums.size()==2) return max(nums[0],nums[1]);
6
7        int dpzero=nums[0];
8        int dpone=max(nums[0],nums[1]);
9
10        for(int i=2;i<nums.size();i++){
11            int take=nums[i]+dpzero;
12            int skip=dpone;
13
14            dpzero=dpone;
15            dpone=max(take,skip);
16        }
17        return dpone;
18    }
19};
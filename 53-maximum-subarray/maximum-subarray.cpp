class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int curr_sum=0;
        for(int i=0;i<nums.size();i++){
            curr_sum= curr_sum+nums[i];
            maxsum= max(maxsum,curr_sum);
            if (curr_sum<0){
                curr_sum=0;
            }
        }
        return maxsum;
    }
};
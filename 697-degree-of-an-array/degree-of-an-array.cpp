class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        unordered_map<int, int> freq;
        unordered_map<int, int> first;
        unordered_map<int, int> last;

        int degree = 0;

        for (int i = 0; i < nums.size(); i++) {

            int num = nums[i];

            if (first.find(num) == first.end()) {
                first[num] = i;
            }

            last[num] = i;

            freq[num]++;

            degree = max(degree, freq[num]);
        }

        int ans = nums.size();

        for (auto it : freq) {

            int num = it.first;

            if (it.second == degree) {

                ans = min(ans,
                          last[num] - first[num] + 1);
            }
        }

        return ans;
    }
};
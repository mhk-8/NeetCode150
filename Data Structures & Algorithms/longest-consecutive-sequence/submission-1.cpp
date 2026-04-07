class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int longest =0;
        for(auto x: nums){
            if(!s.contains(x-1)){
                int length =0;
                while(s.contains(x+length)){
                    length++;
                }
                longest = max(length,longest);
            }
        }
        return longest;
    }
};

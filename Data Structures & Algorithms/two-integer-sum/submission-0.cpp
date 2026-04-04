class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int> m;
       for(int i; i< nums.size(); i++){
        int a= nums[i];
        int b= target - a;
        if(m.find(b) != m.end()){
            return {m[b],i};
        }
        m[a]= i;
       } 
       return {-1,-1};
    }
};

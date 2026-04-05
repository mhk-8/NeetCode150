class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       vector<int> result(k);
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(auto num : nums){
            mp[num]++;
        }
        for(auto pair: mp){
            pq.push(make_pair(pair.second,pair.first));
        }
        for(int i=0;i<k;i++){
            result[i]= pq.top().second;
            pq.pop();
        }
        return result; 
    }
};

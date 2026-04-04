class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;

        for(auto s: strs){
            string temp = s;
            sort(s.begin(),s.end());
            mp[s].push_back(temp);
        }

        for(auto x:mp){
            result.push_back(x.second);
        }
        return result;
    }
};

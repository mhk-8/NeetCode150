class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        
        vector<int> s1_count(26, 0);
        vector<int> window_count(26, 0);
        
        for (int i = 0; i < s1.length(); i++) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }
        
        for (int i = s1.length(); i < s2.length(); i++) {
            if (s1_count == window_count) {
                return true;
            }
            window_count[s2[i] - 'a']++;
            
            window_count[s2[i - s1.length()] - 'a']--;
        }
        
        return s1_count == window_count;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.length() < t.length()) return "";

        unordered_map<char, int> t_count;
        for (char c : t) {
            t_count[c]++;
        }
        int have = 0;
        int need = t_count.size();

        unordered_map<char, int> window_count;
        int left = 0;
        
        int min_len = -1;
        int min_start = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            window_count[c]++;

            if (t_count.count(c) && window_count[c] == t_count[c]) {
                have++;
            }
            while (have == need) {
                int current_window_length = right - left + 1;
                if (min_len == -1 || current_window_length < min_len) {
                    min_len = current_window_length;
                    min_start = left;
                }

                char left_char = s[left];
                window_count[left_char]--;
                
                if (t_count.count(left_char) && window_count[left_char] < t_count[left_char]) {
                    have--;
                }
                
                left++; 
            }
        }

        return min_len == -1 ? "" : s.substr(min_start, min_len);
    }
};

class TimeMap {
    unordered_map<string,vector<pair<int,string>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) {
            return "";
        }
        
        const auto& values = m[key];
        int left = 0;
        int right = values.size() - 1;
        std::string result = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (values[mid].first <= timestamp) {
                result = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};

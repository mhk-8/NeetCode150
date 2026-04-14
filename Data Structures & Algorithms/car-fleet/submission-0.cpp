class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        std::vector<std::pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        std::sort(cars.begin(), cars.end(), [](pair<int, double>& a,pair<int, double>& b) {
            return a.first > b.first;
        });
        
        int fleets = 0;
        double slowest_time = 0.0;
        
        for (int i = 0; i < n; i++) {
            if (cars[i].second > slowest_time) {
                fleets++;
                slowest_time = cars[i].second;
            }
        }
        
        return fleets;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        std::stack<int> st;
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
            int current_height = (i == n) ? 0 : heights[i];
            while (!st.empty() && current_height < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }
                max_area = std::max(max_area, height * width);
            }
            st.push(i);
        }
        
        return max_area;
    }
};

class Solution {
public:
   int MaxAreaHistogram(vector<int> &nums) {
    int len = nums.size();
    vector<int> left(len, -1), right(len, len);
    stack<pair<int, int>> st; // st<{idx, val}>
    for (int idx = 0; idx < len; ++idx) {
        if (!st.empty() && st.top().second < nums[idx])
            left[idx] = st.top().first;
        else if (!st.empty() && st.top().second >= nums[idx]) {
            while (!st.empty() && st.top().second >= nums[idx])
                st.pop();
            if (!st.empty())
                left[idx] = st.top().first;
        }
        st.push({idx, nums[idx]});
    }

    st = stack<pair<int, int>>();

    for (int idx = len - 1; idx >= 0; --idx) {
        if (!st.empty() && st.top().second < nums[idx])
            right[idx] = st.top().first;
        else if (!st.empty() && st.top().second >= nums[idx]) {
            while (!st.empty() && st.top().second >= nums[idx])
                st.pop();
            if (!st.empty())
                right[idx] = st.top().first;
        }
        st.push({idx, nums[idx]});
    }
    int max_area = 0;
    for (int idx = 0; idx < len; ++idx) {
        int area = nums[idx] * (right[idx] - left[idx] - 1);
        max_area = max(area, max_area);
    }
    return max_area;
}

int maximalRectangle(vector<vector<char>> &matrix) {
    int rows = matrix.size(), cols = matrix[0].size(), max_area = 0;
    vector<int> nums(cols, 0);

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int height = matrix[row][col] - 48;
            if (!height)
                nums[col] = 0;
            else
                nums[col] += height;
        }
        int area = MaxAreaHistogram(nums);
        max_area = max(max_area, area);
    }
    return max_area;
}
};
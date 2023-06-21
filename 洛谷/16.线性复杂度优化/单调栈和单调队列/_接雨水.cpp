// https://leetcode.cn/problems/trapping-rain-water/description/
// 单调递减栈
// 题解：https://leetcode.cn/problems/trapping-rain-water/solutions/692342/jie-yu-shui-by-leetcode-solution-tuvc/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> s;
        int n = height.size();
        for(int i = 0; i < n; i++) {
            while(!s.empty() && height[s.top()] < height[i]) { // 当前遍历到的高度比栈顶的高度大，说明可以接雨水
                int top = s.top();
                s.pop();
                if(s.empty()) {
                    break;
                } // 如果栈中只有一个元素直接break
                int left = s.top();
                int cur_weith = i - left - 1;
                int cur_height = min(height[i], height[left]) - height[top];
                ans += cur_weith * cur_height;
            }
            s.push(i);
        }
        return ans;
    }
};
int main() {

    return 0;
}
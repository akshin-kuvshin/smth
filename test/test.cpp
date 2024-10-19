#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<pair<int, int>> twoSum(vector<int>& nums, int x, int except) {
        vector<pair<int, int>> answer;
        int l = 0,
            r = (int)nums.size() - 1;
        while (l < r) {
            if (l == except) {
                ++l;
                continue;
            }
            if (r == except) {
                --r;
                continue;
            }
            if (nums[l] + nums[r] == x) {
                answer.push_back(make_pair(nums[l], nums[r]));
                ++l; --r;
                continue;
            }
            if (nums[l] + nums[r] < x)
                ++l;
            else
                --r;
        }
        cout << "were finding for x=" << x << ", get:\n";
        for (auto p : answer)
            cout << '{' << p.first << ", " << p.second << "}\n";
        return answer;
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> triples;

        sort(nums.begin(), nums.end());
        for (int num : nums)
            cout << num << ' ';
        cout << '\n';
        int N = (int)nums.size();
        for (int i = 0; i < N; ++i) {
            vector<pair<int, int>> V = twoSum(nums, -nums[i], i);
            for (pair<int, int> p : V) {
                vector<int> T = {nums[i], p.first, p.second};
                sort(T.begin(), T.end());
                triples.insert(T);
            }
        }

        vector<vector<int>> answer;
        for (const vector<int> &T : triples)
            answer.push_back(T);
        return answer;
    }
};

Solution solution;

int main() {
    vector<int> nums = {0, -3, 2, -4, -1, -3, -2, 1, -1, 1, 3};
    auto ans = solution.threeSum(nums);
    for (vector<int> triple : ans)
        cout << triple[0] << ' ' << triple[1] << ' ' << triple[2] << '\n';
    return 0;
}

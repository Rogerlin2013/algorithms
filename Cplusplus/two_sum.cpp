#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            if (map.count(target - nums[i]) > 0) {
                ans.push_back(map[target - nums[i]]);
                ans.push_back(i);
                return ans;
            } else {
                map[nums[i]] = i;
            }
        }
        return ans;
    }
};
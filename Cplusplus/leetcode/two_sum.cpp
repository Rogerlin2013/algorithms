#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 暴力法
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

// 一遍哈希
vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result;
    map<int, int> hash_pos;

    for(int i = 0; i < nums.size(); i++) {
        int value = nums[i];
        map<int, int>::iterator it = hash_pos.find(target - value);
        if (hash_pos.end() != it){
            result.push_back(it->second);
            result.push_back(i);
            return result;
        }
        hash_pos[value] = i;
    }
    
    return result;
}
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;

    if (nums.size() < 3)
    {
        return result;
    }

    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            int target = -(nums[i] + nums[j]);
            int index = binary_search(nums, nums.size(), target);
            if (index != -1 && index > j)
            {
                vector<int> haha = {nums[i], nums[j], nums[index]};
                result.push_back(haha);
            }
            
        }
        
    }
    return result;
}

int binary_search(vector<int>& array, int n, int value) {

    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int middle = low + ((high - low) >> 1);

        if (array[middle] > value) {
            high = middle - 1;
        }else if (array[middle] < value) {
            low = middle + 1;
        }else {
            if (middle == n - 1 || array[middle + 1] != value) {
                return middle;
            }else {
                low = middle + 1;
            }
        }
    }

    return -1;
}

vector<vector<int>> threeSum2(vector<int>& nums) {
    vector<vector<int>> result;

    if (nums.size() < 3)
    {
        return result;
    }

    std::sort(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            return result;
        }
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int L = i + 1;
        int R = nums.size() - 1;

        while (L < R)
        {
            if (nums[i] + nums[L] + nums[R] == 0)
            {
                vector<int> haha = {nums[i], nums[L], nums[R]};
                result.push_back(haha);
                while (L < R && nums[L] == nums[L -1])
                {
                    L++;
                }
                
                while (L < R && nums[R] == nums[R + 1]){
                    R--;
                }
                L++;
                R--;
            }else if (nums[i] + nums[L] + nums[R] > 0)
            {
                R--;
            }else {
                L++;
            }
        }
    }
    return result;
}
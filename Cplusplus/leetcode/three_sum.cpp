#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> result;

    if (nums.size() < 3)
    {
        return vector<vector<int>> (result.begin(), result.end());
    }

    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            int target = -(nums[i] + nums[j]);
            int index = binary_search(nums, nums.size(), target);
            if (index != -1 && index > j)
            {
                vector<int> haha = {nums[i], nums[j], nums[index]};
                result.insert(haha);
            }
        }
    }
    return vector<vector<int>> (result.begin(), result.end());
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
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);

    for (size_t i = 1; i < nums.size(); i++)
    {
        /* code */
        int len = 1;
        int value = nums[i];

        for (size_t j = 0; j < i; j++)
        {
            /* code */
            if (nums[j] < value)
            {
                /* code */
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
    }
    int result = 0;

    for (int &i:dp)
    {
        if (i > result)
        {
            result = i;
        }
        
    }

    return result;
}

int main() {
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};

    cout << lengthOfLIS(nums) << endl;
}
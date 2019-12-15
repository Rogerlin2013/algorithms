#include "move_zero.hpp"

void moveZeroes(vector<int>& nums) {
    int zeroCount = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
        int value = nums[i];
        if (value == 0) {
            zeroCount++;
        }else {
            if (zeroCount > 0)
            {
                nums[i - zeroCount] = value;
            }
        }
    }
    for (size_t i = nums.size() - zeroCount; i < nums.size(); i++)
    {
        nums[i] = 0;
    }
}
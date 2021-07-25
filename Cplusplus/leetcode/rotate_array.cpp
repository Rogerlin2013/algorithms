#include <vector>

using namespace std;

// 暴力法
void rotate(vector<int>& nums, int k) {
    for(int i = 0; i < k; i++) {
        int count = nums.size();
        int lastValue = nums[count - 1];

        for (size_t j = count - 1; j > 0; j--)
        {
            nums[j] = nums[j - 1];
        }
        nums[0] = lastValue;
    }
}

// 环状替换
void rotate(vector<int>& nums, int k) {
    if (nums.size() < 2 || k < 1) {
        return;
    }

    int count = nums.size();
    int actualK = k % count;

    int curCount = 0;

    for (int start = 0; curCount < count; start++) {

        int current = start;
        int temp = nums[start];
        do {

        int next = (current + actualK) % count;
        int nextValue = nums[next];
        nums[next] = temp;
        temp = nextValue;

        current = next;
        curCount++;
        }while (current != start);
    }
}

// 反转法

void rotate(vector<int>& nums, int k) {
    if (nums.size() < 2 || k < 1) {
        return;
    }

    reverse(nums, 0, nums.size() - 1);
    k = k % nums.size();
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
}

void reverse(vector<int>& nums, int start, int end) {
    int swapCount = (end - start + 1) / 2;

    for (size_t i = 0; i < swapCount; i++)
    {
        int temp = nums[end - i];
        nums[end - i] = nums[start + i];
        nums[start + i] = temp;
    }
}
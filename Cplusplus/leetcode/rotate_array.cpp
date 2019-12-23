#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    if (nums.size() < 2 || k < 1) {
        return;
    }

    int count = nums.size();
    int curCount = 0;

    int actualK = k % count;

    for (int i = 0; curCount < count; i++) {
        int destIndex = i;
        int sourceIndex = -1;
        int firstNum = nums[destIndex];

        do {
            sourceIndex = destIndex - actualK;
            if (sourceIndex < 0) {
                sourceIndex += count;
            }

            if (destIndex == i) {
                nums[destIndex] = firstNum;
                curCount++;
                break;
            }else {
                curCount++;
                nums[destIndex] = nums[sourceIndex];
            }
            destIndex = sourceIndex;
        }while (true);
    }
}
// ok
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

#include <vector>
#include <iterator>

using namespace std;

// 双指针从后往前
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int destIndex = m + n - 1;
    int source1 = m - 1;
    int source2 = n - 1;

    while(source1 >= 0 && source2 >= 0) {
        if (nums1[source1] > nums2[source2]) {
            nums1[destIndex--] = nums1[source1--];
        }else {
            nums1[destIndex--] = nums2[source2--];
        }
    }

    while(source2 >= 0) {
        nums1[destIndex--] = nums2[source2--];
    }
}

// 双指针从前到后，O(m) 空间复杂度
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> tempVector;

    std::copy(nums1.begin(), nums1.end(), std::back_inserter(tempVector));

    int source1 = 0;
    int source2 = 0;

    int destIndex = 0;

    while (source1 < m && source2 < n) {
        if (tempVector[source1] < nums2[source2]) {
            nums1[destIndex++] = tempVector[source1++];
        }else {
            nums1[destIndex++] = nums2[source2++];
        }
    }

    while (source1 < m) {
        nums1[destIndex++] = tempVector[source1++];
    }
    while (source2 < n) {
        nums1[destIndex++] = nums2[source2++];
    }
    
}
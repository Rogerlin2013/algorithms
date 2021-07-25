#include "max_area.hpp"
#include <algorithm>

int maxArea(vector<int>& height) {
    if (height.size() < 2) {
        return 0;
    }

    int left = 0, right = height.size() - 1;
    int maxArea = min(height[left], height[right]) * (right - left);

    while (left < right)
    {
        if (height[left] < height[right])
        {
            left++;
        }else {
            right--;
        }
        int area = min(height[left], height[right]) * (right - left);
        if (area > maxArea) {
            maxArea = area;
        }
    }
    
    return maxArea;
}

int maxArea2(vector<int>& height) {
    if (height.size() < 2) {
        return 0;
    }
    int maxArea = 0;

    for (size_t i = 0; i < height.size(); i++)
    {
        for (size_t j = i + 1; j < height.size(); j++)
        {
            int area = min(height[i], height[j]) * (j - i);

            if (area > maxArea) {
                maxArea = area;
            }
        }
    }
    return maxArea;
}
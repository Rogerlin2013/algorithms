#include <iostream>
#include "./leetcode/max_area.hpp"

int main() {
    
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    std::cout << "Max = " << maxArea2(height) << std::endl;

    return 0;
}
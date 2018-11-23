#include <iostream>

// 查找第一个等于 value 的值
int binary_search(int array[], int n, int value) {

    int low = 0;
    int hight = n - 1;

    while (low <= hight) {
        int middle = low + ((hight - low) >> 1);

        if (array[middle] >= value) {
            hight = middle - 1;
        }else {
            low = middle + 1;
        }
    }

    if (array[low] == value) {
        return low;
    }else {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    int array[] = {1, 3, 4, 5, 7, 7, 7, 7, 34, 45, 67, 67, 90, 90, 100};

    int index = binary_search(array, 15, 7);
    std::cout << index << std::endl;
    return 0;
}

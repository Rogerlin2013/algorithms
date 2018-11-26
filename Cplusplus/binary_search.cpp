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

    if (low < n && array[low] == value) {
        return low;
    }else {
        return -1;
    }
}

// 查找第一个等于 value 的值   常规写法
int binary_search_2(int array[], int n, int value) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int middle = low + ((high - low) >> 1);

        if (array[middle] > value) {
            high = middle - 1;
        }else if (array[middle] < value) {
            low = middle + 1;
        }else {
            if (middle == 0 || array[middle - 1] != value) {
                return middle;
            }else {
                high = middle - 1;
            }
        }
    }

    return -1;
}

// 查找第一个大于等于 value 的值
int binary_search_4(int array[], int n, int value) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int middle = low + ((high - low) >> 1);

        if (array[middle] < value) {
            low = middle + 1;
        }else {
            if (middle == 0 || array[middle - 1] < value) {
                return middle;
            }else {
                high = middle - 1;
            }
        }
    }

    return -1;
}

// 查找最后一个等于 value 的值   常规写法
int binary_search_3(int array[], int n, int value) {
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

// 查找最后一个小于等于 value 的值
int binary_search_5(int array[], int n, int value) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int middle = low + ((high - low) >> 1);

        if (array[middle] > value) {
            high = middle - 1;
        }else {
            if (middle == n - 1 || array[middle + 1] > value) {
                return middle;
            }else {
                low = middle + 1;
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int array[] = {1, 3, 4, 5, 7, 7, 7, 7, 34, 45, 67, 67, 90, 90, 100};

    int index = binary_search_5(array, 15, 104);
    std::cout << index << std::endl;
    return 0;
}

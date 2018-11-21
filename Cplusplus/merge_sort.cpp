#include <vector>
#include <iostream>

using namespace std;

// [left, right) 构成一个左闭右开区间
void merge_sort(vector<int> &array, int left, int right) {

    if (right - left < 2) {
        return;
    }

    int middle = left + (right - left) / 2;

    merge_sort(array, left, middle);
    merge_sort(array, middle, right);

    int left_index = left;
    int right_index = middle;

    std::vector<int> temp_array;
    while (left_index <= middle && right_index <= right) {
        // 某一分支已经合并完成
        if (left_index == middle) {
            while (right_index < right) {
                temp_array.push_back(array[right_index++]);
            }
            break;
        }

        if (right_index == right) {
            while (left_index < middle) {
                temp_array.push_back(array[left_index++]);
            }
            break;
        }

        int left_value = array[left_index];
        int right_value = array[right_index];

        if (left_value < right_value) {
            temp_array.push_back(left_value);
            left_index++;
        }else {
            temp_array.push_back(right_value);
            right_index++;
        }
    }

    for (int i = left; i < right; ++i) {
        array[i] = temp_array[i - left];
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> array;
    for (int i = 0; i < 30; ++i) {
        array.push_back(random() % 100);
    }

    std::cout << "Array before ..." << std::endl;
    std::vector<int>::iterator it;
    for (it = array.begin(); it < array.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';

    merge_sort(array, 0, array.size());

    std::cout << "Array after ..." << std::endl;
    for (it = array.begin(); it < array.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';
    return 0;
}
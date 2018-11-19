#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "max_heapify start..." << std::endl;
    return 0;
}

void max_heapify(std::vector<int> &array, int i) {

    int array_size = array.size();

    if (i < 1 || i > array_size) {
        return;
    }

    int largest_index = i;
    int left_index = heap_get_left(i);
    int right_index = heap_get_right(i);

    if (left_index <= array_size) {
        if (heap_get_value(array, left_index) > heap_get_value(array, largest_index)) {
            heap_swap(array, left_index, largest_index);
            largest_index = left_index;
        }
    }

    if (right_index <= array_size) {
        if (heap_get_value(array, right_index) > heap_get_value(array, largest_index)) {
            heap_swap(array, right_index, largest_index);
            largest_index = right_index;
        }
    }

    if (largest_index != i) {
        max_heapify(array, largest_index);
    }
}

int heap_get_value(std::vector<int> &array, int i) {
    return array[i - 1];
}

int heap_set_value(std::vector<int> &array, int i, int value) {
    array[i - 1] = value;
}

void heap_swap(std::vector<int> &array, int a, int b) {
    int a_value = heap_get_value(array, a);
    int b_value = heap_get_value(array, b);

    heap_set_value(array, a, b_value);
    heap_set_value(array, b, a_value);
}

int heap_get_parent(int i) {
    return i / 2;
}

int heap_get_left(int i) {
    return i * 2;
}

int heap_get_right(int i) {
    return i * 2 + 1;
}


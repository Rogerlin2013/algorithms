#include <vector>
#include <iostream>
#include <math.h>
#include <iterator>

int heap_get_value(std::vector<int> &array, int i) {
    return array[i - 1];
}

void heap_set_value(std::vector<int> &array, int i, int value) {
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

void max_heapify(std::vector<int> &array, int i, int heap_size) {
    if (i < 1 || i > heap_size) {
        return;
    }

    int largest_index = i;
    int left_index = heap_get_left(i);
    int right_index = heap_get_right(i);

    if (left_index <= heap_size) {
        if (heap_get_value(array, left_index) > heap_get_value(array, largest_index)) {
            heap_swap(array, left_index, largest_index);
            largest_index = left_index;
        }
    }

    if (right_index <= heap_size) {
        if (heap_get_value(array, right_index) > heap_get_value(array, largest_index)) {
            heap_swap(array, right_index, largest_index);
            largest_index = right_index;
        }
    }

    if (largest_index != i) {
        heap_swap(array, i, largest_index);
        max_heapify(array, largest_index, heap_size);
    }
}

void build_max_heap(std::vector<int> &array) {
    int count = array.size();

    int index = count / 2;

    while (index >= 1) {
        max_heapify(array, index, count);
        --index;
    }
}

void heap_sort(std::vector<int> &array) {
    build_max_heap(array);

    int heap_size = array.size();
    int i = array.size();

    while (i > 1) {
        heap_swap(array, 1, i);
        --heap_size;
        --i;
        max_heapify(array, 1, heap_size);
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> array;
    for (int i = 0; i < 30; ++i) {
        array.push_back(random() % 100);
    }

    std::cout << "Array before start..." << std::endl;
    std::vector<int>::iterator it;
    for (it = array.begin(); it < array.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';

    heap_sort(array);

    std::cout << "Array after start..." << std::endl;
    // std::vector<int>::iterator it;
    for (it = array.begin(); it < array.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';
    return 0;
}

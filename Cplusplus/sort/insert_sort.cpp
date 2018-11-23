#include <vector>
#include <iostream>

using namespace std;

void insert_sort(vector<int> &array) {
    int sorted_index = 0;

    for (int i = 0; i < array.size(); ++i) {
        
        int newValue = array[i];
        int search_index = sorted_index;
        int dest_pos = sorted_index;

        while (search_index >= 0 && array[search_index] >= newValue) {
            dest_pos = search_index--;
        }

        if (dest_pos < sorted_index) {
            // insert
            int j = i;
            while (j > dest_pos) {
                array[j] = array[j - 1];
                --j;
            }
            array[dest_pos] = newValue;
        }

        ++sorted_index;
    }
}

void insert_sort2(vector<int> &array) {
    for (int i = 1; i < array.size(); ++i) {
        int newValue = array[i];

        int j = i - 1;
        while (j >= 0 && array[j] > newValue) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = newValue;
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

    insert_sort2(array);

    std::cout << "Array after start..." << std::endl;
    for (it = array.begin(); it < array.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';
    return 0;
}

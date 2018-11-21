#include <vector>
#include <iostream>

using namespace std;

int partition(vector<int> &array, int p, int r) {
    int i = p - 1;
    int j = p;

    int x = array[r];

    while (j < r) {
        if (array[j] <= x) {
            ++i;

            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        ++j;
    }

    array[r] = array[i + 1];
    array[i + 1] = x;

    return i + 1;
}

void quick_sort(vector<int> &array, int p, int r) {
    if (p >= r) {
        return;
    }
    int q = partition(array, p, r);

    quick_sort(array, p, q - 1);
    quick_sort(array, q, r);
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

    quick_sort(array, 0, array.size() - 1);

    std::cout << "Array after start..." << std::endl;
    for (it = array.begin(); it < array.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';
    return 0;
}
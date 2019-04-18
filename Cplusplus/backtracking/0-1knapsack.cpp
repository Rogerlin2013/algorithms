#include <iostream>

int maxW = -1;

// 0-1 背包问题
// i 表示当前考察的物品
// cw 表示当前已经选择的物品重量和
// n  表示物品总数
// items 存储各个物品的重量
// w  背包的最大载重

void f(int i, int cw, int n, int* items, int w) {
    if (i == n || cw == w) {
        if (cw > maxW) {
            maxW = cw;
        }
        return;
    }
    
    f(i + 1, cw, n, items, w);

    if (cw + items[i] <= w) {
        f(i + 1, cw + items[i], n, items, w);
    }
}

int main(int argc, char const *argv[])
{
    int items[] = {1, 23, 44, 2, 65, 46, 98, 16, 27, 87};
    f(0, 0, 10, items, 405);

    std::cout << maxW << std::endl;
    return 0;
}


#include <iostream>

// 摆放结果。数组的下标表示行，值表示放在第几列
int *result = new int[8];

void print_result(void) {
    for(int row = 0; row < 8; row++) {
        for(int column = 0; column < 8; column++) {
            if (result[row] == column) {
                std::cout << "Q ";
            }else {
                std::cout << "* ";
            }
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool isOK(int row, int column) {

    int leftup = column - 1;
    int rightup = column + 1; 
    for(int i = row - 1; i >= 0; i--)
    {
        if (result[i] == column) {
            return false;
        }
        if (leftup >=0 && result[i] == leftup) {
            return false;
        }
        if (rightup < 8 && result[i] == rightup) {
            return false;
        }
        
        leftup--;
        rightup++;
    }
    return true;
}

void call_8_queens(int row) {
    if (row == 8) {
        print_result();
        return;
    }

    for (int column = 0; column < 8; ++column) {
        if (isOK(row, column)) {
            result[row] = column;
            call_8_queens(row + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    call_8_queens(0);
    return 0;
}

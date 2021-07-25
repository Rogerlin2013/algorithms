#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int N) {
    if (N == 1 || N == 2) {
        return 1;
    }

    return fibonacci(N - 1) + fibonacci(N - 2);
}

uint32_t f2_help(vector<uint32_t> &memo, int N) {

    if (memo[N] != 0) {
        return memo[N];
    }
    uint32_t value = f2_help(memo, N - 1) + f2_help(memo, N - 2);
    memo[N] = value;
    return value;
}

uint32_t fibonacci2(int N) {
    vector<uint32_t> memo(N + 1, 0);
    memo[2] = memo[1] = 1;

    return f2_help(memo, N);
}

uint32_t fibonacci3(int N) {
    vector<uint32_t> dp(N + 1, 0);

    dp[1] = dp[2] = 1;

    for (size_t i = 3; i < N + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}

uint32_t fibonacci4(int N) {
    uint32_t f1 = 1;
    uint32_t f2 = 1;

    for (size_t i = 3; i < N + 1; i++)
    {
        uint32_t value = f1 + f2;
        f1 = f2;
        f2 = value;
    }
    return f2;
}

int main() {
    cout << "Hello DP" << endl;
    cout << "F(20) = " << fibonacci4(40) << ";; " << fibonacci3(40) << endl;
}
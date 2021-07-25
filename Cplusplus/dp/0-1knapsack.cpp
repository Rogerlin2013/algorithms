#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(vector<int> &weights, vector<int> &values, int w) {
    int N = weights.size();
    vector<vector<int>> dp(N + 1, vector<int>(w + 1, 0));

    for (size_t i = 1; i < N + 1; ++i) {
        for (size_t j = 1; j < w + 1; ++j) {
            if (j < weights[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            }else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
        }
    }
    
    return dp[N][w];
}

int main() {
    vector<int> weights {2, 1, 3};
    vector<int> values {4, 2, 3};

    cout << "result: " << knapsack(weights, values, 4) << endl;
}
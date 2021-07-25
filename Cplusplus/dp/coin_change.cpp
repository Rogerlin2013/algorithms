#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// amount 金额对应的最少金币个数
int dp(vector<int> &coins, int amount, map<int, int> &dp_table) {

    if (amount < 0) {
        return -1;
    }
    if (amount == 0) {
        return 0;
    }

    auto it = dp_table.find(amount);
    if (it != dp_table.end())
    {
        return it->second;
    }

    int min = INT32_MAX;

    for (size_t i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];
        int count = dp(coins, amount - coin, dp_table) + 1;
        if (count > 0 && count < min) {
            min = count;
        }
    }

    if (min != INT32_MAX) {
        dp_table[amount] = min;
    }
    
    return min != INT32_MAX? min :-1;
}

int coin_change(vector<int> &coins, int amount) {
    map<int, int> dp_table;
    return dp(coins, amount, dp_table);
}

int coin_change2(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);

    // base case
    dp[0] = 0;
    for (size_t i = 1; i < amount + 1; i++)
    {
        /* code */
        for (size_t j = 0; j < coins.size(); j++)
        {
            /* code */
            if (i - coins[j] < 0)
            {
                continue;
            }
            
            dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
        }
    }
    return dp[amount] != (amount + 1) ? dp[amount] : -1;
}

int main() {
    vector<int> coins {1, 3, 4, 6, 10};

    cout << "coin change: " << coin_change(coins, 86) << "  2: " << coin_change2(coins, 86) << endl;
}

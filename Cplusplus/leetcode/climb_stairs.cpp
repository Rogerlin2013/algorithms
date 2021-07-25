#include <algorithm>

int climbStairs(int n) {
    if (2 == n)
    {
        return 2;
    }
    
    if (1 == n)
    {
        return 1;
    }
    
    return climbStairs(n - 1) + climbStairs(n - 2);
}

// 记忆化递归

int climbStairs2(int n) {
    int *memo = new  int[n+1];
    return climbStairs2_impl(n, memo);
}

 int climbStairs2_impl(int n,  int* memo) {
    if (2 == n)
    {
        return 2;
    }
    
    if (1 == n)
    {
        return 1;
    }

    if (memo[n] > 0)
    {
        return memo[n];
    }

    memo[n] = climbStairs2_impl(n - 1, memo) + climbStairs2_impl(n - 2, memo);
    return memo[n];
}


// 动态规划

int climbStairs3(int n) {
    int *dp = new int[std::max(3, n + 1)];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (size_t i = 3; i < n + 1; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    
    return dp[n];
}


// 斐波那契

int climbStairs4(int n) {
    
     if (n >=0 && n < 3) {
        return n;
    }
    
    int a = 1, b = 2;
    int Fn = 0;
    for (size_t i = 2; i < n; i++)
    {
        Fn = a + b;
        a = b;
        b = Fn;
    }
    
    return Fn;
}
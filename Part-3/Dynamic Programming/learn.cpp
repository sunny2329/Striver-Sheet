#include <bits/stdc++.h>
using namespace std;

//! fibonacci number

int f(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

//! memoization , the "top-down" dynamic programming usually the problem is solved in the direction of the main problem to the base case

//! tabulation, usually the problem is solved in the direction of solving the base cases to the main problem


//! tabulation method
int fib(int n, vector<int> &dp){
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
}

int main()
{
}
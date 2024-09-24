#include <bits/stdc++.h>
using namespace std;

//! Climb Stairs
int climbStairs(int n)
{
    int dp[46];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

//! Frog Jump

int frogJump(int ind, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne = frogJump(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    if (ind > 1)
        jumpTwo = frogJump(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);

    return dp[ind] = min(jumpOne, jumpTwo);
}

int solve(vector<int> &height, int ind, vector<int> &dp)
{
    int n = height.size();
    if (ind == n - 1)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int oneJump = solve(height, ind + 1, dp) + abs(height[ind] - height[ind + 1]);

    int twoJump = INT_MAX;
    if (ind + 2 < n)
    {
        twoJump = solve(height, ind + 2, dp) + abs(height[ind] - height[ind + 2]);
    }
    return dp[ind] = min(oneJump, twoJump);
}
int minimumEnergy(vector<int> &height, int n)
{
    // Code here
    vector<int> dp(n + 1, -1);
    return solve(height, 0, dp);
}

//! Minimal Cost

int solve(int ind, vector<int> &height, vector<int> &dp, int k)
{
    if (ind == 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int mmSteps = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
        {
            int jump = solve(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            mmSteps = min(mmSteps, jump);
        }
    }

    return dp[ind] = mmSteps;
}

int minimalCost(int n, vector<int> &height, int k)
{
    vector<int> dp(n, -1);
    return solve(n - 1, height, dp, k);
}

//! House Robber

int dp[101];

int slv(int i, vector<int> &v)
{
    if (i >= v.size())
        return 0;
    int &ret = dp[i];
    if (~ret)
        return ret;
    ret = max(v[i] + slv(i + 2, v), slv(i + 1, v));
    return ret;
}

int rob(vector<int> &nums)
{
    memset(dp, -1, sizeof dp);
    return slv(0, nums);
}

int main()
{
}
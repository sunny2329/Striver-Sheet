#include <bits/stdc++.h>
using namespace std;

//! Types of questions
//! 1. Constant Window
//! 2. Longest subarray/substring whose <condition>

//! expand -> r
//! shrink -> l

//! Longest subarray with sum <= k

//! longest substring without any repeating character
int longestSubarray(string str)
{
    if (str.size() == 0)
        return 0;
    int maxans = INT_MIN;
    unordered_set<int> set;
    int l = 0;
    for (int r = 0; r < str.length(); r++)
    {
        if (set.find(str[r]) != set.end())
        {
            while (l < r && set.find(str[r]) != set.end())
            {
                set.erase(str[l]);
                l++;
            }
        }
        set.insert(str[r]);
        maxans = max(maxans, r - l + 1);
    }
    return maxans;
}

//! maximum points you can obtain from cards
int maxPoints(int nums[], int k, int n)
{
    int lsum = 0;
    int rsum = 0;
    int maxSum = 0;
    for (int i = 0; i < k - 1; i++)
    {
        lsum += nums[i];
    }
    maxSum = lsum;
    int rightInd = n - 1;
    for (int i = k - 1; i >= 0; i--)
    {
        lsum = lsum - nums[i];
        rsum += nums[rightInd];
        rightInd--;
        maxSum = max(maxSum, lsum + rsum);
    }
    return maxSum;
}



int main()
{
}
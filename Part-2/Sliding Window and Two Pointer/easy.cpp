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

int lengthofLongestSubstring(string s)
{
    vector<int> mpp(256, -1);

    int left = 0, right = 0;
    int n = s.size();
    int len = 0;
    while (right < n)
    {
        if (mpp[s[right]] != -1)
        {
            left = max(mpp[s[right]] + 1, left);
        }
        mpp[s[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
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

//! max consecutive ones
int longestOnes(vector<int> &nums, int k)
{
    int left = 0, right = 0;
    int zeros = 0;
    int ans = 0;
    while (right < nums.size())
    {
        if (nums[right] == 0)
            zeros++;
        while (zeros > k)
        {
            if (nums[left] == 0)
                zeros--;
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}

//! Fruits into baskets
int totalFruits(vector<int> &arr)
{
    int left = 0, right = 0, ans = 0;
    map<int, int> mpp;
    while (right < arr.size())
    {
        mpp[arr[right]]++;
        if (mpp.size() > 2)
        {
            mpp[arr[left]]--;
            if (mpp[arr[left]] == 0)
                mpp.erase(arr[left]);
            left++;
        }
        if (mpp.size() <= 2)
        {
            ans = max(ans, right - left + 1);
        }
        right++;
    }
    return ans;
}

//! Longest repeating character replacement
int characterReplacement(string s, int k)
{
    int maxfreq = 0, ans = 0, remain = 0, j = 0;
    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'A']++;
        maxfreq = max(maxfreq, freq[s[i] - 'A']);
        if (i - j + 1 - maxfreq > k && j < i)
        {
            freq[s[j] - 'A']--;
            j++;
        }
        if (i - j + 1 - maxfreq <= k)
            ans = max(ans, i - j + 1);
    }
    return ans;
}

//! Binary subarrays with sum
int numSubarraysWithlessSum(vector<int> &nums, int goal)
{
    if (goal < 0)
    {
        return 0;
    }
    int n = nums.size();
    int cnt = 0;
    int high = 0, low = 0;
    int sum = 0;
    while (high < n && low < n)
    {
        sum += nums[high];
        while (sum > goal)
        {
            sum -= nums[low];
            low++;
        }
        cnt += high - low + 1;
        high++;
    }
    return cnt;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return numSubarraysWithlessSum(nums, goal) - numSubarraysWithlessSum(nums, goal - 1);
}

//! Count number of nice subarrays
int helper(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    int left = 0, right = 0;
    int sum = 0, count = 0;
    while (right < nums.size())
    {
        sum = sum + (nums[right] % 2);
        while (sum > goal)
        {
            sum = sum - (nums[left] % 2);
            left++;
        }
        count += right - left + 1;
        right++;
    }
    return count;
}
int numberSubarrayWithSum(vector<int> &nums, int goal)
{
    return helper(nums, goal) - helper(nums, goal - 1);
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    for (int num : nums)
    {
        if (num % 2 == 1)
            num = 1;
        else
            num = 0;
    }
    return numberSubarrayWithSum(nums, k);
}

//! Number of substring containing all three characters

int numberOfSubstrings(string s)
{
    int n = s.length();
    vector<int> lastseen(3, -1);
    int low = 0, high = 0, ans = 0;
    while (high < n)
    {
        lastseen[s[high] - 'a'] = high;
        ans += (1 + min({lastseen[0], lastseen[1], lastseen[2]}));
        high++;
    }
    return ans;
}

//! max points you can score from cards

int maxScore(vector<int> &cardPoints, int k)
{
    int lsum = 0, rsum = 0, maxSum = 0;
    for (int i = 0; i < k; i++)
    {
        lsum += cardPoints[i];
    }
    maxSum = lsum;
    int index = 0;
    while (index < k)
    {
        lsum -= cardPoints[k - index - 1];
        rsum += cardPoints[cardPoints.size() - index - 1];
        index++;
        maxSum = max(maxSum, lsum + rsum);
    }
    return maxSum;
}

int main()
{
}
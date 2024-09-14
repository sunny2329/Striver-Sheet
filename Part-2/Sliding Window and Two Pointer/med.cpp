#include <bits/stdc++.h>
using namespace std;

//! Longest substring with At most K Distinct Characters

int longestSub(string s, int k)
{
    int maxLen = 0, l = 0, r = 0;
    map<char, int> mpp;
    while (r < s.length())
    {
        mpp[s[r]]++;
        if (mpp.size() > k)
        {
            mpp[s[l]]--;
            if (mpp[s[l]] == 0)
            {
                mpp.erase(s[l]);
            }
            l++;
        }
        if (mpp.size() <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
}

//! Subarray with k different integers

int solve(vector<int> nums, int k)
{
    int ans = 0, left = 0, right = 0;
    unordered_map<int, int> mpp;
    while (right < nums.size())
    {
        mpp[nums[right]]++;
        while (mpp.size() > k)
        {
            mpp[nums[left]]--;
            if (mpp[nums[left]] == 0)
            {
                mpp.erase(nums[left]);
            }
            left++;
        }
        ans += right - left + 1;
        right++;
    }
    return ans;
}

int numberofSub(vector<int> &nums, int k)
{
    return solve(nums, k) - solve(nums, k - 1);
}

//! Minimum window
string minWindow(string s, string t)
{
    int ans = 0, n = s.length(), len = INT_MAX, ind = -1;
    unordered_map<char, int> freq;
    for (auto &c : t)
    {
        freq[c]++;
    }
    int i = 0, j = 0, ct = 0;
    while (j < n)
    {
        if (freq[s[j]] > 0)
            ct++;
        freq[s[j]]--;

        while (ct == t.length())
        {
            if (j - i + 1 < len)
            {
                len = j - i + 1;
                ind = i;
            }
            freq[s[i]]++;
            if (freq[s[i]] > 0)
                ct--;
            i++;
        }
        j++;
    }
    return ind == -1 ? "" : s.substr(ind, len);
}




int main()
{
}
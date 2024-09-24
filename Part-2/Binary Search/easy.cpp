#include <bits/stdc++.h>
using namespace std;

//! Binary Search

int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int med = (low + high) / 2;
        if (nums[med] == target)
            return med;
        else if (nums[med] < target)
        {
            low = med + 1;
        }
        else
        {
            high = med - 1;
        }
    }
    return -1;
}

//! find floor

int findFloor(vector<long long> &v, long long n, long long x)
{

    // Your code here
    int start = 0, end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int med = (start + end) / 2;
        if (v[med] == x)
            return med;
        else if (v[med] < x)
        {
            start = med + 1;
            ans = med;
        }
        else
        {
            end = med - 1;
        }
    }
    return ans;
}



int main()
{
}
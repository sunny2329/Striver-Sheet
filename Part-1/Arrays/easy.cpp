#include <bits/stdc++.h>
using namespace std;

//! Largest Element in an array
int largest(vector<int> &arr)
{
    // code here
    int lar = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > lar)
            lar = arr[i];
    }
    return lar;
}

//! Second largest element
int getSecondLargest(vector<int> &arr)
{
    // Code Here
    int lar = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > lar)
            lar = arr[i];
    }
    int ans = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > ans && arr[i] != lar)
            ans = arr[i];
    }
    return ans;
}

//! Check if sorted and rotated

bool check(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
            count++;
    }
    if (nums[nums.size() - 1] > nums[0])
        count++;
    return count <= 1;
}

int main()
{
}
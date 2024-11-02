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

//! Remove duplicates

int removeDuplicates(vector<int> &nums)
{
    int i = 1;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[j] != nums[j - 1])
        {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}

//! Rotated Array

void rotate(vector<int> &nums, int k)
{
    vector<int> temp(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        temp[(i + k) % nums.size()] = nums[i];
    }
    nums = temp;
}

//! Move Zeros

void moveZeroes(vector<int> &nums)
{
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != 0)
        {
            swap(nums[i], nums[j]);
            i++;
        }
    }
}

//! Find the union

vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    // Your code here
    // return vector with correct order of elements
    int i = 0, j = 0;
    vector<int> ans;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            // Add a[i] if it's not a duplicate of the last element in ans
            if (ans.empty() || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
        else if (b[j] < a[i])
        {
            // Add b[j] if it's not a duplicate of the last element in ans
            if (ans.empty() || ans.back() != b[j])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
        else
        { // a[i] == b[j]
            // Add a[i] (or b[j]) only once if it's not a duplicate of the last element in ans
            if (ans.empty() || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
            j++;
        }
    }

    // Add remaining elements from a, avoiding duplicates
    while (i < a.size())
    {
        if (ans.empty() || ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }

    // Add remaining elements from b, avoiding duplicates
    while (j < b.size())
    {
        if (ans.empty() || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }

    return ans;
}

//! Find the missing number

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int rsum = 0;
    for (int i = 0; i <= n; i++)
    {
        rsum += i;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    return rsum - sum;
}

int main()
{
}
#include <bits/stdc++.h>
using namespace std;

//! generate all binary strings without consecutive 1's

void helper(string &s, char prev, int counter, int n, vector<string> &ans)
{
    if (counter == n)
    {
        ans.push_back(s);
        return;
    }

    // Append '0' and recurse
    s += '0';
    helper(s, '0', counter + 1, n, ans);
    s.pop_back();

    // Append '1' only if the previous character is not '1'
    if (prev != '1')
    {
        s += '1';
        helper(s, '1', counter + 1, n, ans);
        s.pop_back();
    }
}

//! generate parenthesis

void solve(string op, int open, int close, vector<string> &ans)
{
    if (open == 0 && close == 0)
    {
        ans.push_back(op);
        return;
    }
    if (open == close)
    {
        op.push_back('(');
    }
}

vector<string> generateParenthesis(int n)
{
    int open = n;
    int close = n;
    vector<string> ans;
    string op = "";
    solve(op, open, close, ans);
    return ans;
}

vector<string> generateBinaryStrings(int n)
{
    vector<string> ans;
    string s = "";
    helper(s, '0', 0, n, ans); // Start with an empty string and counter = 0
    return ans;
}

//! subsets

void helper1(int counter, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans)
{
    if (counter == nums.size())
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[counter]);
    helper1(counter + 1, temp, nums, ans);
    temp.pop_back();
    helper1(counter + 1, temp, nums, ans);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    helper1(0, nums, temp, ans);
    return ans;
}

//! find subsets whose sum is k

void printSubsets(int index, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (index == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    ds.push_back(arr[index]);
    s += arr[index];
    printSubsets(index + 1, ds, s, sum, arr, n);
    ds.pop_back();
    s -= arr[index];
    printSubsets(index + 1, ds, s, sum, arr, n);
}

//! Number of subsets with sum k

int MOD = (int)(1e9 + 7);
void solve(int arr[], int sum, int n, int &ans, int index, int s)
{
    if (index == n)
    {
        if (s == sum)
        {
            ans = (ans + 1) % MOD;
            // return;
        }
        return;
    }
    s += arr[index];
    solve(arr, sum, n, ans, index + 1, s);
    s -= arr[index];
    solve(arr, sum, n, ans, index + 1, s);
}
int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    int ans = 0;
    solve(arr, sum, n, ans, 0, 0);
    return ans;
}

//! combination sum
vector<vector<int>> res;
void print_combo(int i, vector<int> &v, vector<int> &ans, int target)
{
    if (i == v.size())
    {
        if (target == 0)
        {
            res.push_back(ans);
        }
        return;
    }
    // pick same element :
    if (v[i] <= target)
    {
        ans.push_back(v[i]);
        print_combo(i, v, ans, target - v[i]);
        ans.pop_back();
    }
    // not pick same element, picking next element :
    print_combo(i + 1, v, ans, target);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> ans;
    print_combo(0, candidates, ans, target);
    return res;
}

//! Combination sum 2
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        ds.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

//! Subset sum

void subsetSumHelper(int ind, vector<int> &arr, int n, vector<int> &ans, int sum)
{
    if (ind == n)
    {
        ans.push_back(sum);
        return;
    }

    subsetSumHelper(ind + 1, arr, n, ans, sum + arr[ind]);
    subsetSumHelper(ind + 1, arr, n, ans, sum);
}

vector<int> subsetSums(vector<int> arr, int n)
{
    vector<int> ans;
    subsetSumHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}

//! Subset sum 2
void solve(int index, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = index; i < nums.size(); i++)
    {
        if (i != index && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        solve(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    solve(0, nums, ds, ans);
    return ans;
}

//! Combination sum 3

vector<vector<int>> ans;
int sum = 0;
void dfs(vector<int> &cur, int k, int n, int idx)
{
    if (cur.size() == k and sum == n)
    {
        ans.push_back(cur);
        return;
    }
    else if (cur.size() == k and sum > n)
        return;
    for (int i = idx; i <= 9; i++)
    {
        cur.push_back(i);
        sum += i;
        dfs(cur, k, n, i + 1);
        cur.pop_back();
        sum -= i;
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> cur;
    dfs(cur, k, n, 1);

    return ans;
}
int main()
{
    int n = 3;
    vector<string> result = generateBinaryStrings(n);
    for (auto &s : result)
        cout << s << " ";
    return 0;
}
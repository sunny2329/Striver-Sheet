#include <bits/stdc++.h>
using namespace std;
/*!
    DONE 
 */
//! pow

int power(int x, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power(x * x, n / 2);
    else
        return x * power(x, n - 1);
}

//! myAtoi
int getFun(long res, string &s, int counter, int sign)
{
    if (sign * res >= INT_MAX)
        return INT_MAX;
    if (sign * res <= INT_MIN)
        return INT_MIN;
    if (counter >= s.size() || s[counter] < '0' || s[counter] > '9')
        return sign < 0 ? res * (-1) : res;
    return getFun(res * 10 + (s[counter] - '0'), s, ++counter, sign);
}

int myAtoi(string s)
{
    long res = 0;
    int counter = 0;
    while (s[counter] == ' ')
        counter++;
    int sign = 1;
    if (s[counter] == '-')
    {
        sign = -1;
        counter++;
    }
    else if (s[counter] == '+')
        counter++;
    return getFun(res, s, counter, sign);
}

//! Sort a stack using recursion

void insertSorted(stack<int> &s, int x)
{
    if (s.empty() || x >= s.top())
    {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insertSorted(s, temp);
    s.push(temp);
}

void sortStack(stack<int> &s)
{
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        sortStack(s);
        insertSorted(s, temp);
    }
}

//! Reverse a stack using recursion

void insert_at_bottom(stack<int> &St, int x)
{
    if (St.size() == 0)
        St.push(x);
    else
    {
        int y = St.top();
        St.pop();
        insert_at_bottom(St, x);
        St.push(y);
    }
}

void fun(stack<int> &St)
{
    if (St.size() > 0)
    {
        int x = St.top();
        St.pop();
        fun(St);
        insert_at_bottom(St, x);
    }
}

//! count good numbers
int M = 1e9 + 7;

long long power(long long b, long long e, long long ans)
{
    if (e == 0)
        return ans;
    if (e & 1)
        return power(b, e - 1, (ans * b) % M);
    else
        return power((b * b) % M, e / 2, ans);
}

int goodNumbers(long long n)
{
    long long temp = power(20, n / 2, 1);
    return (n & 1) ? (temp * 5) % M : temp;
}

int main()
{
    cout << power(3, 3);
}
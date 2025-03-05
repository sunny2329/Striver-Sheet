#include <bits/stdc++.h>

using namespace std;

int dataTypeSize(string str)
{
    // your code here
    if (str == "Character")
    {
        return sizeof(char);
    }
    else if (str == "Integer")
    {
        return sizeof(int);
    }
    else if (str == "Long")
    {
        return sizeof(long);
    }
    else if (str == "Float")
    {
        return sizeof(float);
    }
    else
    {
        return sizeof(double);
    }
}

//! In bytes:
// Character size -> 1
// Integer size -> 4
// Long size -> 8 (depends on the system architecture)
// Float size -> 4
// Double size -> 8

int main()
{
    string str;
    cin >> str;
    cout << dataTypeSize(str) << endl;
    return 0;
}
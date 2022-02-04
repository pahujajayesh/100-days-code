#include <iostream>
#include <cstring>
using namespace std;
bool checkpalindrome(string str, int i, int j)
{
    if (i > j)
    {
        return true;
    }
    if (str[i] != str[j])
    {
        return false;
    }
    else
    {
        return checkpalindrome(str, i + 1, j - 1);
    }
}
int main()
{
    string str = "aaabaa";
    if (checkpalindrome(str, 0, str.length() - 1))
    {
        cout << "it is a plaindrom";
    }
    else
    {
        cout << "not a plaindrome";
    }

    return 0;
}

//Coding Ninjas Ques
// Ques - https: //www.codingninjas.com/codestudio/problems/check-palindrome_920555

#include <math.h>
#include <cstring>
bool checkPlain(string s, int i, int j)
{
    if (i > j)
    {
        return true;
    }
    if (s[i] != s[j])
    {
        return false;
    }
    else
    {
        return checkPlain(s, i + 1, j - 1);
    }
}
bool checkPalindrome(long long n)
{
    string s = "";
    int r;
    while (n != 0)
    {
        r = n % 2;
        n = n / 2;
        s.push_back(r);
    }
    int i = 0;
    int j = s.length() - 1;
    bool ans = checkPlain(s, i, j);
    return ans;
}
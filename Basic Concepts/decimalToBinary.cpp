#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
void convert(int n)
{
    int i = 0;
    int ans = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }
    string str = to_string(ans);
    cout << str;
}
int main()
{
    int n;
    cin >> n;
    convert(n);
    return 0;
}
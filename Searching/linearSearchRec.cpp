#include <iostream>
using namespace std;
bool linearSearch(int *arr, int n, int x)
{
    if (n == 0)
    {
        return false;
    }
    if (arr[0] == x)
    {
        return true;
    }
    else
    {
        bool smallAns = linearSearch(arr + 1, n - 1, x);
        return smallAns;
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    if (linearSearch(arr, n, x))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}
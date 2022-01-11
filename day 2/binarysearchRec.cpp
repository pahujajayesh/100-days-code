#include <iostream>
using namespace std;
bool binarySearch(int *arr, int n, int s, int e, int x)
{
    if (s > e)
    {
        return false;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == x)
    {
        return true;
    }
    if (arr[mid] < x)
    {
        return binarySearch(arr, n, s, mid - 1, x);
    }
    else
    {
        return binarySearch(arr, n, mid + 1, e, x);
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
    int s = 0, e = n - 1;
    cout << binarySearch(arr, n, s, e, x) << endl;

    return 0;
}
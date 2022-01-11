#include <iostream>
using namespace std;
bool isSorted(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool smallAns = isSorted(arr + 1, n - 1);
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
    if (isSorted(arr, n))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }

    return 0;
}
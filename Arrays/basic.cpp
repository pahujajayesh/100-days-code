#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int output[n - 2];
    for (int i = 0; (n - i) >= 3; i++)
    {
        int a = arr[i];
        int b = arr[i + 1];
        int c = arr[i + 2];
        if ((a + c > b) && (a + b > c) && (c + b > a))
        {
            output[i] = 1;
        }
        else
        {
            output[i] = 0;
        }
    }
    for (int i = 0; i < n - 2; i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}
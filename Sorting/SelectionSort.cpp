#include <iostream>
using namespace std;
void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1 - i; i++)
    {
        int minIndex = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
    selectionSort(arr, n);
    return 0;
}
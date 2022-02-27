#include <iostream>
using namespace std;

int plaindrome(string s, int n, int m, int arr[])
{
    int ansCount = 0;
    for (int k = 0; k < m; k++)
    {
        int size = arr[k];
        for (int i = 0; i < n; i++)
        {
            bool isPalin = true;
            int j = i + size - 1;
            if (j >= n)
            {
                break;
            }
            int x=i;
            while (x <= j)
            {
                if (s[x] != s[j])
                {
                    isPalin = false;
                    break;
                }
                else
                {
                    x++;
                    j--;
                }
            }
            if (isPalin)
            {
                ansCount++;
            }
        }
    }
    return ansCount;
}
int main()
{
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int m;
    cin >> m;
    int *arr = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    cout << plaindrome(s, n, m, arr) << endl;
    delete[] arr;

    return 0;
}
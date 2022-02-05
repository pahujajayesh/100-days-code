int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    // find correct index for pivot
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start;
    int j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }
    // return pivotIndex
    return pivotIndex;
}
void solve(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    // find partition
    int p = partition(arr, start, end);
    // sort left part
    solve(arr, start, p - 1);
    // sort right part
    solve(arr, p + 1, end);
}
vector<int> quickSort(vector<int> arr)
{
    solve(arr, 0, arr.size() - 1);
    return arr;
}

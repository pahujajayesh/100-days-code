#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(11);
    q.push(177);
    q.push(37);
    cout << "size " << q.size() << endl;
    q.pop();
    cout << "size " << q.size() << endl;
    if (q.empty())
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        cout << "queue is not empty" << endl;
    }

    cout << "first elemnet:  " << q.front() << endl;
    cout << "last element" << q.back() << endl;
    return 0;
}
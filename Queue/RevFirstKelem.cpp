#include <stack>
queue<int> modifyQueue(queue<int> q, int k)
{
    // add code here.
    stack<int> s;
    //push first k elements to stack
    for (int i = 0; i < k; i++)
    {
        int curr = q.front();
        q.pop();
        s.push(curr);
    }
    //insert the reversed k elements at end of queue
    while (!s.empty())
    {
        int curr = s.top();
        s.pop();
        q.push(curr);
    }
    int t = q.size() - k;
    //now pop from starting and push it to end to obtain the output
    while (t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}
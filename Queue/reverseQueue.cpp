// Approach 1 Use a stack
// Time o(n) Space o(n)

#include <stack>
#include <queue>
queue<int> rev(queue<int> q)
{
    stack<int> s;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        s.push(curr);
    }
    while (!s.empty())
    {
        int curr = s.pop();
        q.push(curr);
    }
    return q;
}
// Approach 2 recursive
// time o(n) space o(n)
void solve(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int curr = q.front();
    q.pop();
    solve(q);
    q.push(curr);
}
queue<int> rev(queue<int> q)
{
    solve(q);
    return q;
}
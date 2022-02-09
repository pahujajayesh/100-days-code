#include <stack>
stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    stack<int> ans;
    while (!myStack.empty())
    {
        int num = myStack.top();
        ans.push(num);
        myStack.pop();
    }
    myStack.push(x);
    while (!ans.empty())
    {
        int num = ans.top();
        myStack.push(num);
        ans.pop();
    }
    return myStack;
}

//recursive approach
void solve(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();
    solve(s, x);
    s.push(num);
}
stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
}

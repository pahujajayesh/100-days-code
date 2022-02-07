// Approach 1(brute force)
//  time-O(n) space->o(n)
#include <stack>
void deleteMiddle(stack<int> &inputStack, int N)
{
    stack<int> output;
    int count = 0;
    while (count != N / 2)
    {
        int val = inputStack.top();
        output.push(val);
        inputStack.pop();
        count++;
    }
    if (count == N / 2)
    {
        inputStack.pop();
    }
    while (!output.empty())
    {
        int val = output.top();
        inputStack.push(val);
        output.pop();
    }
}
// Approach->2 Recursive
//  time-O(n) space->o(n)

void solve(stack<int> &inputStack, int count, int n)
{
    if (count == n / 2)
    {
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();
    solve(inputStack, count + 1, n);
    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;
    solve(inputStack, count, N);
}

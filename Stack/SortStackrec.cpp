//time o(n^2)
void sortedInsert(stack<int> &s, int num)
{
    if (s.empty() || (!s.empty() && s.top() < num))
    {
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    sortedInsert(s, num);
    s.push(n);
}
void sortStack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    sortStack(s);

    sortedInsert(s, num);
    //     s.push(num);
}
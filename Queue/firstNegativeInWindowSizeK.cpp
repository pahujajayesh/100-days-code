vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    deque<long long int> dq;
    vector<long long> ans;
    // step1 process first k elements
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }
    // store it in ans vector
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    //if size is 0 than push 0 in ans vector
    else
    {
        ans.push_back(0);
    }
    // process remaining elements
    for (int i = K; i < N; i++)
    {
        // remove extra elememts
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }
        // add new elelemt
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
        //store ans
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}
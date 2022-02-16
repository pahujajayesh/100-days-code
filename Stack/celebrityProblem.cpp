class Solution
{
private:
    bool knows(vector<vector<int>> &M, int a, int b)
    {
        // if a knows b return true
        if (M[a][b] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // step 1 insert all elements in stack in random order
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }
        // step 2 pop 2 elemets from stack and check if they know each other
        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if (knows(M, a, b))
            {
                // means a knows b and b can be the celeb so push it back in stack
                s.push(b);
            }
            else
            {
                // means b knows a but a don't know b
                s.push(a);
            }
        }
        int output = -1;
        int ans = s.top();
        int count0 = 0;
        // check if ans row all elements are zero
        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] == 0)
            {
                count0++;
            }
        }
        int count1 = 0;
        // check if ans col all elemets are 1 except itself
        for (int i = 0; i < n; i++)
        {
            if (i != ans && M[i][ans] == 1)
            {
                count1++;
            }
        }
        if (count0 == n && count1 == n - 1)
        {
            output = ans;
        }
        return output;
    }
};

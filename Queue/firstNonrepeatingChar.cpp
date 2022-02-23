class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // Code here
        // unordered map to store the count of aplhabets
        unordered_map<char, int> count;
        queue<char> q;
        string ans = "";
        for (int i = 0; i < A.length(); i++)
        {
            char ch = A[i];
            count[ch]++;
            // push the curr element in queue
            q.push(ch);
            while (!q.empty())
            {
                if (count[q.front()] > 1)
                {

                    q.pop();
                }
                else
                {
                    ans.push_back(q.front());
                    break;
                }
            }
            // if repeating elements than push # in ans string
            if (q.empty())
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};
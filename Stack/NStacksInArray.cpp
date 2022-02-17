// time o(1)
//  space(s+n) S->SIZE OF ARRAY N->NO OF STACKS
class NStack
{
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;

public:
    NStack(int N, int S)
    {
        s = S;
        n = N;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        // initialize top
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        // initialize next
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        // for last element store -1
        next[s - 1] = -1;
        // initialize free spot to -1
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if (freespot == -1)
        {
            return false;
        }
        // step 1: fnd index
        int index = freespot;
        // update freespot
        freespot = next[index];
        // insert element in array
        arr[index] = x;
        // update next
        next[index] = top[m - 1];
        // update top
        top[m - 1] = index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check if stack is empty
        if (top[m - 1] == -1)
        {
            return -1;
        }
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};
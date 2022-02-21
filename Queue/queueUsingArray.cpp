class Queue
{
    int *arr;
    int size;
    int qfront;
    int rear;

public:
    Queue()
    {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        if (qfront == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        if (rear == size)
        {
            return;
        }
        arr[rear] = data;
        rear++;
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (isEmpty())
        {
            return -1;
        }
        int curr = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if (qfront == rear)
        {
            qfront = 0;
            rear = 0;
        }
        return curr;
    }

    int front()
    {
        // Implement the front() function
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};
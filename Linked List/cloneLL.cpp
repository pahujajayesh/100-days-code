//time->o(n)
//space->o(n)
class Solution
{
private:
    void insertAtTail(Node *&head, Node *&tail, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node *copyList(Node *head)
    {
        // step1->create a clone list
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;
        Node *temp = head;
        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        // step2->create mapping of original and clone node
        unordered_map<Node *, Node *> oldToNewNode;
        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        while (originalNode != NULL)
        {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL)
        {
            cloneNode->arb = oldToNewNode[originalNode->arb];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};

//time->o(n)
//space->o(1)
class Solution
{
private:
    void insertAtTail(Node *&head, Node *&tail, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node *copyList(Node *head)
    {
        // step1->cretae a clone list
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;
        Node *temp = head;
        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        // step2:cloneNode add between original nodes
        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL)
        {
            Node *next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;

            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }
        // step3: random pointer copy

        temp = head;
        while (temp != NULL)
        {
            if (temp->next != NULL)
            {
                temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
            }
            temp = temp->next->next;
        }
        // step 4:revert changes done in step 2

        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL)
        {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if (originalNode != NULL)
            {
                cloneNode->next = originalNode->next;
            }

            cloneNode = cloneNode->next;
        }

        // step5:return cloneNode
        return cloneHead;
    }
};
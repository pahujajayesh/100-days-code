//space:O(1)
//time:O(n)
//reverse node
Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *temp = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node *addOne(Node *head)
{
    // Removing leading zeroes.
    while (head != NULL && head->data == 0)
    {
        head = head->next;
    }
    //revere head;
    head = reverse(head);
    //to store the head
    Node *temp = head;
    //prev to store previos data of head
    Node *prev = NULL;
    int carry = 1;
    while (head != NULL)
    {
        int sum = carry + head->data;
        carry = sum / 10;
        sum = sum % 10;
        //update the sum in head->data
        head->data = sum;
        prev = head;
        //increment head
        head = head->next;
    }
    //if list is all travered and carry is still present
    if (carry != 0)
    {
        //create a nwenode
        Node *newNode = new Node(0);
        newNode->data = carry;
        if (prev != NULL)
        {
            prev->next = newNode;
        }
        else
        {
            //means list is empty
            return newNode;
        }
    }
    //reverse the list
    Node *ans = reverse(temp);
    return ans;
}

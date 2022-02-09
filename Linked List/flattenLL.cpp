// brute force
#include <algorithm>
Node *flattenLinkedList(Node *head)
{
    vector<int> ans;
    // traverse the linked list and push it into vector
    while (head != NULL)
    {
        ans.push_back(head->data);
        Node *temp = head;
        // push all the child nodes
        while (temp->child != NULL)
        {
            ans.push_back(temp->child->data);
            temp = temp->child;
        }
        head = head->next;
    }
    // sort the list
    sort(ans.begin(), ans.end());
    Node *root = NULL;
    Node *tail = NULL;
    // create new linked list
    for (int i = 0; i < ans.size(); i++)
    {
        Node *newNode = new Node(ans[i]);

        if (root == NULL)
        {
            root = newNode;
            tail = newNode;
        }
        else
        {
            tail->child = newNode;
            tail = newNode;
        }
    }
    return root;
}
//one test case failing
Node *solve(Node *left, Node *right)
{
    if (left == NULL)    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    Node *ans = new Node(-1);
    Node *temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->child = left;
            temp = left;
            left = left->child;
        }
        else
        {
            temp->child = right;
            temp = right;
            right = right->child;
        }
    }
    while (left != NULL)
    {
        temp->child = left;
        temp = left;
        left = left->child;
    }
    while (right != NULL)
    {
        temp->child = right;
        temp = right;
        right = right->child;
    }
    //     	ans=ans->child;
    return ans->child;
}
Node *flattenLinkedList(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL && head->child == NULL)
    {
        return head;
    }

    Node *left = head;
    Node *right = head->next;
    head->next = NULL;
    right = flattenLinkedList(right);
    Node *result = solve(left, right);
    return result;
}
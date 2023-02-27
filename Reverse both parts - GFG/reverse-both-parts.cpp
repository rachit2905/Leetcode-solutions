//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
    Node* fun(Node* head)
    {
        Node *temp=head;
        Node *p=NULL;
        Node *q=NULL;
        while(temp->next!=NULL)
        {
            p=temp;
            temp=temp->next;
            p->next=q;
            q=p;
        }
        temp->next=p;
        return temp;
    }
    Node *reverse(Node *head, int k)
    {
        // code here
             Node* t2 = head;

        Node* t1;

        Node* left = head;

        int i = 1; 

        while (i <= k)

        {

            t1 = t2;

            t2 = t2 -> next;

            i++;

        }

        t1 -> next = NULL;

        Node* right = t2;        

        Node* first = fun(left);

        Node* second = fun(t2);

        head = first;

        while (first -> next != NULL)

            first = first -> next;

        first -> next = second;

        return head;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends
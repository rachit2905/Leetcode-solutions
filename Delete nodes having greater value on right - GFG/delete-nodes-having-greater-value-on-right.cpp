//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        while(curr != NULL)
        {
            Node *NEXT = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NEXT;
        }
        
        return prev;
        
    }
    Node *compute(Node *head)
    {
        // step 1: reverse list
        head = reverseList(head);
        
        // now start deletation
        int data = INT_MIN;
        
        Node *prev = NULL;
        Node *temp = head;
        while(temp != NULL)
        {
            if(temp->data < data)
            {
                // remove 
                prev->next = temp->next;
                temp = prev->next;
            }
            else
            {
                prev = temp;
                data = temp->data;
                temp = temp->next;
            }
        }
        
         head = reverseList(head);
         
         return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends
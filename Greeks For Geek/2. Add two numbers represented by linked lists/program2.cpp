//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private :
    struct Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertAtTail(Node* &head, Node* &tail, int val)
    {
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return ;
        }
        
        tail->next = newNode;
        tail = newNode;
        
        return ;
        
    }
    
    struct Node* add(Node* first, Node* second)
    {
        int carry =0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0 ){
            
            
            int val1 = 0;
            if(first != NULL)
                val1 = first->data;
                
            int val2 = 0;
            if(second != NULL)
                val2 = second->data;
            
            
            int sum = carry + val1 + val2;
            
            int digit = sum % 10;
            
            // Create node and add in answer linked list
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            
            if(first != NULL)
                first = first->next;
                
            if(second != NULL)
                second = second->next;
            
            // first = first->next;
            // second = second->next;
            
        }
        
       
        
        return ansHead;
        
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // Step 1 : reverse Input linked list
        first = reverse(first);
        second = reverse(second);
        
        // Step 2 : add to link list 
        Node* ans = add(first, second);
        
        // Step 3 : reverse answer
        // ans = reverse(ans);
        
        return reverse(ans);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
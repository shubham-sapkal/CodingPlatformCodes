/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/


Node* kReverse(Node* head, int k) {
    // base case
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    // Step 1 : reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;
    int cnt = 0;
    
    while(curr != NULL && cnt < k)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        cnt++;
    }
    
    // Step 2 : call recursion for remaining part
    if(nextNode != NULL)
    {
        head->next = kReverse(nextNode, k);
    }
    
    // Step 3 : return head of recursed linked list
    return prev;
    
}
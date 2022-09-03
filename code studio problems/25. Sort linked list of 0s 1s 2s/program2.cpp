/********************************
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

********************************/

void insertAtTail(Node* &tail, Node* curr)
{
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node *head)
{
    // Write your code here.
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    
    // created three linked list for one, two and three
    while(curr != NULL)
    {
        if(curr->data == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if(curr->data == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if(curr->data == 2)
        {
            insertAtTail(twoTail, curr);
        }
        
        curr = curr -> next;
        
    }
    
    // OneHead is Not Empty
    if(oneHead != NULL)
    {
        zeroTail -> next = oneHead -> next;
        oneTail->next = twoHead->next; 
    }
    else{
        zeroTail -> next = twoHead -> next;
    }
    
    
    twoTail->next = NULL;
    
    // Set head to new linked list
    head = zeroHead->next;
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
    
}

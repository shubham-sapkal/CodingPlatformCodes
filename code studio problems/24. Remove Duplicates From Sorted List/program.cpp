/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
    // Write your code here.
    
    if(head == NULL){
        return NULL;
    }
    
    Node* curr = head;
    
    while (curr !=NULL )
    {
        if( curr->next != NULL && curr->data == curr->next->data ){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            temp->next = NULL;
            delete temp;
        }
        else{
            curr=curr->next;
        }
    }
    
    return head;
    
}
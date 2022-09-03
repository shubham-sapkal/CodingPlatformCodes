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

Node* sortList(Node *head)
{
    // Write your code here.
    int count0 = 0, count1 = 0, count2 = 0; 

    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data == 0){
            count0++;
        }
        else if(temp->data == 1) {
            count1++;
        }
        else{
            count2++;
        }
        temp = temp->next;
    }
    
    temp = head;
    
    for(int i = 0; i < count0; i++){
        temp->data = 0;
        temp = temp->next;
    }
    
    for(int i = 0; i < count1; i++){
        temp->data = 1;
        temp = temp->next;
    }
    
    for(int i = 0; i < count2; i++){
        temp->data = 2;
        temp = temp->next;
    }
    
    return head;
    
}

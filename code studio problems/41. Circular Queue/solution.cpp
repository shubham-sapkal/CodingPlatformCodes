class CircularQueue{
    int* arr;
    
    int front;
    int rear;
    
    int size;
    
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
        
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
       //to check whther queue is full
        if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) )         {
            //cout << "Queue is Full";
            return false;
        }
        else if(front == -1) //first element to push
        {
            front = rear = 0;
            
        }
        else if(rear == size-1 && front != 0) {
            rear = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            rear++;
        }
        //push inside the queue
        arr[rear] = value;
        
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // check queye is empty or not
        if(front == -1)
        {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){ // single element is present
            front = -1;
            rear = -1;
        } else if(front == size-1) { // to maintain cyclic nature
            front = 0;
        }
        else{
            front++;
        }
        return ans;
        
    }
};
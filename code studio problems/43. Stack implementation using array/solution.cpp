// Stack class.
class Stack {
    int* arr;
    int size;
    int stop;
public:
    
    Stack(int capacity) {
        // Write your code here.
        arr =  new int[capacity];
        size = capacity;
        stop = -1;
    }

    void push(int num) {
        // Write your code here.
//         cout<<"push into stack" << endl;
        if(stop >= size){
//             cout<<"stack is full .. ";
            return ;
        }
        stop++;
        arr[stop] = num;
        
    }

    int pop() {
        // Write your code here.
//         cout<<"pop into stack" << endl;
        if(stop == -1){
            return -1;
        }
        int ans = arr[stop];
        stop--;
        return ans;
    }
    
    int top() {
//         cout<<"top into stack" << endl;
        // Write your code here.
        if(stop == -1)
        {
            return -1;
        }
        
        return arr[stop];
    }
    
    int isEmpty() {
        // Write your code here.
        return stop == -1 ? true : false;
    }
    
    int isFull() {
        // Write your code here.
        return stop >= size ? true : false;
    }
    
};
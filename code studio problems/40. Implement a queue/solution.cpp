class Queue {
    int* arr;
    int qfront;
    int qrear;
    int size;
    
public:
    Queue() {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        
        qfront = 0;
        qrear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return qfront == qrear ? true : false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function 
        if(qrear == size){
            cout<<"Queue is Full" << endl;
        }
        else{
            arr[qrear] = data;
            qrear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(qfront == qrear)
        {
            return -1;
        } else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == qrear)
            {
                qfront = 0;
                qrear = 0;
            }
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(qfront == qrear)
        {
            return -1;
        } else{
            return arr[qfront];
        }
    }
};
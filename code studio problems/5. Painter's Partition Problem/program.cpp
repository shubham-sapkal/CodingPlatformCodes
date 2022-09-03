bool isPossibleSolution(vector<int> boards, int k, int mid){
    
    int painterCount = 1;
    int boardSum = 0;
    
    for(int i=0; i<boards.size(); i++){
        
        if(boardSum + boards[i] <= mid ){
            boardSum += boards[i];
        }
        else {
            painterCount++;
            if(painterCount > k || boards[i] > mid ){
                return false;
            }
            boardSum = boards[i];
        }
        
    }
    
    return true;
    
}

int findMax(vector<int> boards){
    int max = boards[0];
    
    for(int i = 1; i< boards.size(); i++){
        if(boards[i] > max )
            max = boards[i];
    }
    
    return max;
    
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    
    int sum = 0;
    for(int i = 0; i<boards.size(); i++)
        sum = sum+boards[i];
    
    int start = findMax(boards);
        
    int end = sum;
    
    int mid = start + (end-start)/2;
    
   // int ans = -1;
    
    //cout<<"ans = "<<ans;
    
    while(start<=end){
        
        //cout<<"\nStart = "<<start;
        //cout<<"\nEnd = "<<end;
        //cout<<"\nMid = "<<mid;
        
        if(isPossibleSolution(boards, k , mid)){
            //ans = mid;
            end = mid-1;
        }
        else {
            start = mid+1;
        }
        
        mid = start + (end-start)/2;
  
    }
    
    //cout<<"ans = "<<ans;
    
    return start;
    
}
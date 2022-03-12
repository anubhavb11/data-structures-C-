 long long maxSubarraySum(int arr[], int n){
        
        // Your code here
       int cs=0,ms=INT_MIN;
       int cnt=0;
       for(int i=0;i<n;i++){
           
           if(arr[i]<= cs + arr[i]){
               cs =cs + arr[i];
           }
           else{
               cs = arr[i];
           }
           ms = max(ms,cs);
       }
       
    //   if(cnt == n){
    //       ms=INT_MIN;
    //       for(int i=0;i<n;i++){
    //           ms = max(arr[i],ms);
    //       }
    //   }
       return ms;
        
    }
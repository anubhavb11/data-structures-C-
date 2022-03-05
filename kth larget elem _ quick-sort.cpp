// https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/

class Solution {
public:
    int ans = -1;
    int partition(vector<int>& arr, int s , int e){
            int i = s-1;
            int j= s;
            for(;j<e;j++){
                if(arr[j]<= arr[e]){
                     i++;
                    swap(arr[i],arr[j]);
                    // i++;

                }
            }
            swap(arr[i+1],arr[e]);
            return i+1;
    }
    int  quick(vector<int>& arr, int s , int e,int k){
    // if(s >= e){
    //     return -1;
    // }
    int p = partition(arr, s, e);
        cout<<p;
    if( p == k){
        for(int i=0;i<=e;i++){
            cout<<arr[i]<<" ";
        }
        cout<<arr[p]<<"a ";
        ans = arr[p];
        return arr[p];
    }
    if(k < p){
        cout<<"a";
          quick(arr,s,p-1,k);

    }
    else{
        cout<<"b";
        quick(arr,p+1,e,k);

    }
        return arr[p];
  
    
}
    
    int findKthLargest(vector<int>& arr, int k) {
         int s =0;
    int e = arr.size();
           if(e == 1){
               return arr[s];
           }
        if(e==2){
            if(k==1){
                return max(arr[0],arr[1]);
            }
            else{
                return min(arr[0],arr[1]);
                
            }
        }
        k = e-k;
     
     quick(arr,s,e-1,k);
        return ans;
            
        
    }
};
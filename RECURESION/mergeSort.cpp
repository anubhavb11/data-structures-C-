#include <iostream>
using namespace std;


void merge(int* arr,int s,int e){
    int i =s;
    int mid = (s+e)/2;
    int j = mid+1;
    int k =s;
    int temp[1000];
    while(i<=mid && j<=e ){
        if(arr[i] <arr[j] ){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j<=e){
        temp[k] = arr[j];
        k++;
        j++;
    }
    
    for(int q=s;q<=e;q++){
        // cout<<temp[q];
        arr[q] = temp[q];
    }
}


void sort(int* arr,int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;

    sort(arr,s,mid);
    sort(arr,mid+1,e);

    merge(arr,s,e);

}


int main() {
   int arr[] = {1,17,749,3,2,1};
  int n = sizeof(arr)/sizeof(arr[0]);
//    for(int i=0;i<4;i++){
//        cout<<arr[i]<<" ";
//    }
   sort(arr,0,n-1);
   for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
   }

}

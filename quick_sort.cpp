#include <iostream>
#include<vector> 
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int s , int e){
    int i = s;
    int j= s;
    for(;j<e;j++){
        if(arr[j]<= arr[e]){
            //  i++;
            swap(arr[i],arr[j]);
            i++;
           
        }
    }
    swap(arr[i],arr[e]);
    return i;
}


void quick(vector<int>& arr, int s , int e){
    if(s >= e){
        return ;
    }
    int p = partition(arr, s, e);
    quick(arr,s,p-1);
    quick(arr,p+1,e);
}

int main() {
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int s =0;
    int e = n;
    quick(arr,s,e-1);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

}

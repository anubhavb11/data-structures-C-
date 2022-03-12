#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void sub(char* arr,int i){
    if(arr[i] == '\0'){
        cout<<arr<<endl;
        return;
    }
    for(int j=i;arr[j]!='\0';j++){
        swap(arr[i],arr[j]);
        sub(arr,i+1);

        // backtracking
        swap(arr[i],arr[j]);
    }

}


int main() {

    char  a[100]= "abc";
    char b[100] ;
    sub(a,0);

}

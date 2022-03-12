#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void sub(char* a, char* b,int i,int j){
    if(a[i] == '\0'){
        // cout<<"Dsd";
        b[j] = '\0';
        cout<<b<<endl;
        return;
    }
    b[j] = a[i];
    sub(a,b,i+1,j+1);
    sub(a,b,i+1,j);
}


int main() {

    char  a[100]= "abc";
    char b[100] ;
    sub(a,b,0,0);

}

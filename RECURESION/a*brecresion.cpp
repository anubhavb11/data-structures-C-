#include <iostream>
using namespace std;
// int ans =0;
int fact(int a,int b){
    if(a == 0 || b == 0 ){
        return 0;
    }
    int ans = a + fact(a,b-1);
    // ans = ans + a;
    return ans;
}


int main() {
    int n;
    cin>>n;
    int b;
    cin>>b;
    cout<<fact(n,b);
}

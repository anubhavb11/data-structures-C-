#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int fibo(int n, int* dp){
    if(n==0 || n==1){
        dp[n] =n;
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    int ans = fibo(n-1,dp) + fibo(n-2,dp);
    dp[n] = ans;
    return ans;
}

int fiboBU(int n){
    int* dp = new int[n+1];
    dp[0] = 0;
    p[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}




int main() {
//    int n;
//    cin>>n;
//     int* dp = new int[n+1];
//     for(int i=0;i<=n;i++){
//         dp[i] = -1;
//     }
//    cout<<fib(n,dp);

   int n;
	cin>>n;
	int *dp = new int[n+1];
	for(int i=0;i<=n;i++){
		dp[i] = -1;
	}

	cout<<fib(n,dp)<<endl;
	// cout<<BottomUp(n)<<endl;
	cout<<fibo(n,dp)<<endl;
	return 0;
}

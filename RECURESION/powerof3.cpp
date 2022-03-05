// https://leetcode.com/problems/power-of-three/
class Solution {
public:
    
    int rec(int n,long long int no){
        if(no == n){
            return true;
        }
        if(no> n){
            return false;
        }
        no = no * 3;
        return rec(n,no);
    }
    
    bool isPowerOfThree(int n) {
        long long int no = 3;
        if(n==1){
            return true;
        }
        // while(no<=n){
        //     if(no == n){
        //         return true;
        //     }
        //     no = no*3;
        // }
        // return false;
        
        return rec(n,3);
    }
};
//   https://practice.geeksforgeeks.org/problems/check-for-subsequence4930/1#
 
 bool isSubSequence(string a, string b) 
    {
        // code here
        int j=0;
        for(int i=0;i<b.length();i++){
            if(b[i] == a[j]){
                // cout<<a[j];
                j++;
            }
        }
        if(j == a.length()){
            return true;
        }
        return false;
        // sub(A);
        
    }
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/

class Solution {
public:
    char arr[100][20] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    
    void cal(string digit,char* b,int i,int j){
        if(digit[i]=='\0'){
            if(j==0){
                return;
            }
            b[j] = '\0';
            cout<<"😂";
            ans.push_back(b);
            return;
        }
        int x = digit[i] - '0';
        if(x==1 || x==0){
            cal(digit,b,i+1,j);
        }
        for(int k=0; arr[x][k]!='\0';k++){
            b[j] =  arr[x][k];
            cout<<b[j];
            cal(digit,b,i+1,j+1);
          
        }
          // cal(digit,b,i+1,j);
    }
    
    vector<string> letterCombinations(string digits) {
        char b[100];
        cal(digits,b,0,0);
        vector<string> d;
        // if(ans.size() ==1){
        //     return d;
        // }
        return ans;
    }
};
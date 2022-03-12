//  https://leetcode.com/problems/maximum-69-number/

class Solution {
public:
    int maximum69Number (int num) {
        int temp = num;
        int len =0;
        vector<int> v;
        while(temp){
            int x = temp%10;
            v.push_back(x);
            len++;
            temp = temp/10;
        }
        reverse(v.begin(),v.end());
        for(int i= 0; i<v.size();i++){
            if(v[i] == 6){
                v[i] = 9;
                break;
            }
        }
        int ans = 0;
        for(int i= 0; i<v.size();i++){
            ans = ans*10 + v[i];
        }
        return ans;
        
        
        
    }
};
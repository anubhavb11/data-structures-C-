//  https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
class Solution {
public:
    
    static bool comp(vector<int>& v1, vector<int>& v2 ){
        // if(v1[0] == v2[0]){
            return v1[1] < v2[1]; 
        // }
        // return v1[0] < v2[0];
    }

    int findMinArrowShots(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<v.size();i++){
            
        }
        int ans =1;
        int end = v[0][1];
        for(int i=1;i<v.size();i++){
                if(v[i][0] > end){
                    ans++;
                    end = v[i][1];
                }
           
            // while(i<v.size() && v[i][1]>v[i+1][0]){
            //     i++;
            // }
        }
        return ans;
    }
};
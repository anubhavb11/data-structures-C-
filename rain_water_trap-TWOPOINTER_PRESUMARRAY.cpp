// https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> l;
        vector<int> r;
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx,arr[i]);
            l.push_back(mx);
        }
        mx = INT_MIN;
        for(int i=n-1;i>=0;i--){
            mx = max(mx,arr[i]);
            r.push_back(mx);
        }
        reverse(r.begin(),r.end());
        int ans =0;
        for(int i=0;i<n;i++){
            
            int x = min(l[i],r[i]) - arr[i];
            cout<<x<<" ";
            ans = ans + x;
        }
        return ans;
        
    }
};

// optimize 
class Solution {
public:
    
    // min(arr[r],arr[l]) - a[i];
    int trap(vector<int>& arr) {
        int n = arr.size();
        int lmax=0;
        int rmax =0;
        int l = 0;
        int r = n-1;
        int ans =0;
        while(l<=e){
            if(arr[l]<=arr[r]){
                if(lmax> arr[l]){
                    int w = lmax - arr[l];
                    ans = ans + w;
                }
                else{
                    lmax = arr[l];
                }
                l++;

            }
            else{
                if(rmax> arr[r]){
                    int w = rmax - arr[r];
                    ans = ans + w;
                }
                else{
                    rmax = arr[r];
                }
                r--;
                
            }
        }
        return ans;

    }
};
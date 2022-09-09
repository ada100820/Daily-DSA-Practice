class Solution {
public:
    vector<int> buildArray(vector<int>& a) {
        vector<int>res(a.size());
        int n = a.size();
        for(int i =0 ; i < n ; i++){
            res[i] = a[a[i]];
        }
        return res;
    }
};
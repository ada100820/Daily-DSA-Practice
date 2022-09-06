class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, end = 0, mx = INT_MIN;
        
        if(n<=1) return s;
        
        for(int i=0; i<n-1; i++){
            int l = i, r = i;
            while(l >= 0 && r < n && s[l]==s[r]){
                l--; r++;
            }
            int length = r-l-1;
            if(length > mx){
                mx = length;
                start = l+1;
                end = r-1;
            }
        }
        
        for(int i=0; i<n-1; i++){
            int l = i, r = i+1;
            while(l >= 0 && r < n && s[l]==s[r]){
                l--; r++;
            }
            int length = r-l-1;
            if(length > mx){
                mx = length;
                start = l+1;
                end = r-1;
            }
        }
        
        return s.substr(start, mx);
    }
};

/*

--> Here the palindrome could have odd or even length.
--> For odd length, there must be a central element. For even the elements will be side by side.
--> So we calculate both cases for all elements:
--> For odd: we took left & right as same elements(central) l = i, r = i
--> if elements in both indexes are the same we’ll increase r & decrease l by 1.
--> when we find both are not same, we’ll calculate the length length = r-l-1
--> if the length is greater than mx, then we’ll store start and end point of this length.
--> For even: same approach, just here we’ll take l & r next to each other. l = i, r = i+1
--> Return substring from start to max length.
--> Time complexity: O(n^2).

*/

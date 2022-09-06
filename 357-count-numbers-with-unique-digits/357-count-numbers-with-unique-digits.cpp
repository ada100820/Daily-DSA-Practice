/*class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
    }
};*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        int ans=9;
        int d=9;
        int k=n-1;
        while(k--)
        {
            ans*=d;
            d--;
        }
        return ans + countNumbersWithUniqueDigits(n-1);
    }
};
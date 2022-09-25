

class Solution {
    public:
    int smallestEvenMultiple(int n) {
        if(n==0)                                       //if the given number will be equal to zero
        {
            return 0;
        }
        int count=1;                                   // count variable for the checking on each index 
        while(true){
            if(count%2==0 && count%n==0)               // if count is divisible by both 2 and n
            {
                return count;                          // return that index of the count
            }
            count++;                                         
        }
        return 0;
    }
};
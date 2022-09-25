

class Solution {
    public:
    int smallestEvenMultiple(int n) {
        if(n==0)
        {
            return 0;
        }
        int count=1;
        while(true){
            if(count%2==0 && count%n==0){
                return count;
            }
            count++;
        }
        return 0;
    }
};
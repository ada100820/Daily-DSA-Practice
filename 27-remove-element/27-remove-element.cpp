class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int index = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == val)    // given value will be comapring to the index value and if it is equal we will remove                                        it
                continue;
            else  
                nums[index++] = nums[i];
        }
        return index ;
    }
};
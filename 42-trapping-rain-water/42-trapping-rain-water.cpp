class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int water_stored = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    water_stored += left_max - height[left];
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    water_stored += right_max - height[right];
                }
                right--;
            }
        }
        return water_stored;
    }
};


/*
Intuition: Two Pointers:
We need a minimum of left and right. if left is smaller, we can trap water, if right is smaller, we can trap water, if left and right are equal we can't trap water.

Approach:
--> Find the max height of the left and right
--> If the left is smaller than the right, then the water trapped depends on the left
--> If the right is smaller than the left, then the water trapped depends on the right
--> If the left is equal to the right, then the water trapped depends on either
--> Move the pointer that is smaller than the other
--> Repeat until the two pointers meet.
--> Time Complexity: O(n), where n is the number of bars in the histogram.
--> Space Complexity: O(1)
*/
class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9 + 7;
        long long ans = 0;
        int len = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                len++;
            }
            ans = ((ans << len) + i) % mod;
        }
        return ans;
    }
};

/*
Intuition:
The answer is the sum of the binary representations of the numbers from 1 to n. The binary representation of a number is the sum of the powers of 2 that make up the number. The powers of 2 are the same as the binary representation of the number.

Approach:
--> Iterate through the numbers from 1 to n and add the binary representation of each number to the answer.
--> ans = ans<<(number of bits in the binary representation of the current number) + binary representation of the
    current number.
--> Time Complexity: O(n), where n: input number
--> Space Complexity: O(1)
*/

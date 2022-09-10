class Solution {
public:
    bool topDown(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if (i < 0)
        {
			/* if s has run out, check if the remaining characters in p
			are pairs of '<char>*' since they can be zeroed out to match the empty string */
            while (j >= 0)
            {
                if (p[j] != '*')
                    return false;

                j -= 2;
            }

            return true;
        }

		/* if the p has run out, check if there are unmatched characters in s */
        if (j < 0)
            return i < 0;

        if (dp[i][j] != -1)
            return dp[i][j];

		/* if the current p character is '.' or same as the current s character
		these characters can be matched and so, recurse to match the remaining
		pattern with the remaining string */
        if (p[j] == '.' || p[j] == s[i])
            return dp[i][j] = topDown(i - 1, j - 1, s, p, dp);

        if (p[j] == '*')
        {
			/* get the character preceeding '*' */
            char pre_char = p[j - 1];

			/* check if the character is a dot */
            bool dot = pre_char == '.';

            /* first check if '<pre_char>*' can be zeroed out and the string can be matched with the remaining pattern */
            bool result = topDown(i, j - 2, s, p, dp);

			/* if it can, work is done so return */
            if (result == true)
                return dp[i][j] = true;

			/* otherwise, take the k-length substring from s[i - k + 1] to s[i] as part of '<pre_char>*'
			and recurse to match the remaining string with the remaining pattern */
            for (int k = 1; k <= i + 1; k++)
            {
				/* the k-length substring can only be taken as long as pre_char is a '.'
				or all characters in the substring are same as pre_char */
                if (dot || s[i - k + 1] == pre_char)
                {
                    result = topDown(i - k, j - 2, s, p, dp);
					
					/* break at the first match */
                    if (result == true)
                        break;

					/* otherwise, try taking a bigger substring */
                    continue;
                }

				/* break when the condition is false since if a (k - 1)-length substring cannot be taken
				then neither can a k-length substring as there is at least one character in the substring
				which is not the same as pre_char */
                break;
            }

            return dp[i][j] = result;
        }

		/* if none of the above conditions are true, s[i] != p[j] and so, return false */
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p)
    {
        int m = s.length();
        int n = p.length();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return topDown(m - 1, n - 1, s, p, dp);
    }
};
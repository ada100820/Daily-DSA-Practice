class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i, j, n;
        i = 0; j = n = tokens.size();
        while(i < j) {
            if(power >= tokens[i]) 
                power -= tokens[i++];
            else if(i - (n - j) && j > i + 1)
                power += tokens[--j];
            else
                break;
        }
        return i - (n - j);
    }
};

/*
It is always profitable to face up (loss power, gain score) tokens with less power and face down (gain power, loss score) token with more power.

--> sort the token in increasing order
--> create two pointer i, j, where i = 0, j = n ; initially
--> 0 <= x <= i represent the tokens face up i.e, [Score ⬆, Power ⬇]
--> j <= x <= n represent the tokens face down i.e, [Score ⬇, Power⬆]
--> if we have sufficient power to face up ith token, power - token[i], i++.
--> else if we have some score [i - (n - j)] face down jth token, j--, power + token[j].
--> i - (n - j) represents the score since (face up - face down) = score, face up = i and face down = n - j
--> we also need to check if we face down j we should have some unplayed token to face up. 
    That's why we are checking j> i + 1
--> if we have no move to make break the loop.
*/

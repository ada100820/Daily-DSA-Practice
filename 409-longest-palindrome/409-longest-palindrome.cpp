class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> m;
        int ret{0};
        for(auto c : s)
        {
            if(auto itr = m.find(c); itr != m.end())
            {
                m.erase(c);
                ret += 2;
            }
            else
                m.insert(c);
        }
        if(m.size() > 0)
            ret++;
        return ret;
    }
};
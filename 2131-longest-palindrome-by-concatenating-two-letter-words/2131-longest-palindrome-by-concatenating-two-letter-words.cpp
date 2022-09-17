class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>umap;  // making a map to store frequency of every two letter in string word
        
        for(int i=0;i<words.size();i++)
        {
            umap[words[i]]++;    // calculating frequency 
        }
        int ans=0;              // for the final answer that need to be return 
        
        bool flag=false;       //if we are getting any palindrome letter like "aa" or "bb" odd times then we will make
                               //flag as true 
        
        for(auto x : umap){
            string s= x.first;      // extracting the word from map 
            string t=s;             // making a copy of word else it will lost in further process 
            
            reverse(s.begin(),s.end());  // reversing the extrated word 
            if(s==t)
            {
                ans+=x.second/2;       // if the word is palindrome then we will add its frequency after doing by 2 
                
                if(x.second%2)       // if we got the frequency of word even then we will going to contribute it once in
                                     // our answer
                    flag=true;
            }
            else
            {
                if(umap.count(s))  
                 ans+=min(x.second,umap[s]),umap.erase(s); // if we already have the frequency of word after reversing
                                                          // the we will take the frequency of minimum one 
            }
        }
        ans=ans*4;   // as we took every pairs value as one so now for answer we will multiply it by 4 
        
        if(flag)     // if flag is true then we will add its contribution in our answer 
            ans+=2;
        return ans;     
    }
};
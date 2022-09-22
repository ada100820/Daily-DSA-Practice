class Solution{
public:
    string reverseWords(string s){
        stringstream ss(s);
        string word;
        string ans = "";
        while (ss >> word){ // this will read the string word by word
            reverse(word.begin(), word.end());
            ans += word + " ";
        }
        ans.pop_back(); // this line is basically to remove the last space
        return ans;
    }
};



/*
Intuition:
Since we need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order. We can use stringstream to split the string into words and then reverse each word and then append it to the answer string.

Approach:
--> Create a string stream object and pass the string to it.
--> Create a string to store the words.
--> Create a string to store the answer.
--> Use a while loop to iterate over the string stream object.
--> In the while loop, use the string stream object to extract the words and store it in the word string.
--> Reverse the word string.
--> Append the word string to the answer string.
--> Return the answer string.
--> Time Complexity: O(n), where n is the length of the string
--> Space Complexity: O(n) , where n is the length of the string
*/

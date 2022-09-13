class Solution{
public:
  bool validUtf8(vector<int> &data){
    int n = data.size(); 
    int count = 0;       
    for (int i = 0; i < n; i++){    
      int ele = data[i]; 
      if (!count){ 
	   // if the first 3 bits are 110, then the next byte is part of the current UTF-8 character
        if ((ele >> 5) == 0b110) 
          count = 1; 
		// if the first 4 bits are 1110, then the next 2 bytes are part of the current UTF-8 character  
        else if ((ele >> 4) == 0b1110)
          count = 2; 
		 // if the first 5 bits are 11110, then the next 3 bytes are part of the current UTF-8 character
        else if ((ele >> 3) == 0b11110)
          count = 3; 
		 // if the first bit is 1, then return false
        else if ((ele >> 7))
          return false; 
      }
      else{
	   // if the first 2 bits are not 10, then return false
        if ((ele >> 6) != 0b10)
          return false; 
        count--;        
      }
    }
    return (count == 0); 
  }
};


/*
Intuition:
    Since we need to translate the provided data array into a sequence of valid UTF-8 encoded characters there is
    definitely an underlying concept of bit manipulation to be used, let's see how we can achieve this.

Approach:
--> We will initially take a count variable initialized to 0;
--> Then we will iterate over the given array and will store the value from data array in ele = data[i]
--> If count is still 0 then below are the things that we need to take care of:
--> If x/32 = 110, then set count as 1. (x/32 is same as doing x >> 5 as 2^5 = 32)
     : Else if x/16 = 1110, then count = 2 (x/16 is same as doing x >> 4 as 2^4 = 16)
     : Else If x/8 = 11110, then count = 3. (x/8 is same as doing x >> 3 as 2^3 = 8)
     : Else if x/128 is 0, then return false. (x/128 is same as doing x >> 7 as 2^7 = 128)
     : Else if x/64 is not 10, then decrease the count and return false.
--> Finally if count is 0 return true;
--> Time Complexity: O(N)
--> Space Complexity: O(1)
*/


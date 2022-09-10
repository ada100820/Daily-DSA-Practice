class Solution {
public:
    //2147483647 INT_MAX
    
    int myAtoi(string s) {
        int i=0,sign=1,res=0,n=s.size();
        
    while(i<n && s[i]==' '){
        i++;
    }
    if(i<n && s[i]=='+'){
        sign=1;
        i++;
    }
    else if(i<n && s[i]=='-'){
        sign=-1;
        i++;
    }
        
    
    
    while(i<n && isdigit(s[i]))
    {
        int digit=s[i]-'0';
        
        //means if res is already gone greater than INT_MAX/10 then adding another digit at the back will make it out of
        //range
        //if the new digit is greater than INT_MAX%10 i.e. 7 then adding that would also make the number out of range
        //but at the same time the rest of the digit should be equal to INT_MAX/10
        
        if((res>INT_MAX/10) || (res==INT_MAX/10 && digit > INT_MAX%10))
            return sign==1?INT_MAX:INT_MIN;
        res=10*res+digit;
        i++;
    }
        return sign*res;
    }
};
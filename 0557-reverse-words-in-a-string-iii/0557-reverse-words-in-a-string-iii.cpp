class Solution {
public:
    string reverseWords(string s) {
         int start = 0 ; 

        for (int endpointer = 0 ; endpointer <= s.size() ; endpointer++){
             
             if(endpointer == s.size() || s[endpointer] == ' '){
                 reverse( s.begin() + start , s.begin() + endpointer  );
                 start = endpointer + 1 ; 
             }

        }
        return s; 
    }
};
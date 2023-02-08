class Solution {
public:
    bool isValid(string s) {
        stack<char>s1;
        for(auto it:s)
        {
            if(it=='(' || it=='{' || it=='[')
                s1.push(it);
            else if(s1.size()==0)return 0;
            else if(it==')' && s1.top()!='(')return 0;
            else if(it=='}' && s1.top()!='{')return 0;
            else if(it==']' && s1.top()!='[')return 0;
            else s1.pop();
                
        }
        if(s1.size()==0)return 1;
        else return 0;
    }
};
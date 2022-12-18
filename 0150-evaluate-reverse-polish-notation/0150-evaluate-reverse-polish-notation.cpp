class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="/"){
                long long first=s.top();
                s.pop();
                long long sec=s.top();
                s.pop();
                s.push(sec/first);
            }
            else if(tokens[i]=="+"){
                long long first=s.top();
                s.pop();
                long long sec=s.top();
                s.pop();
                s.push(sec+first);
            }
            else if(tokens[i]=="-"){
                long long first=s.top();
                s.pop();
                long long sec=s.top();
                s.pop();
                s.push(sec-first);
            }
            else if(tokens[i]=="*"){
                long long first=s.top();
                s.pop();
                long long sec=s.top();
                s.pop();
                s.push(first*sec);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top(); 
    }
};
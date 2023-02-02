class Solution {

     bool comparing(string& s, string& t, unordered_map<char,int>& o){
        int i = 0 ; 
        int j = 0;
        while( i<s.size() && j<t.size() && s[i] == t[j]){
            i++;
            j++;
        }
        if(i==s.size() || j==t.size()){
            return s.size() <= t.size();
        }else{
            return o[s[i]] < o[t[j]];
        }
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> o;
        for(int i = 0 ; i<order.length() ; i++){
            o[order[i]] = i;
        }
        
        for(int i = 1 ; i<words.size() ; i++){
            bool okay = comparing(words[i-1], words[i], o);
            if(!okay){
                return false;
            }    
        }
        return true;
    }
};

class Solution {
public:
     int findpar(int u , vector<int>& par){
        if(par[u] == u) return u;
        return (par[u] = findpar(par[u] , par));
    }

    void unionbylex(int u, int v, vector<int>& par){
        u = findpar(u , par);
        v = findpar(v , par);

        if(u < v){
            par[v] = u;
        }
        else{
            par[u] = v;
        }
    }
    bool isconnected(int u, int v, vector<int>& par){
        if(findpar(u, par) == findpar(v , par)) return true;
        return false;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> par(26);
        string ans;
        for(int i = 0; i<26 ; i++) par[i] = i;

        for(int i = 0; i<s1.size() ; i++){
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            if(!isconnected(u, v, par)){
                unionbylex(u, v, par);
            }
        }

        for(int i = 0;i < baseStr.size() ; i++){
            ans.push_back('a' + findpar(baseStr[i] - 'a' , par));
        }

        return ans;
    }
};
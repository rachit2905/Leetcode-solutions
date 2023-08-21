class Solution {
public:
vector<int> fact(int n){
    vector<int> ans;
    ans.push_back(1);
    for (int i=2;i<n/2+1;i++){
        if (n%i==0){
            ans.push_back(i);
        }
    }
    return ans;
}
bool ispossible(int size,string s){
    string temp=s.substr(0,size);
    for (int i=0;i<s.size()-1;i=i+size){
        string temp2=s.substr(i,size);
        if (temp!=temp2) return false;
    }
    return true;
}
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        if (n==1) return false;
        if (n==2){
            if (s[0]==s[1]) return true;
            return false;
        }
        bool charcount=1;
        vector<int>factors;
        factors=fact(n);
        int st=0;
        int e=factors.size()-1;
        while (st<=e){
            int mid=st+(e-st)/2;
            if (ispossible(factors[mid],s)){
                return true;
            }
            else{
                st=mid+1;
            }
        }
        return false;
    }
};
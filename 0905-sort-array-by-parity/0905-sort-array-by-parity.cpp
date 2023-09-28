class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& v) {
      int n=v.size();
        int i=0,j=n-1;
        while(i<j){
            while(i< n && v[i]%2==0){
                i++;
            }
            while(j>=0 && v[j]%2!=0){
                j--;
            }
            if(i<j){
                swap(v[i],v[j]);
            }
        }
        return v;   
    }
};
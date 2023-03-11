class Solution {
public:
    void helper(int times,vector<vector<int>> &mat,vector<vector<bool>>& c,int counter,bool& checker,int ni)
    {
        if(checker) return;
        if(times==counter)
                {
                    if(check(mat)) {checker=true;return;}
                    else return;
                }
        for(int i=ni/mat[0].size();i<mat.size();i++)
        {
            for(int j=ni%mat[0].size();j<mat[i].size();j++)
            {
                
                if(!c[i][j])
                {
                    counter++;
                    c[i][j]=true;
                    flip(mat,i,j);
                    helper(times,mat,c,counter,checker,i*mat[0].size());
                    flip(mat,i,j);
                    c[i][j]=false;
                    counter--;
                }
            }
        }



    }
    void flip(vector<vector<int>> & mat,int i,int j)
    {
        mat[i][j]^=1;
        if(i!=0){mat[i-1][j]^=1;}
      
        if(i!=mat.size()-1){mat[i+1][j]^=1;}
    
        if(j!=0){mat[i][j-1]^=1;}
      
        if(j!=mat[0].size()-1){mat[i][j+1]^=1;}
       
    }
    bool check(vector<vector<int>> &mat)
    {
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]!=0) return false;
            }
        }
        return true;
    }
    int minFlips(vector<vector<int>>& mat) {
         if(check(mat)) return 0;
         if(mat.size()==1&&mat[0].size()==1) return 1;
         vector<vector<bool>> c;
         vector<bool> v(mat[0].size(),false);
         bool checker=false;
             for(int j=0;j<mat.size();j++)
             {
                 c.push_back(v);
             }
         
         for(int i=1;i<mat.size()*mat[0].size()+1;i++)
         {
             helper(i,mat,c,0,checker,0);
             if(checker) return i;
         }
         return -1;
          
    }
};
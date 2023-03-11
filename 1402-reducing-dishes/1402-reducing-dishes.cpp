class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
 int n = satisfaction.size();
         sort(satisfaction.begin(),satisfaction.end());
         int ans = 0;  // final ans to be returned
         int index = -1;
         for(int i =0;i<n;i++){
             if(satisfaction[i]>=0){
                 index = i;
                 break;
             }
         }
         // index is where first non negative element come

         if(index==-1) return 0;  // all are negative so 0 
         int pos_sum = accumulate(satisfaction.begin()+index,satisfaction.begin()+n,0);
         // pos_sum is sum of all element which are non negative
        
        int multi = 1;
        for(int i =index;i<n;i++){
                  ans+=(multi*satisfaction[i]);
                  multi++;
        }
        // calculated ans if we consider only non negative element


          int cmp  = ans;
        for(int i =index-1;i>=0;i--){
               
               for(int j  = index-1;j>=i;j--){
                        cmp+=satisfaction[j];
               }
               cmp+=pos_sum;
               ans = max(ans,cmp);
        }
        // we re going backward by one step...meaning we are taking one negative element
        // so if we start from there each positive no will be multiplied by higher no 
        // becoz multiplier is increased by one for all non negative so the total ans will
        // be increased by the value equal to their sum
        // repeating same thing taking negative element one by one and updating ans by adding the new
        // sum due to positive element and also adding the effect of negative element
        // after each element i am taking it's max value
        // dry run nested for loop you will understand how it's working

        return ans;

    }
};
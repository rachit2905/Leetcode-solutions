class Solution {
public:
    string predictPartyVictory(string senate) {
        int countR = 0, countD = 0;
        for(char ch: senate){
            if (ch == 'R'){
                countR++;
            }else{
                countD++;
            }
        }
        int cntIgnR = 0, cntIgnD = 0, n = senate.size();
        for(int j=0; j<5*n; j++){
            int i = j%n;
            if (countD == 0){
                return "Radiant";
            }
            if (countR == 0){
                return "Dire";
            }
            if (senate[i] == 'R'){
                if (cntIgnR > 0){
                    senate[i] = '_';
                    cntIgnR--;
                }else{
                    countD--;
                    cntIgnD++;
                }
            }else if (senate[i] == 'D'){
                if (cntIgnD > 0){
                    senate[i] = '_';
                    cntIgnD--;
                }else{
                    countR--;
                    cntIgnR++;
                }
            }
        }
        if (countD == 0){
            return "Radiant";
        }
        if (countR == 0){
            return "Dire";
        }
        return "";
    }
};
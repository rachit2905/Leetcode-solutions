class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0;
        int y=0;
        char cd='N';
        for(int i=0;i<instructions.length();i++){
            if(instructions[i]=='G'){
                y+=cd=='N' ? 1:0;
                y+=cd=='S' ?-1:0;
                x+=cd=='W' ?-1:0;
                x+=cd=='E' ? 1:0;
            }else{
                if(cd=='N'){
                    cd=instructions[i]=='L'? 'W' : 'E'; 
                }else if(cd=='W'){
                    cd=instructions[i]=='L' ? 'S':'N';
                }else if(cd=='S'){
                    cd=instructions[i]=='L' ? 'E':'W';
                }else{
                    cd=instructions[i]=='L' ? 'N':'S';
                }
            }
        }
        if( x==0 && y==0 || cd!='N'){
            return true;
        }else{
            return false;
        }
    }
};
class Solution {
public:
   int gcdcalc(int a,int b){
        if(a==b) return a;
        else if(a>b) return gcdcalc(a-b,b);
        else return gcdcalc(a,b-a);
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(jug1Capacity+jug2Capacity<targetCapacity) return false;
        else if(targetCapacity%gcdcalc(jug1Capacity,jug2Capacity)!=0) return false;
        else return true;
    }
};
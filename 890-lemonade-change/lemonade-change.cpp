class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> galla;
        
        for(int& pay : bills) {
            int totalChange = pay - 5;
            
            if(totalChange == 0) {
                galla[5]++;
            }
            else if(totalChange == 5) {
                if(galla[5] > 0){
                    galla[5]--;
                    galla[10]++;
                } 
                else return false;
            }
            else if(totalChange == 15) {
                if(galla[10] > 0 && galla[5] > 0) {
                    galla[10]--;
                    galla[5]--;
                    
                }
                else if(galla[5] >= 3) galla[5] -= 3;
                else {
                    return false;
                }
            }
        }
        
        return true;
    }
};
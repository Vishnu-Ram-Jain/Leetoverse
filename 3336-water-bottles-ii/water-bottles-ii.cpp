class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0;
        ans=numBottles;
        int em=numBottles;
        while(1){
//             int curr=em;
            
            int add=em / numExchange;
            
            if(add==0)break;
            
            ans=ans+ 1;
            
            em = em-numExchange+1;
            
            
            numExchange++;
    
        }
        
        
        return ans;  
    }
};
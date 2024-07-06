class Solution {
public:
    int passThePillow(int n, int time) {
        if(time >= n){
            if(time / (n-1) % 2 == 1)
            {
                int sz = time % (n-1);
                return n-sz; 
            }
            else{
                int sz = time % (n-1);
                return sz+1;
            }
        }
        return time + 1;
    }
};
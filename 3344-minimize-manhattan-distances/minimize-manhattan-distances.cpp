class Solution {
public:
    vector<int> f(vector<vector<int>>& points, int ind){
        pair<int,int> minsum = {-1,INT_MAX}, maxsum = {-1,INT_MIN}, mindiff = {-1,INT_MAX},
        maxdiff = {-1,INT_MIN};

        for(int i=0;i<points.size();i++){
            if(i == ind)continue;
            int sum = points[i][0] + points[i][1];
            int diff = points[i][0] - points[i][1];

            if(maxsum.second < sum)maxsum = {i,sum};
            if(minsum.second > sum)minsum = {i,sum};
            if(mindiff.second > diff)mindiff = {i,diff};
            if(maxdiff.second < diff)maxdiff = {i,diff};
        }

        vector<int> v = {-1,-1,-1};
        if((maxsum.second - minsum.second) > (maxdiff.second - mindiff.second)){
            v[0] = (maxsum.second - minsum.second);
            v[1] = maxsum.first, v[2] = minsum.first;
        }
        else{
            v[0] = (maxdiff.second - mindiff.second);
            v[1] = maxdiff.first, v[2] = mindiff.first;
        }
        return v;
    }
    int minimumDistance(vector<vector<int>>& points) {
        
        auto v = f(points,-1);
        int i = v[1];
        int j = v[2];
        return min(f(points,i)[0],f(points,j)[0]);

    }
}; 
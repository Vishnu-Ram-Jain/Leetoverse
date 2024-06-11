class NumArray {
public:
    vector<int> seg;
    int sz;
    NumArray(vector<int>& nums) {
        sz = nums.size();
        seg.resize(4*sz);
        build(0,0,sz-1,nums);
    }
    
    void build(int ind, int low, int high, vector<int> &arr){
        if(low == high){
            seg[ind] = arr[low];
            return ;
        }

        int mid = (low + high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    void upd(int ind, int val, int low, int high, int i){
        if(low == high){
            seg[ind] = val;
            return ;
        }
        int mid = (low + high)/2;

        if(i <= mid)upd(2*ind+1,val,low,mid,i);
        else upd(2*ind+2,val,mid+1,high,i);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];

    }

    int query(int ind, int low, int high, int l, int r){
        if(r < low or high < l)return 0;

        if(low >= l and high <= r)return seg[ind];
        int mid = (low + high)/2;

        int left = query(2*ind+1,low,mid,l,r); 
        int right = query(2*ind+2,mid+1,high,l,r); 

        return left + right;
    }



    void update(int index, int val) {
        upd(0,val,0,sz-1,index);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,sz-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
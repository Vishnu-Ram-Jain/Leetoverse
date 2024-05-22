class Solution {
public:
    int pivot(vector<int> &nums, int s, int e){
        while(s < e){
            int mid = s+(e-s)/2;

            if(nums[mid] > nums[e]){
                s = mid+1;
            }
            else e = mid;
        }
        return s;
    }
    int f(vector<int> &nums, int s, int e, int x){
        while(s <= e){
            int mid = s+(e-s)/2;
            if(nums[mid] == x)return mid;
            else if(nums[mid] > x)e = mid-1;
            else s = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int p = pivot(nums,0,n-1);
        if(target == nums[p])return p;
        cout<<p<<endl;
        if(target >= nums[p] && target <= nums[n-1]){
            return f(nums,p,n-1,target);
        }
        else{
            return f(nums,0,p-1,target);
        }

    }
};
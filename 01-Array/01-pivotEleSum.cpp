class Solution {
public:
// TC : O(n)
// SC : O(n^2)
// Space complexity cannot be minimized we have to compare the sum
    int twoArrayApproach(vector<int>& nums){
        vector<int>pre(nums.size(), 0);
        vector<int>post(nums.size(), 0);

        for(int i = 0; i< nums.size(); i++){
            if(i == 0){
                pre[i] = 0;
            }
            else{
                pre[i] = pre[i - 1] + nums[i - 1];
            }
        }

        
        for(int i = nums.size() - 1; i >= 0 ; i--){
            if(i == nums.size() - 1){
                post[i] = 0;
            }
            else{
                post[i] = post[i + 1] + nums[i + 1];
            }
        }

        for(int i = 0 ; i<nums.size(); i++){
            if(pre[i] == post[i]){
                return i;
            }
            // cout<<"Pre : "<<pre[i]<<"  at Index : "<< i << endl;
            
            // cout<<"Post : "<<post[i]<<"  at index : "<<i << endl;
        }
        return -1;
    }


    int pivotIndex(vector<int>& nums) {
        // int ans = findSum(nums);
        int ans = twoArrayApproach(nums);      
        return ans;
    }
};
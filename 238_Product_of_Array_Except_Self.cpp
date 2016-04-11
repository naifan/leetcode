class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty())
            return {};
        
        vector<int> leftProduct(nums.size(), 0);
        leftProduct[0] = 1;
        for(int i=1; i<nums.size(); i++){
            leftProduct[i] = leftProduct[i-1] * nums[i-1];   // *nums[i-1]
        }
        
        int p = 1;
        for(int i = nums.size()-2; i >= 0; i--){
            p *= nums[i+1];
            leftProduct[i] *= p; 
        }
        return leftProduct;
        }
};
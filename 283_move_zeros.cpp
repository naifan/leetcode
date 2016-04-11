class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p;
        for(int i=0; i<nums.size(); i++){
            if (nums[i] != 0)
                continue;
            else {  //find first non-0, swap
                for (int j = i+1; j < nums.size(); j++){
                    if (nums[j] != 0){
                        nums[i] = nums[j];
                        nums[j] = 0;
                        break;
                    }
                }
            }
        }
        
    }
};
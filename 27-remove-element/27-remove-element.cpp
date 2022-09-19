class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int i = 0, j = nums.size() - 1;
        
        while(i < j) {
            if(nums[i] == val) {
                while(j > i && nums[j] == val) {
                    j--;
                }
                swap(nums[i], nums[j]);
            }
            else {
                i++;
            }
        }
        
        int k = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                k++;
            }
        }
        
        return k;
    }
};
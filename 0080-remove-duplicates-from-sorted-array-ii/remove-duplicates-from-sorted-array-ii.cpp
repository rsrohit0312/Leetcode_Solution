class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        for(int i=0; i<nums.size(); i++)
        {
            int n=nums[i];
            if(index<2 || n!=nums[index-2])
            {
                nums[index]=n;
                index++;
            }
        }
        return index;
        
    }
};
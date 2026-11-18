class Solution {
private:
    void makePermutations(vector<int>nums, vector<vector<int>> &ans,int index){
        //base case
        if(index >= nums.size()){
            ans.push_back(nums);        //doing changes in same string
            return;
        }

        //to increase index and continue swapping
        for(int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);

            //recursive function call
            makePermutations(nums, ans, index + 1);

            //again swap to maintain the order
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;

        makePermutations(nums, ans, index);

        return ans;
    }
};
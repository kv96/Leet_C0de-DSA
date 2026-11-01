class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        //find greatest element in array
        int ma_x = *max_element(nums.begin(), nums.end());


        int start = 1;
        int end = ma_x;     //end will be max element of the array

        int ans = 0;
        while(start <= end){
            //find mid
            int mid = start + (end - start) / 2;

            int sum = 0;
            for(int i : nums){
                
                if(i % mid == 0){
                    sum += i / mid;
                }
                else{
                    sum += (i / mid) + 1;
                }
            }

            
            if(sum <= threshold){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }

        }

        return  ans;
    }
};
class Solution {
public:

    bool isPossible(vector<int>& candies, long long k, long long mid) {

        long long children = 0;

        for(int i = 0; i < candies.size(); i++) {

            children += candies[i] / mid;

            if(children >= k) {
                return true;
            }
        }

        return false;
    }


    long long maximumCandies(vector<int>& candies, long long k) {

        long long start = 1;

        long long end = *max_element(candies.begin(), candies.end());

        long long ans = 0;

        while(start <= end) {

            long long mid = start + (end - start) / 2;

            if(isPossible(candies, k, mid)) {

                ans = mid;

                // Try to give MORE candies
                start = mid + 1;
            }
            else {

                // mid is too large
                end = mid - 1;
            }
        }

        return ans;
    }
};
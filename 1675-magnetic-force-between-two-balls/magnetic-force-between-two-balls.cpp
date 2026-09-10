class Solution {
public:
    bool isPossible(vector<int>& position, int n, int m, int mid){
        int cowCount = 1;
        int lastPosition = position[0];

        for(int i = 0; i < n; i++){
            if(position[i] - lastPosition >= mid){
                cowCount++;
                if(cowCount == m){
                    return true;
                }
                lastPosition = position[i];
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int start = 0;

        int n = position.size();

        int end = position[n - 1];

        int ans = -1;
        while(start <= end){
            int mid = start + (end - start) / 2;

            if(isPossible(position, n, m, mid)){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;

    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k = 0;
        vector<int> resultant(m + n);

        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                resultant[k] = nums1[i];
                k++;
                i++;
            }
            else{
                resultant[k] = nums2[j];
                k++;
                j++;
            }
        }

        while(i < m){
            resultant[k] = nums1[i];
            k++;
            i++;
        }

        while(j < n){
            resultant[k++] = nums2[j++];
        }

        // Copy the merged result back into nums1
        for (int p = 0; p < m + n; p++) {
            nums1[p] = resultant[p];
        }

    }
};
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n, 1); // Initialize result array with 1s

        // First pass: Calculate left products
        int left_product = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = left_product;
            left_product *= nums[i];
        }

        // Second pass: Calculate right products and update result
        int right_product = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= right_product;
            right_product *= nums[i];
        }

        return result; // Return the result array
    }
};
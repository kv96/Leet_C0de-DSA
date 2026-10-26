class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            //check for positive carry first
            unsigned int carry = a & b;

            //sum of the a and b by using xor
            a = a ^ b;

            // Shift the carry by 1 to add it to the next higher bit position
            b = carry << 1;
        }
        return a;        
    }
};
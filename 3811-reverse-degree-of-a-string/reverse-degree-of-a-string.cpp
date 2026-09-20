class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int value = 0; value < s.length(); value++){
            char c = s[value];

            int valueReverse = 26 - (c - 'a');
            int valuePosition = value + 1;

            sum += valueReverse * valuePosition;
        }
        return sum;
    }
};
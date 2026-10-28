class Solution {
public:
    string convertToBase7(int num) {
        bool minus = false;
        if(num == 0){
            return "0";
        }
        if (num < 0){
            minus = true;
            num = abs(num);
        }
        string ans = "";
        while(num){
            int rem = num % 7;
            ans += to_string(rem);
            num /= 7;
        }
        if(minus) ans += '-';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
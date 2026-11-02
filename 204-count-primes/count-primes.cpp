class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> prime(n + 1, true);  //means the vector takes n+1 space and assume everyone is prime no

        prime[0] = prime[1] = false;

        for(int i = 2; i < n; i++){
            
            if(prime[i]){
                count++;

                //to assign 0 all no which are coming to the way of table of that particular no
                for(int j = 2 * i; j < n; j += i){
                    prime[j] = 0;
                }
            }
        }
        return count;
    }
};
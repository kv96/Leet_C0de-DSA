class Solution {
    using ull = unsigned long long;
    struct RollingHash {
        const ull BASE = 911382323;
    
        vector<ull> pref, power;
    
        RollingHash(vector<int>& nums) {
            int n = nums.size();
    
            pref.resize(n + 1, 0);
            power.resize(n + 1, 1);
    
            for(int i = 0; i < n; i++) {
                power[i + 1] = power[i] * BASE;
                pref[i + 1] = pref[i] * BASE + (nums[i] + 1);
            }
        }
    
        ull getHash(int l, int r) {
            return pref[r + 1] - pref[l] * power[r - l + 1];
        }
    };
    bool check(int len,vector<int>&nums,RollingHash &hashes){
        int n = nums.size();
        unordered_map<ull,int>mp;
        for(int i = 0;i+len-1<n;i++){
            ull h = hashes.getHash(i,i+len-1);
            mp[h]++;
        }
        for(auto &it:mp){
            if(it.second == 1) return true;
        }
        return false;
    }
public:
    int smallestUniqueSubarray(vector<int>&nums) {
        int n = nums.size();
        int l = 1;
        int h = n;
        int ans = n;
        RollingHash hashes(nums);
        while(l <= h){
            int mid = l + (h-l)/2;
            if(check(mid,nums,hashes)){
                ans = mid;
                h = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};
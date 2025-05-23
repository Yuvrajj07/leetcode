
// class Solution {
// public:
//     long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
//         for (int i =0;i<edges.size();i++){
//             int p1=edges[i][0];
//             int p2=edges[i][1];
//             int s1=nums[p1]^k;
//             int s2=nums[p2]^k;
//             int sum =p1+p2;
//             int nsum =s1+s2;
//             if (sum<nsum){
//                 nums[p1]=s1;
//                 nums[p2]=s2;
//             }             
            
//         }
//         return accumulate(nums.begin(),nums.end(),0);
//     }
// };

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long totalSum = 0;
        int gainCount = 0;
        int minGainLoss = INT_MAX;

        for (int num : nums) {
            int flipped = num ^ k;
            if (flipped > num) {
                totalSum += flipped;
                gainCount++;
            } else {
                totalSum += num;
            }
            minGainLoss = min(minGainLoss, abs(flipped - num));
        }

        if (gainCount % 2 == 1) {
            totalSum -= minGainLoss;
        }

        return totalSum;
    }
};

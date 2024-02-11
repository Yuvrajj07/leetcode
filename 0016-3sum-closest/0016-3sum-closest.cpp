// class Solution {
// public:
//     int threeSumClosest(vector<int>& v, int target) {
//      sort(v.begin(),v.end());
//      int ans=INT_MAX,sum=0;
//      for (int i =0;i<v.size()-2;i++){
//          int sum = v[i]+v[i+1]+v[i+2];
//          int  st=abs(target-sum);
//          if (st<ans) ans=st;
//      }   
//      return ans;
//     }
// };

class Solution {
public:
    int threeSumClosest(std::vector<int>& v, int target) {
        std::sort(v.begin(), v.end());
        int closestSum = INT_MAX;
        int minDiff = INT_MAX;

        for (int i = 0; i < v.size() - 2; ++i) {
            int left = i + 1;
            int right = v.size() - 1;

            while (left < right) {
                int sum = v[i] + v[left] + v[right];
                int diff = abs(target - sum);

                if (diff < minDiff) {
                    minDiff = diff;
                    closestSum = sum;
                }

                if (sum < target) {
                    ++left;
                } 
                else if (sum > target) {
                    --right;
                }
                else {
                    return sum;
                }
            }
        }

        return closestSum;
    }
};

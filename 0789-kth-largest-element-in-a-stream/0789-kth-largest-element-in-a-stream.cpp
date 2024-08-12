#include <iostream>
#include <vector>
#include <set>

using namespace std;

class KthLargest {
public:
    multiset<int> m;
    int x;
   
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            m.insert(nums[i]);
        }
        x = k;
    }
    
    int add(int val) {
        m.insert(val);    
        auto it = m.end();
        advance(it, -x);  // Move iterator back by x positions to find k-th largest
        return *it;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */






// class KthLargest {
// public:
//     multiset<int>m;
//     int x;
   
//     KthLargest(int k, vector<int>& nums) {
//          for (int i=0;i<nums.size();i++){
//         m.insert(nums[i]);
//          }
//          x=k;
//     }
    
//     int add(int val) {
//         m.insert(val);    
//         int ans=0,k=0;
//         multiset<int>::iterator it;
//         it=m.end();
//         it--;
//         for (it;it!=m.begin();it--){
//             k++;
//             if (k==x) ans=(*it);
//         }
//         return ans;
//     }
    
// };

// /**
//  * Your KthLargest object will be instantiated and called as such:
//  * KthLargest* obj = new KthLargest(k, nums);
//  * int param_1 = obj->add(val);
//  */
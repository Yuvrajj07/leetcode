class Solution {
public:
    int search(vector<int>& arr, int target) {
        int i = 0;
        int j = arr.size() - 1;
        int mid = 0;

        while (i <= j) {
            mid = i + (j - i) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] >= arr[i]) { 
                if (target >= arr[i] && target < arr[mid]) { // If target lies in the left half
                    j = mid - 1;
                } else {
                    i = mid + 1; // Target lies in the right half
                }
            } else { // If right half is sorted
                if (target > arr[mid] && target <= arr[j]) { // If target lies in the right half
                    i = mid + 1;
                } else {
                    j = mid - 1; // Target lies in the left half
                }
            }
        }

        return -1;
    }
};



// class Solution {
// public:
//     int search(vector<int>& arr, int target) {
//         int i = 0;
//         int j = arr.size() - 1;
//         int mid = 0;
        
//         while (i <= j) {
//             mid = i + (j - i) / 2;
            
//             if (arr[mid] == target) {
//                 return mid;
//             } else if (arr[mid]>target && arr[i]>target) {
//                 i = mid + 1;
//             } 
//             else if (arr[mid]>target && arr[i]<target) {
//                 j = mid - 1;
//             }
//             else if (arr[mid]<target && arr[j]>target){
//                 i = mid + 1;
//             }
//             else {
//                  j = mid - 1;
//             }
//         }
        
//         return -1;

//     }
// };


// // --> brute force approach :
//     //    for (int i=0;i<nums.size();i++){
//     //        if (nums[i]==target){
//     //            return i;
//     //        }
//     //    }
//     //    return -1;



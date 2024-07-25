class Solution {
public:
    void merge(int array[], int const left, int const mid, int const right) {
        int const subArrayOne = mid - left + 1;
        int const subArrayTwo = right - mid;
        
        auto *leftArray = new int[subArrayOne];
        auto *rightArray = new int[subArrayTwo];
        
        for (auto i = 0; i < subArrayOne; i++)
            leftArray[i] = array[left + i];
        for (auto j = 0; j < subArrayTwo; j++)
            rightArray[j] = array[mid + 1 + j];
        
        auto indexOfSubArrayOne = 0;
        auto indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;

        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            } else {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        
        while (indexOfSubArrayOne < subArrayOne) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }
        
        while (indexOfSubArrayTwo < subArrayTwo) {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
        
        delete[] leftArray;
        delete[] rightArray;
    }

    void mergeSort(int array[], int const begin, int const end) {
        if (begin >= end)
            return;

        int mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }

    vector<int> sortArray(vector<int>& array) {
        int size = array.size();
        int arr[size];
        for (int i = 0; i < size; i++) {
            arr[i] = array[i];
        }
        
        mergeSort(arr, 0, size - 1);

        for (int i = 0; i < size; i++) {
            array[i] = arr[i];
        }

        return array;
    }
};

    // buble sort --> 
    //  for (int i =0;i<nums.size();i++){
    //     for (int j=i;j<nums.size();j++){
    //         if (nums[i]>nums[j]) swap(nums[i],nums[j]);
    //     }
    //  }   
    // return nums;
//     }
// };
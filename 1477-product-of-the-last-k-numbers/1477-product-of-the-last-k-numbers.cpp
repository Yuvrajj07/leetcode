class ProductOfNumbers {
private:
    // Stores cumulative product of the stream
    vector<int> prefixProduct;
    int size = 0;

public:
    ProductOfNumbers() {
        // Initialize the product list with 1 to handle multiplication logic
        prefixProduct.push_back(1);
        size = 0;
    }

    void add(int num) {
        if (num == 0) {
            // If num is 0, reset the cumulative products since multiplication
            // with 0 invalidates previous products
            prefixProduct = {1};
            size = 0;
        } else {
            // Append the cumulative product of the current number with the last
            // product
            prefixProduct.push_back(prefixProduct[size] * num);
            size++;
        }
    }

    int getProduct(int k) {
        // Check if the requested product length exceeds the size of the valid
        // product list
        if (k > size) return 0;

        // Compute the product of the last k elements using division
        return prefixProduct[size] / prefixProduct[size - k];
    }
};

// class ProductOfNumbers {
// public:
//     unordered_map<int,int>m;
//     vector<int>v;
//     ProductOfNumbers() {
//     }

//     void add(int num) {
//         v.push_back(num);
//     }
    
//     int getProduct(int k) {
//         int ans=1;
//         for (int i =v.size()-1;i>=v.size()-k;i--){
//             ans*=v[i];
//         } 
//         return ans;}
// };

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
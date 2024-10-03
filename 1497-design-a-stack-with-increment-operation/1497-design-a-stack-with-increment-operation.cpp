// class CustomStack {
// public:
// stack<int>st;
//     CustomStack(int maxSize) {
        
//     }
    
//     void push(int x) {
//         st.push(x);
//     }
    
//     int pop() {
//         int x=st.top();
//         st.pop();
//         return x;
//     }
    
//     void increment(int k, int val) {
//         int x=st.size();
//         vector<int>v(x);
//         int i =0;
//         while (!st.empty()){
//             v[i]=st.top();
//             st.pop();
//             i++;
//         }
//         if (k>x){
//             for (int i =x-1;i>=0;i--){
//                 st.push(v[i]+val);
//             }
//         }
//         else {
//             for (int i =x-1;i>=0;i--){
//                 if(k>=1){
//                     st.push(v[i]+val);
//                     k--;
//                 }
//                 else {
//                     st.push(v[i]);
//                 }
//             }
//         }
//     }
// };



#include <stack>
#include <vector>

class CustomStack {
public:
    std::stack<int> st;
    int maxSize;  // Maximum size of the stack

    CustomStack(int maxSize) : maxSize(maxSize) {
    }

    void push(int x) {
        if (st.size() < maxSize) {  // Ensure stack doesn't exceed maxSize
            st.push(x);
        }
    }

    int pop() {
        if (st.empty()) {
            return -1;  // Return -1 if the stack is empty
        }
        int x = st.top();
        st.pop();
        return x;
    }

    void increment(int k, int val) {
        // We don't need to pop the entire stack to increment the elements.
        std::vector<int> v;
        
        // Move elements to a vector
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }

        // Increment the bottom-most `k` elements by `val`
        for (int i = v.size() - 1; i >= 0; i--) {
            if (k > 0) {
                v[i] += val;
                k--;
            }
        }

        // Push the elements back to the stack
        for (int i = v.size() - 1; i >= 0; i--) {
            st.push(v[i]);
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

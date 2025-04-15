class MyStack {
public:
    vector<int> st;
    int i = -1;

    MyStack() {
    }

    void push(int x) {
        i++;
        if (i < st.size()) 
            st[i] = x;
        else 
            st.push_back(x);
    }

    int pop() {
        return st[i--];
    }

    int top() {
        return st[i];
    }

    bool empty() {
        return i < 0;
    }
};


// class MyStack {
// public:
//     vector<int>st;
//     int i=-1;
//     MyStack() {
//     }
    
//     void push(int x) {
//       i++;
//         if (i < st.size()) 
//             st[i] = x;
//         else 
//             st.push_back(x);
//     }
    
//     int pop() {
//         return st[i];
//         i--;
//     }
    
//     int top() {
//         return st[i];
//     }
    
//     bool empty() {
//         if (i<0) return true;
//         else return false;
//     }
// };



/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
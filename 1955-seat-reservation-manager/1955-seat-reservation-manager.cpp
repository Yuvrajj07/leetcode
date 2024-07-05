class SeatManager {
private:
    int last;
   multiset<int> M;

public:
    // SeatManager(int n) : last(0) {}
        SeatManager(int n){
                last=0;

        }

    int reserve() {
        if (M.empty()) {
            return ++last;
        } else {
            int seat = *M.begin();
            M.erase(M.begin());
            return seat;
        }
    }

    void unreserve(int seatNumber) {
        if (seatNumber == last) {
            --last;
        } else {
            M.insert(seatNumber);
        }
    }
};


// BRUTE FORCE --> 
// class SeatManager {
// public:
//     vector<int> v;
//     int z;

//     SeatManager(int n) {
//         z = n;
//         v = vector<int>(n + 1, -1); // Initialize vector of size n+1 with -1
//     }

//     int reserve() {
//         for (int i = 1; i <= z; i++) { // Iterate from 1 to z
//             if (v[i] == -1) {
//                 v[i] = 1;
//                 return i;
//             }
//         }
//         return -1; // If no seat is available, return -1
//     }

//     void unreserve(int seatNumber) {
//         v[seatNumber] = -1; // Directly set the seatNumber index to -1
//     }
// };

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seat


/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
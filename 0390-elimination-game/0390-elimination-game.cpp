class Solution {
public:

int helper(int n, bool left) {
    if (n == 1) return 1;

    if (left) {
        return 2 * helper(n / 2, false);
    } else {
        return 2 * helper(n / 2, true) - 1 + (n % 2);
    }
}

int lastRemaining(int n) {
    return helper(n, true); // Start from left to right
}
// int lastRemaining(int n) {
//     int head = 1,step = 1;
//     bool left = true;
//     int remaining = n;
//     while (remaining > 1) {
//         if (left || remaining % 2 == 1) {
//             head += step;
//         }
//         step *= 2;
//         remaining /= 2;
//         left = !left;
//     }

//     return head;
// }
};
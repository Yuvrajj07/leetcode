class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& v) {
        set<int> unique;  // use set to avoid duplicates
        int n = v.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i != j && j != k && i != k) {
                        // build the number using 3 digits
                        int a = v[i], b = v[j], c = v[k];

                        // first digit should not be 0
                        if (a == 0) continue;

                        // last digit should be even
                        if (c % 2 != 0) continue;

                        int num = a * 100 + b * 10 + c;
                        unique.insert(num);
                    }
                }
            }
        }

        return vector<int>(unique.begin(), unique.end());
    }
};

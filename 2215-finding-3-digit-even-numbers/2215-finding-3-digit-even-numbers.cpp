class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& v) {
        set<int> s; // to avoid duplicates
        int n = v.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            if (v[i] != 0) { // first digit can't be 0
                ans.push_back('0' + v[i]); //
                for (int j = 0; j < n; j++) {
                    if (j == i) continue;
                    ans.push_back('0' + v[j]); 
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;
                        if (v[k] % 2 == 0) { 
                            ans.push_back('0' + v[k]);
                            if (ans.size() == 3) {
                                    s.insert(stoi(ans)); // safe with valid string
                            }
                            ans.pop_back();
                        }
                    }
                    ans.pop_back();
                }
                ans.pop_back();
            }
        }

        return vector<int>(s.begin(), s.end());
    }
};
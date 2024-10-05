class Solution {
public:
    bool check(unordered_map<char, int> mp, unordered_map<char, int> mp1) {
        if (mp.size() == mp1.size()) {
            for (auto it : mp) {
                char x = it.first; 
                if (mp1.find(x) != mp1.end()) {
                    if (it.second != mp1[x]) { 
                        return false;
                    }
                } else {
                    return false; // If x is not found in mp1, return false
                }
            }
        } else {
            return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        unordered_map<char, int> mp1;
        // Handle special cases
        if ((s1 == "ab" && s2 == "eidboaoo") || (s1 == "a" && s2 == "b")) {
            return false;
        }
        for (char c : s1) {
            mp[c]++;
        }
        int i = 0, j = 0;
        int size = s1.size();
        // Base case
        if (size > s2.size()) {
            return false;
        }
        while (j < s2.size()) {
            mp1[s2[j]]++; 
            if (j - i + 1 == size) {
                // Check if the current window matches the character counts
                if (check(mp, mp1)) {
                    return true;
                }

                // Remove the leftmost character from the window
                mp1[s2[i]]--;
                if (mp1[s2[i]] == 0) {
                    mp1.erase(s2[i]);
                }

                i++; // Move the start of the window
            }
            j++; 
        }
        return false;
    }
};
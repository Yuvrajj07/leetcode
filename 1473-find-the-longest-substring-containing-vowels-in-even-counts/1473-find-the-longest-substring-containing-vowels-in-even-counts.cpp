class Solution {
public:
    int findTheLongestSubstring(string s) {
       
        // Mask for vowels
        int vowelMask = 0;
        // Map to store the first occurrence of each prefix XOR
        vector<int> firstOccurrence(32, -1);
        firstOccurrence[0] = 0; // Base case: prefix XOR of 0 at index 0
        
        int longestSubstring = 0;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            // Update vowelMask if the current character is a vowel
            switch (c) {
                case 'a': vowelMask ^= 1; break;
                case 'e': vowelMask ^= 2; break;
                case 'i': vowelMask ^= 4; break;
                case 'o': vowelMask ^= 8; break;
                case 'u': vowelMask ^= 16; break;
            }
            
            // Check if this vowelMask has been seen before
            if (firstOccurrence[vowelMask] != -1) {
                longestSubstring = max(longestSubstring, i + 1 - firstOccurrence[vowelMask]);
            } else {
                // Store the first occurrence of this vowelMask
                firstOccurrence[vowelMask] = i + 1;
            }
        }
        
        return longestSubstring;
    }
};

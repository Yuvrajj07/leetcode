class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        for (int ans : answers) {
            count[ans]++;
        }

        int result = 0;
        for (auto& [x, freq] : count) {
            int groupSize = x + 1;
            int groups = (freq + x) / groupSize;
            result += groups * groupSize;
        }

        return result;
    }
};

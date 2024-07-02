class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> result;
        if (A.size() == 0) return result;
        int hash[26] = {0}; 
        for (int i = 0; i < A[0].size(); i++) { 
            hash[A[0][i] - 'a']++;
        }

        int hashOtherStr[26] = {0}; 
        for (int i = 1; i < A.size(); i++) {
            memset(hashOtherStr, 0, 26 * sizeof(int));
            for (int j = 0; j < A[i].size(); j++) {
                hashOtherStr[A[i][j] - 'a']++;
            }
            for (int k = 0; k < 26; k++) {
                hash[k] = min(hash[k], hashOtherStr[k]);//没有同时出现的降为零，出现次数少的取少数
            }
        }
        for (int i = 0; i < 26; i++) {
            while (hash[i] != 0) {
                string s(1, i + 'a'); // 1位元素入数组
                result.push_back(s);
                hash[i]--;
            }
        }

        return result;
    }
};

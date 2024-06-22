//给定字符串s和t，判断s是否为t的子序列
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = dp[i][j - 1];//只能从左推/s不动t减小
            }
        }
        if (dp[s.size()][t.size()] == s.size()) return true;
        return false;
    }
};

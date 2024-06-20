class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];//j-1 为j为头结点左子树节点数量，i-j 为以j为头结点右子树节点数量
            }
        }
        return dp[n];
    }
};

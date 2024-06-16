在背包问题中，遍历物品和背包容量的顺序会影响动态规划表的填充顺序：
    先遍历物品：我们对每个物品 i，计算其在不同容量 j 下的最优解。这种方式直观且易于理解，因为它逐步考虑每个物品是否放入背包。
    先遍历背包容量：对于每个容量 j，我们考虑不同物品 i 的最优解。这种方式在解决完全背包问题时常用，在01背包问题中需要适当调整。

问能否能装满背包（或者最多装多少）：dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
问装满背包有几种方法：dp[j] += dp[j - nums[i]] ;
问背包装满最大价值：dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
问装满背包所有物品的最小个数：dp[j] = min(dp[j - coins[i]] + 1, dp[j]);


void test_2_wei_bag_problem1() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));
    for (int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0];
    }

    for(int i = 1; i < weight.size(); i++) { // 遍历物品
        for(int j = 0; j <= bagweight; j++) { // 遍历背包容量
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);

        }
    }

    cout << dp[weight.size() - 1][bagweight] << endl;
}

int main() {
    test_2_wei_bag_problem1();
}

假设有3个物品，重量分别为 [2, 3, 4]，价值分别为 [3, 4, 5]，背包容量为 5。

动态规划表初始状态：
dp[0] = [0, 0, 0, 0, 0, 0]
填表过程：
    物品 1 （重量 2，价值 3）：
dp[1] = [0, 0, 3, 3, 3, 3]
    物品 2 （重量 3，价值 4）：
dp[2] = [0, 0, 3, 4, 4, 7]
    物品 3 （重量 4，价值 5）：
dp[3] = [0, 0, 3, 4, 5, 7]
最终 dp 表示在不同背包容量下的最优解，dp[n][bagweight] 就是所求的最大价值。


void test_1_wei_bag_problem() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;

    vector<int> dp(bagWeight + 1, 0);
    for(int i = 0; i < weight.size(); i++) { // 遍历物品
        for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagWeight] << endl;
}

int main() {
    test_1_wei_bag_problem();
}

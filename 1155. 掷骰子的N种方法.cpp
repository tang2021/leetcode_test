// 1155. 掷骰子的N种方法
// 这里有 d 个一样的骰子，每个骰子上都有 f 个面，分别标号为 1, 2, ..., f。
// 我们约定：掷骰子的得到总点数为各骰子面朝上的数字的总和。
// 如果需要掷出的总点数为 target，请你计算出有多少种不同的组合情况（所有的组合情况总共有 f^d 种），模 10^9 + 7 后返回。
// 示例 1：
// 输入：d = 1, f = 6, target = 3
// 输出：1
// 示例 2：

// 输入：d = 2, f = 6, target = 7
// 输出：6
// 示例 3：
// 输入：d = 2, f = 5, target = 10
// 输出：1
int numRollsToTarget(int d, int f, int target) {
    vector<int>dp(target+1,0);
    dp[0]=1;
    int mod=1e9+7;
    for(int i=1;i<=d;i++){
        for(int j=target;j>=0;j--){
            dp[j]=0;
            for(int k=1;k<=min(f,j);k++)
            dp[j]=(dp[j]+dp[j-k])%mod;
        }
    }
    return dp[target]%mod;
}
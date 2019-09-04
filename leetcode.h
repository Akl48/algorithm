#include "config.h"

class _343_leetCode {
    /*
    给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
    */
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2 ; i <= n ; i++ ) {
            for (int j = 1 ; j < i ; j++ ) {
                dp[i] = max(dp[i],max(dp[i - j] * j,(i - j) * j));
            }
        }
        return dp[n];   
    }
};
class _279_leetCode {
    /*
    给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
    */
    int numSquares(int n) {
        vector<int> dp(n+1);
        for (int i = 1 ; i <= n ; i++ ) {
            dp[i] = i;
            for (int j = 1 ; j <= sqrt(i) ; j++ ) {
                dp[i] = min(dp[i],dp[i - j * j] + 1 );
            }
        }
        return dp[n];
    }  
};
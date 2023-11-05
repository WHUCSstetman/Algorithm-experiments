#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int minCoins(std::vector<int>& coins, int amount) {
    int n = coins.size();
    std::vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        return -1;  // No valid coin combination
    } else {
        return dp[amount];
    }
}

int main() {
    std::vector<int> coins = {1, 2, 5};
    int amount ;
    cin>>amount;

    int result = minCoins(coins, amount);

    if (result == -1) {
        std::cout << "No valid coin combination for amount " << amount << std::endl;
    } else {
        std::cout << "Minimum number of coins required for amount " << amount << ": " << result << std::endl;
    }

    return 0;
}

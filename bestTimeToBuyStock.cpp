#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
#include <algorithm> // for min and max

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = INT_MAX;
        for (int price: prices){
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }
        return max_profit;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> prices = {3, 8, 1, 2};

    // Call the function
    int profit = sol.maxProfit(prices);

    // Output the result
    cout << "Maximum Profit: " << profit << endl;

    return 0;
}

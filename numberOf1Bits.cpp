#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count = count + n % 2; // Adds 1 if the least significant bit is 1
            n = n >> 1;            // Right shift to check next bit
        }
        return count;
    }
};

int main() {
    // Example input: 01111111111111111111111111111101
    // Binary: 2147483645 (in decimal)
    uint32_t n = 0b01111111111111111111111111111101;

    Solution sol;
    int result = sol.hammingWeight(n);

    cout << "Number of 1 bits (Hamming weight): " << result << endl;

    return 0;
}

#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 31; i >= 0; i--) {
            if ((n >> i) & 1) {   // check bit at position i
                res |= 1 << (31 - i); // set mirrored bit
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    uint32_t n = 21;  // Example input: 00000000000000000000000000010101
    uint32_t result = sol.reverseBits(n);

    cout << "Input n = " << n << endl;
    cout << "Reversed bits = " << result << endl;

    // Show binary form of result (32-bit)
    cout << "Reversed bits (binary) = ";
    for (int i = 31; i >= 0; i--) {
        cout << ((result >> i) & 1);
    }
    cout << endl;

    return 0;
}

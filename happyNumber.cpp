#include <iostream>
#include <set>
#include <cmath>
using namespace std;

class Solution {
public:
    int helper(int n, set<int> &s)
    {
        // Optional: compute number of digits (not actually used)
        int dig = log10(abs(n)) + 1;

        int sum = 0;
        while(n != 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        int ssize = s.size();
        s.insert(sum);
        if(ssize == s.size()) return 0; // already existed (cycle)
        return sum;
    }

    bool isHappy(int flag)
    {
        set<int> s;
        while(true)
        {
            flag = helper(flag, s);
            if(flag == 1) break;
            if(flag == 0) break;
        }
        return flag == 1;
    }
};

int main() {
    Solution sol;
    
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (sol.isHappy(number)) {
        cout << number << " is a happy number!" << endl;
    } else {
        cout << number << " is not a happy number." << endl;
    }

    return 0;
}

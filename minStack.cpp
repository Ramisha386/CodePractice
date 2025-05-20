#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> Stack;
    stack<int> minStack;

    MinStack() {}

    void push(int val) {
        Stack.push(val);
        if (minStack.empty() || minStack.top() >= val)
            minStack.push(val);
    }

    void pop() {
        if (!minStack.empty() && Stack.top() == minStack.top()) {
            minStack.pop();
        }
        Stack.pop();
    }

    int top() {
        return Stack.top();
    }

    int getMin() {
        return minStack.top();  // assuming valid call; per constraints, stack is not empty
    }
};

int main() {
    // Example input:
    // ["MinStack","push","push","push","getMin","pop","top","getMin"]
    // [[],[-2],[0],[-3],[],[],[],[]]

    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "Current Min: " << minStack.getMin() << endl; // Output: -3
    minStack.pop();
    cout << "Top Element: " << minStack.top() << endl;    // Output: 0
    cout << "Current Min: " << minStack.getMin() << endl; // Output: -2

    return 0;
}

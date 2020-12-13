#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
    public:
        MinStack() {
        }

        void push(int x) {
            x_stack.push(x);
            if (min_stack.empty() || x <= min_stack.top()) {
                min_stack.push(x);
            }
        }

        void pop() {
            if (x_stack.top() == min_stack.top()) {
                min_stack.pop();
            }
            x_stack.pop();
        }

        int top() {
            return x_stack.top();
        }

        int getMin() {
            return min_stack.top();
        }
};

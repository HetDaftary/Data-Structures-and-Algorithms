#include "../src/Stack.hpp"

int main() {
    Stack<int> stk;
    for (int i = 0; i < 5; i++) {
        stk.push(i);
        stk.displayStack(cout);
    }

    cout << stk.peek() << endl;
    stk.pop();
    cout << stk.peek() << endl;

    return 0;
}

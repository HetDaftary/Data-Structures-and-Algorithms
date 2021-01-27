 #if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "..\includer.hpp"
#else 
    #include "../includer.hpp"
#endif
using namespace std;

int main() {
    Stack<int, false> stk;
    for (int i = 0; i < 5; i++) {
        stk.push(i);
        stk.displayStack(cout);
    }

    cout << stk.peek() << endl;
    stk.pop();
    cout << stk.peek() << endl;

    Stack<int, true> stk1(5);
    for (int i = 0; i < 5; i++) {
        stk1.push(i);
        stk1.displayStack(cout);
    }

    cout << stk1.peek() << endl;
    stk1.pop();
    cout << stk1.peek() << endl;

    return 0;
}

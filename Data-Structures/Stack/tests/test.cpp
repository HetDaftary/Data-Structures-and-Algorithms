 #if defined(_WIN32) || defined(_WIN64) || (defined(__CYGWIN__) && !defined(_WIN32)) // Windows uses a different system for path names. 
    #include "..\includer.hpp"
#else 
    #include "../includer.hpp"
#endif

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

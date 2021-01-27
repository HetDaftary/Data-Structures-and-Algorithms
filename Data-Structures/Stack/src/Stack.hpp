#include "StackTypes.hpp"

template<class T, bool isFixedSize> class Stack {
    private:
        #if isFixedSize 
            StackFixedSize<T>* stk;
        #else 
            StackVariableSize<T>* stk;
        #endif
    
    public:
        Stack(int capacity = 1) {
            #if isFixedSize
                stk = new StackFixedSize<T>(capacity);
            #else 
                stk = new StackVariableSize<T>(capacity);
            #endif
        }

        bool isEmpty() {
            return stk -> isEmpty();
        }

        void push(T key) {
            stk -> push(key);
        }

        T peek() {
            return stk -> peek();
        }

        bool pop() {
            return stk -> pop();
        }

        void displayStack(std::ostream& outStream, std::string sep = " ") {
            stk -> displayStack(outStream, sep);
        }
};

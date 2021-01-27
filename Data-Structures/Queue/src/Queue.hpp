#include "QueueTypes.hpp"

template<class T, bool isFixedSize> class Queue {
    private:
        #if isFixedSize 
            QueueFixedSize<T>* qu;
        #else 
            QueueVariableSize<T>* qu;
        #endif
    public:
        Queue1(int capacity = 1) {
            #if isFixedSize
                qu = new QueueFixedSize<T>(capacity);
            #else  
                qu = new QueueVariableSize<T>(capacity);
            #endif
        }

        bool isEmpty() {
            return qu -> isEmpty();
        }

        void enqueue(T key) {
            qu -> enqueue(key);
        }

        bool dequeue() {
            return qu -> dequeue();
        }

        void displayQueue(ostream& outStream, std::string sep = " ") {
            return qu -> displayQueue(outStream, sep);
        }
};
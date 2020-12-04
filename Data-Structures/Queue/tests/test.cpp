#include "../src/Queue.hpp"

int main() {
    Queue<int> qu;
    for (int i = 0; i < 1000; i++) {
        qu.enqueue(i);
        qu.displayQueue();
    }

    while (!qu.isEmpty()) {
        qu.dequeue();
        qu.displayQueue();
    }
    return 0;
}
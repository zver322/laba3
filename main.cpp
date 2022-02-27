#include <iostream>
#include "deque.h"

int main() {
    Deque<int> dq(5);
    Deque<int> dq2(5);
    for (int i = 0; i < dq.sizeGet(); ++i) {
        dq.inserRear(i);
        dq2.inserRear(i*2);
    }

    /*for (auto it = dq.begin(), end = dq.end(); it != end; ++it) {
        const auto i = *it;
        std::cout << i << "\n";
    }*/

    Deque<int>::Iterator it = dq.set(3);

    for (Deque<int>::Iterator it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
    dq.insert(it, 3);
    /*

    for (Deque<int>::Iterator it = dq2.begin(); it != dq2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    dq.swap(dq2);
    for (Deque<int>::Iterator it = dq.begin(); it != dq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (Deque<int>::Iterator it = dq2.begin(); it != dq2.end(); ++it) {
        std::cout << *it << " ";
    }*/
    
    return 0;
}
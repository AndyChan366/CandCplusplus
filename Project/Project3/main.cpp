#include <iostream>
#include "Deque.h"

int main()
{
    Deque< int >::debug_printing(true);
    
    Deque< int > deque;
    deque.push_front(5);
    deque.push_back(6);
    int x = deque.front(); // x = 5
    deque.front() = 4; // front of deque is now 4
    int y = deque.back(); // y = 6
    std::cout << deque << std::endl;
    deque.back() = 7; // back of deque is 7
    deque.pop_front(); // deque has now 1 value, i.e., 7
    deque.pop_back(); // deque is now empty
    int size = deque.size(); // size is zero
    std::cout << size << std::endl;
    bool b = deque.is_empty(); // b is true
    std::cout << b << std::endl;
    deque.push_front(1);
    deque.push_front(2);
    deque.push_front(3);
    std::cout << deque << std::endl;
    deque.clear(); // deque is now empty

    return 0;
}
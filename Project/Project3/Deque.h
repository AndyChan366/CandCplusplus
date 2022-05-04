#ifndef DEQUE_H
#define DEQUE_H

#include "DLList.h"

class UnderflowError {};

template < typename t >
class Deque
{
    public:

    //=========================================================================
    // Reference Methods
    //=========================================================================

    DLList< t > &__list__() { return list_; }

    t &front()              { return list_.front(); }
    t front() const         { return list_.front(); }
    

    t &back()               { return list_.back(); }
    t back() const          { return list_.back(); }

    //=========================================================================
    // Information Methods
    //=========================================================================

    int size() const        { return list_.size(); }
    bool is_empty()         { return list_.is_empty(); }

    //=========================================================================
    // Mutator Methods
    //=========================================================================

    void push_front(t key)  { list_.insert_head(key); }
    void push_back(t key)   { list_.insert_tail(key); }

    t pop_front()           { return list_.remove_head(); }  
    t pop_back()            { return list_.remove_tail(); }

    void clear()            { list_.clear(); }

    static bool debug_printing() { return DLList< t >::debug_printing(); }
    static bool debug_printing(bool toggle) 
    { 
        DLList< t >::debug_printing(toggle);
        DLNode< t >::debug_printing(toggle);
        return DLList< t >::debug_printing(); 
    } 

    private:
    DLList< t > list_;
};

template < typename t >
std::ostream &operator<<(std::ostream &cout, Deque< t > &deque)
{
    cout << deque.__list__();
    return cout;
}


#endif
#ifndef DLNODE_H
#define DLNODE_H

#include <iostream>
#include <iomanip>

template < typename t >
class DLNode
{
    public:
    DLNode(const t &key, DLNode< t > *prev=NULL, DLNode< t > *next=NULL)
    : key_(key), prev_(prev), next_(next)
    {}

    //=========================================================================
    // reference methods
    //=========================================================================

    t &key()      { return key_; }
    t key() const { return key_; }

    DLNode< t > *&prev()      { return prev_; }
    DLNode< t > *prev() const { return prev_; }

    DLNode< t > *&next()      { return next_; }
    DLNode< t > *next() const { return next_; }

    //=========================================================================
    // getter methods
    //=========================================================================
    t get_key() const        { return key_;  }
    DLNode *get_prev() const { return prev_; }
    DLNode *get_next() const { return next_; }

    //=========================================================================
    // setter methods
    //=========================================================================
    void set_key(t key)         { key_ = key;   }
    void set_prev(DLNode *prev) { prev_ = prev; }
    void set_next(DLNode *next) { next_ = next; }

    //=========================================================================
    // debug methods
    //=========================================================================
    static bool debug_printing() { return debug_print; }
    static bool debug_printing(bool toggle) 
    { 
        debug_print = toggle; 
        return debug_print; 
    }

    private:
    //=========================================================================
    // member variables
    //=========================================================================
    t key_;
    DLNode< t > *prev_;
    DLNode< t > *next_;
    static bool debug_print;
};

//=============================================================================
// static member initialization
//=============================================================================
template < typename t >
bool DLNode< t >::debug_print(false);

//=============================================================================
// non-member operator overload
//=============================================================================
template < typename t >
std::ostream &operator<<(std::ostream &cout, DLNode< t > &node)
{
    const int N = 10;
    if (DLNode< t >::debug_printing())
    {
        cout << "<DLNode"  << std::setw(N) << &node 
             << ", key:"   << std::setw(N) << node.key() 
             << ", prev:"  << std::setw(N) << node.prev()
             << ", next:"  << std::setw(N) << node.next() 
             //<< " size_of: " << sizeof(node)
             <<'>';
    }
    else 
    {
        cout << node.key();
    }
    return cout;
}

#endif
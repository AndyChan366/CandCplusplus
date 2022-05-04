#ifndef DLLIST_H
#define DLLIST_H
#include "DLNode.h"

class IndexError {};
class ValueError {};

template < typename t >
class DLList
{
    public:
    //=========================================================================
    // Constructors
    //=========================================================================
    
    DLList()
    : head_sentinel_(new DLNode< t >(-1)),
      tail_sentinel_(new DLNode< t >(-2))
    {
        head_sentinel_->set_next(tail_sentinel_);
        tail_sentinel_->set_prev(head_sentinel_);
    }

    //=========================================================================
    // Destructors
    //=========================================================================

    ~DLList()
    {
        clear();
        delete head_sentinel_;
        delete tail_sentinel_;
    }

    //=========================================================================
    // Reference Methods
    //=========================================================================
    DLNode< t >* head_sentinel() const { return head_sentinel_; }
    DLNode< t >* tail_sentinel() const { return tail_sentinel_; }

    DLNode< t >* &head_sentinel() { return head_sentinel_; }
    DLNode< t >* &tail_sentinel() { return tail_sentinel_; }

    t &front()      
    { 
        if (head_sentinel()->next() == tail_sentinel())
        throw ValueError();

        return head_sentinel()->next()->key(); 
    }
    t front() const 
    { 
        if (head_sentinel()->next() == tail_sentinel())
        throw ValueError();

        return head_sentinel()->next()->key();    
    }

    t &back()       
    { 
        if (tail_sentinel()->prev() == head_sentinel())
        throw ValueError();

        return tail_sentinel()->prev()->key();
    }
    t back() const
    { 
        if (tail_sentinel()->prev() == head_sentinel())
        throw ValueError();

        return tail_sentinel()->prev()->key();
    }

    //========================================================================
    // Information Methods
    //=========================================================================
    int size() const
    {
        DLNode< t > *node = head_sentinel()->next();
        int count = 0;

        while(node != tail_sentinel())
        {
            ++count;
            node = node->next();
        }

        return count;
    }

    DLNode< t > *find(t key) const
    {
        DLNode< t > *head_temp = head_sentinel()->next();
        DLNode< t > *tail_temp = tail_sentinel()->prev();

        while (head_temp != tail_temp)
        {
            if (head_temp->key() == key) return head_temp;
            if (tail_temp->key() == key) return tail_temp;

            head_temp = head_temp->next();
            tail_temp = tail_temp->prev();
        }

        return NULL;
    }

    bool is_empty()
    {
        if (head_sentinel()->next() == tail_sentinel()) return true;
        else return false;
    }

    //=========================================================================
    // Adder Methods
    //=========================================================================

    void insert_head(t key)
    {
        DLNode< t > *temp = new DLNode< t >(key, head_sentinel());
        temp->next() = head_sentinel()->next();
        head_sentinel()->next()->prev() = temp;
        head_sentinel()->next() = temp;
    }

    void insert_tail(t key)
    {
        DLNode< t > *temp = new DLNode< t >(key, NULL, tail_sentinel());
        temp->prev() = tail_sentinel()->prev();
        tail_sentinel()->prev()->next() = temp;
        tail_sentinel()->prev() = temp;
    }

    void insert_before(DLNode< t >* node, t key)
    {
        DLNode< t >* temp = node->prev();
        temp->next() = new DLNode< t >(key, temp, node);
        node->prev() = temp->next();
    }

    void insert_after(DLNode< t >* node, t key)
    {
        DLNode< t >* temp = node->next();
        temp->prev() = new DLNode< t >(key, node, temp);
        node->next() = temp->prev();
    }

    //=========================================================================
    // Remover Methods
    //=========================================================================

    t remove_head()
    {
        DLNode< t >* temp = head_sentinel();

        if (temp->next() != tail_sentinel())
        {
            t ret = temp->next()->key();
            head_sentinel() = head_sentinel()->next();

            delete temp;

            return ret;
        }
        throw ValueError();
    }   

    t remove_tail()
    {
        DLNode< t >* temp = tail_sentinel()->prev();

        if (temp != head_sentinel())
        {
            t ret = temp->prev()->key();
            temp->prev()->next() = tail_sentinel();
            tail_sentinel()->prev() = tail_sentinel();
        
            delete temp;

            return ret;
        }
        throw ValueError();
    }

    t remove(DLNode< t >* node)
    {
        if (node == NULL) throw ValueError();
        
        DLNode< t > *head_temp = head_sentinel()->next();
        DLNode< t > *tail_temp = tail_sentinel()->prev();
        t ret;

        while (head_temp != tail_temp)
        {
            if (head_temp == node || tail_temp == node)
            {
                node->prev()->next() = node->next();
                node->next()->prev() = node->prev();
                ret = node->key();
                delete node;
                return ret;
            }

            head_temp = head_temp->next();
            tail_temp = tail_temp->prev();
        }

        throw ValueError();
    }

    t remove(t key)
    {
        DLNode< t >* node = find(key);
        if (node == NULL) throw ValueError();

        node->prev()->next() = node->next();
        node->next()->prev() = node->prev();

        t ret = node->key();

        delete node;
        return ret;
        throw ValueError();
    }

    void clear()
    {
        DLNode< t >* head_temp = head_sentinel();
        DLNode< t >* tail_temp = tail_sentinel();

        while(head_temp != tail_temp)
        {
            head_temp = head_sentinel()->next()->next();
            delete head_sentinel()->next();
            head_sentinel()->next() = head_temp;
        }
    }

    //=========================================================================
    // Operator Overloads
    //=========================================================================

    t &operator[](int pos)
    {
        int head_count = 0;
        int tail_count = size() - 1;
        if (pos < head_count || pos > tail_count) throw IndexError();

        DLNode< t >* head_node = head_sentinel()->next();
        DLNode< t >* tail_node = tail_sentinel()->prev();

        while(head_node != tail_node)
        {
            if (head_count == pos) return head_node->key();
            if (tail_count == pos) return tail_node->key();
            ++head_count;
            --tail_count;
            head_node = head_node->next();
            tail_node = tail_node->prev();
        }
        throw IndexError();
    }

    bool operator==(const DLList< t > &list)
    {
        DLNode< t >* local_head = head_sentinel();
        DLNode< t >* local_tail = tail_sentinel();
        DLNode< t >* forgn_head = list.head_sentinel();
        DLNode< t >* forgn_tail = list.tail_sentinel();

        while(local_head != local_tail && forgn_head != forgn_tail)
        {
            if (local_head->key() != forgn_head->key() ||
                local_tail->key() != forgn_tail->key())
                return false;

            local_head = local_head->next();
            local_tail = local_tail->prev();
            forgn_head = forgn_head->next();
            forgn_tail = forgn_tail->prev();
        }
        return true;
    }

    bool operator!=(DLList< t > &list)
    {
        if (list == *this) return false;
        return true;
    }

    //=========================================================================
    // Debug printing control
    //=========================================================================
    static bool debug_printing() { return debug_print; }
    static bool debug_printing(bool toggle) 
    { 
        debug_print = toggle; 
        return debug_print; 
    }

    private:
    DLNode< t >* head_sentinel_;
    DLNode< t >* tail_sentinel_;
    static bool debug_print;
};

//=============================================================================
// Initialize Static Members
//=============================================================================

template <typename t >
bool DLList< t >::debug_print(false);

//=============================================================================
// Non-member operator overloads
//=============================================================================

template < typename t >
std::ostream &operator<<(std::ostream &cout, DLList< t > &list)
{
    if (DLList< t >::debug_printing())
    {
        cout << "<DLList " << &list << " head_sentinel: " << list.head_sentinel() 
             << " value: " << list.head_sentinel()->key() 
             << " list size: " << list.size()
             << '>'
             << std::endl;
        DLNode< t > *temp = list.head_sentinel()->next();
        while(temp != list.tail_sentinel())
        {
            cout << "    " << *temp << std::endl;
            temp = temp->next();
        }
        cout << "<                tail_sentinel: " << list.tail_sentinel() 
             << " value: " << list.tail_sentinel()->key() << '>';
    }
    else
    {
        cout << '[';
        DLNode< t > *temp = list.head_sentinel()->next();
        while(temp != list.tail_sentinel())
        {
            cout << temp->key();
            if (temp->next() != NULL)
            if (temp->next() != list.tail_sentinel()) cout << ", ";
            temp = temp->next();
        }
        cout << ']';
    }
    
    return cout;
}

#endif

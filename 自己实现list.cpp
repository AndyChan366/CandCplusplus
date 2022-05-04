#include "a_list.h"

template <typename T>
typename a_list<T>::reference a_list<T>::front(){
    return node->next->data;
}

template <typename T>
typename a_list<T>::reference a_list<T>::back(){
    return node->prev->data;
}

template <typename T>
bool a_list<T>::empty() const noexcept{
    return size_count==0;
}

template <typename T>
typename a_list<T>::size_type a_list<T>::size() const noexcept{
    return size_count;
}

template <typename T>
typename a_list<T>::iterator a_list<T>::begin() noexcept{
    return node->next;
}

template <typename T>
typename a_list<T>::iterator a_list<T>::begin() const noexcept{
    return node->next;
}

template <typename T>
typename a_list<T>::iterator a_list<T>::end() noexcept{
    return node;
}

template <typename T>
typename a_list<T>::iterator a_list<T>::end() const noexcept{
    return node;
}

template <typename T>
void a_list<T>::clear() noexcept{
    erase(begin(), end());
}

template <typename T>
typename a_list<T>::iterator a_list<T>::insert(iterator pos, const T &value){
    auto temp = new list_node<T>(value);
    temp->prev = pos.link->prev;
    pos.link->prev = temp;
    temp->prev->next = temp;
    temp->next = pos.link;
    ++size_count;
    return temp;
}

template <typename T>
typename a_list<T>::iterator a_list<T>::insert(typename a_list<T>::iterator pos, T &&value){
    auto temp = new list_node<T>(std::move(value));
    temp->prev = pos.link->prev;
    pos.link->prev = temp;
    temp->prev->next = temp;
    temp->next = pos.link;
    ++size_count;
    return temp;
}

template <typename T>
typename a_list<T>::iterator a_list<T>::erase(typename a_list<T>::iterator pos){
    auto temp = pos.link;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    auto res = typename a_list<T>::iterator(temp->next);
    delete temp;
    --size_count;
    return res;
}

template <typename T>
typename a_list<T>::iterator a_list<T>::erase(typename a_list<T>::iterator first, typename a_list<T>::iterator last){
    for(auto it = first; it != last;){
        it = erase(it);
    }
    return last;
}

template <typename T>
void a_list<T>::push_back(const T &value){
    insert(end(), value);
}

template <typename T>
void a_list<T>::push_back(T &&value){
    insert(end(), std::move(value));
}

template <typename T>
void a_list<T>::pop_back(){
    erase(node->prev);
}

template <typename T>
void a_list<T>::push_front(const T &value){
    insert(begin(), value);
}

template <typename T>
void a_list<T>::push_front(T &&value){
    insert(begin(), std::move(value));
}

template <typename T>
void a_list<T>::pop_front(){
    erase(begin());
}

template <typename T>
bool a_list<T>::operator==(const a_list<T> &rhs) const{
    if(size_count != rhs.size_count){
        return false;
    }
    for(auto it1 = begin(), it2 = rhs.begin(); it1 != end() && it2 != rhs.end(); ++it1, ++it2){
        if(*it1 != *it2){
            return false;
        }      
    }
    return true;
}

template <typename T>
bool a_list<T>::operator!=(const a_list<T> &rhs) const{
    return !(*this == rhs);
}

template <typename T>
a_list<T>::~a_list(){
    clear();
    delete node;
}

template <typename T>
a_list<T> &a_list<T>::operator=(const a_list<T> &rhs){
    clear();
    for(auto it = rhs.begin(); it != rhs.end(); ++it){
        push_back(*it);
    }
    return *this;
}

template <typename T>
a_list<T> &a_list<T>::operator=(a_list<T> &&rhs){
    clear();
    std::swap(size_count, rhs.size_count);
    std::swap(node, rhs.node);
    return *this;
}

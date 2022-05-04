#include "a_stack.h"

template <typename T, typename Container>
typename a_stack<T, Container>::reference a_stack<T, Container>::top(){
    return c.back();
}

template <typename T, typename Container>
typename a_stack<T, Container>::const_reference a_stack<T, Container>::top() const{
    return c.back();
}

template <typename T, typename Container>
void a_stack<T, Container>::push(const typename a_stack<T, Container>::value_type &value){
    c.push_back(value);
}

template <typename T, typename Container>
void a_stack<T, Container>::push(typename a_stack<T, Container>::value_type &&value){
    c.push_back(std::move(value));
}

template <typename T, typename Container>
bool a_stack<T, Container>::empty() const{
    return c.empty();
}

template <typename T, typename Container>
typename a_stack<T, Container>::size_type a_stack<T, Container>::size() const{
    return c.size();
}

template <typename T, typename Container>
void a_stack<T, Container>::pop(){
    c.pop_back();
}

template <typename T, typename Container>
a_stack<T, Container>& a_stack<T, Container>::operator=(const a_stack<T, Container>& o) = default;

template <typename T, typename Container>
a_stack<T, Container>& a_stack<T, Container>::operator=(a_stack<T, Container>&& o) = default;

template <class T, class Container>
bool operator==(const a_stack<T, Container> &lhs, const a_stack<T, Container> &rhs){
    return lhs.c == rhs.c;
}

template <class T, class Container>
bool operator!=(const a_stack<T, Container> &lhs, const a_stack<T, Container> &rhs){
    return !(lhs == rhs);
}

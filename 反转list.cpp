#include"ListNode.h" 

ListNode *reverseList(ListNode *head){
    ListNode *res=head;
    head=head->next;
    ListNode *prev=nullptr,*next=nullptr;
    while(head!=nullptr){
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    res->next=prev;
    return res;
}

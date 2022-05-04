/*
下面所给的是链表节点的结构，给定一个链表和一个值X，对其进行分区
使得节点值小于X的节点放在前面，大于等于X的节点放在后面，保持每个分区节点的原始顺序
示例：
输入5->7->44->1->35    10
返回5->7->1->44->35
*/
#include<iostream>
#include"ListNode.h"
using namespace std;
ListNode* partList(ListNode* head, int x){
    ListNode *firstblock=nullptr;
    ListNode *secondblock=nullptr;
    ListNode *left=nullptr;
    ListNode *right=nullptr;
    while(head!=nullptr){
        if(head->val<x){
            if(firstblock){
                left->next=head;
                left=left->next;
            }
            else{
                left=firstblock=head;
            }
        }
        else{
            if(secondblock){
                right->next=head;
                right=right->next;
            }
            else{
                right=secondblock=head;
            }
        }
        head=head->next;
    }
    right->next=nullptr;
    left->next=secondblock;
    return firstblock;
}
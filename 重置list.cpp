#include "ListNode.h"
ListNode *resetList(ListNode *head)
{
    if (!head)
    {
        return head;
    }

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *temp = even;

    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = temp;
    return head;
}

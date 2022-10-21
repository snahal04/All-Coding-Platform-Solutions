/*Merge Two Sorted Lists 
Asked In: Microsoft Yahoo Amazon*/

/*Merge two sorted linked lists and return it as a new list.*/

/*The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.*/

//For example, given following linked lists :

  //5 -> 8 -> 20 
  //4 -> 11 -> 15
//The merged list should be :

//4 -> 5 -> 8 -> 11 -> 15 -> 20

//Solution in CPP 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::mergeTwoLists(ListNode *A, ListNode *B)
{
    ListNode *head;
    if (A->val > B->val)
    {
        head = B;
        B = B->next;
    }
    else
    {
        head = A;
        A = A->next;
    }
    ListNode *p = head;
    while (A && B)
    {
        if (A->val < B->val)
        {
            p->next = A;
            A = A->next;
            p = p->next;
        }
        else
        {
            p->next = B;
            B = B->next;
            p = p->next;
        }
    }
    while (A)
    {
        p->next = A;
        A = A->next;
        p = p->next;
    }
    while (B)
    {
        p->next = B;
        B = B->next;
        p = p->next;
    }
    return head;
}




#include "int.h"

struct ListNode {
    int val;
    struct ListNode *next;
};


// Reverse the linklist without recursion
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *pCurr = NULL, *pPrev = NULL, *pNext = NULL;
    
    pCurr = head;
    
    while (pCurr != NULL)
    {
        pNext = pCurr->next;
        
        if (pCurr == head)
        {
            pCurr->next = NULL;
        }
        else
        {
            pCurr->next = pPrev;
        }
        
        pPrev = pCurr;
        
        head = pCurr;
        pCurr = pNext;
    }
    
    return head;
}

// Reverse the linklist with recursion
struct ListNode* reverseListWithRecursion(struct ListNode* head) {
    struct ListNode *pCurr = NULL, *pTmpHead = NULL;
    
    if (head == NULL) return NULL;
    
    pCurr = head;

    pTmpHead = reverseList(pCurr->next);
    
    if (pCurr->next == NULL)
    {
        pTmpHead = pCurr;
    }
    else
    {
        (pCurr->next)->next = pCurr;
        pCurr->next = NULL;
    }
    
    return pTmpHead;
}

// detects cycle in the link list
bool hasCycle(struct ListNode *head)
{
    struct ListNode *pCurr = NULL, *pFast = NULL;

    if (!head)
        return false;
    pCurr = head;
    pFast = pCurr->next;

    while (pFast != NULL)
    {
        if (pCurr == pFast)
        {
            return true;
        }
        else
        {
            pCurr = pCurr->next;
            pFast = (pFast->next) ? ((pFast->next)->next) : NULL;
        }
    }
    
    return false;
}

// Mergedlist without recursion
struct ListNode* mergeTwoLists(struct ListNode* pHead1, struct ListNode* pHead2)
{
    struct ListNode *pHead = NULL, *pCurr1 = NULL, *pCurr2 = NULL, *pMergeCurr = NULL;

    if ((!pHead1) && (!pHead2))
    {
        return NULL;
    }

    if (!pHead1)
    {
        return pHead2;
    }

    if (!pHead2)
    {
        return pHead1;
    }

    pCurr1 = pHead1;
    pCurr2 = pHead2;

    // Processing of First node of Mergedlist
    if (pCurr1->val < pCurr2->val)
    {
        pHead = pCurr1;
        pCurr1 = pCurr1->next;
    }
    else
    {
        pHead = pCurr2;
        pCurr2 = pCurr2->next;
    }

    pHead->next = NULL;
    pMergeCurr = pHead; // Maintains curr ptr in merged list

    while ((NULL != pCurr1) || (NULL != pCurr2))
    {
        if (pCurr1 && pCurr2)
        {
            if (pCurr1->val < pCurr2->val)
            {
                pMergeCurr->next    = pCurr1; // connect to merged list
                pMergeCurr          = pCurr1; // move to next ptr in merged list
                pCurr1              = pCurr1->next; // Move to next ptr in first list
                pMergeCurr->next    = NULL;
            }
            else
            {
                pMergeCurr->next    = pCurr2; // connect to merged list
                pMergeCurr          = pCurr2; // move to next ptr in merged list
                pCurr2              = pCurr2->next; // Move to next ptr in first list
                pMergeCurr->next    = NULL;
            }
        }
        else if (!pCurr1)
        {
            pMergeCurr->next = pCurr2;
            break;
        }
        else if (!pCurr2)
        {
            pMergeCurr->next = pCurr1;
            break;
        }
    }

    return pHead;
}


// Mergedlist with recursion
struct ListNode* mergeTwoListsWithRecursion(struct ListNode* pHead1, struct ListNode* pHead2)
{
    struct ListNode *pHead = NULL;

    if ((!pHead1) && (!pHead2))
    {
        return NULL;
    }

    if (!pHead1)
    {
        return pHead2;
    }

    if (!pHead2)
    {
        return pHead1;
    }

    if (pHead1->val < pHead2->val)
    {
        pHead = mergeTwoLists(pHead1->next, pHead2);
        pHead1->next = pHead;
        return pHead1;
    }
    else
    {
        pHead = mergeTwoLists(pHead1, pHead2->next);
        pHead2->next = pHead;
        return pHead2;
    }
}


// Given sorted list, remove duplicates
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *pCurr = NULL, *pNext = NULL;

    if (!head)
    {
        return NULL;
    }

    if (head && !head->next)
    {
        return head;
    }

    pCurr = head;
    pNext = (pCurr) ? pCurr->next : NULL;

    while (pNext)
    {
        if (pCurr->val == pNext->val)
        {
            if (pCurr == head)
            {
                head = pNext;
                pCurr->next = NULL;
                free(pCurr);

                pCurr = head;
            }
            else
            {
                pCurr->next = pNext->next;
                free(pNext);
                pNext = NULL;
            }
        }
        else
        {
            pCurr = pCurr->next;
        }
        pNext = (pCurr) ? pCurr->next : NULL;
    }

    return head;
}

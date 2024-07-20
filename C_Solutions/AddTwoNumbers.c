#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
    res->val = 0;
    res->next = NULL;
    struct ListNode* current = res;
    int n = 0;

    while (l1 != NULL || l2 != NULL) {
        int x;
        int y;

        if (l1 != NULL) {
            x = l1->val;
        } else {
            x = 0;
        }

        if (l2 != NULL) {
            y = l2->val;
        } else {
            y = 0;
        }

        int sum = n + x + y;
        n = sum / 10;

        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
        current->next = NULL;

        if (l1 != NULL){
            l1 = l1->next;
        }
        if (l2 != NULL){
            l2 = l2->next;
        }
    }

    if (n > 0) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = n;
        current->next = NULL;
    }

    struct ListNode* result = res->next;
    free(res);
    return result;
}

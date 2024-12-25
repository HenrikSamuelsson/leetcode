/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* tail = head;
    int carry = 0;
    while (l1 || l2 || carry) {
        long sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        int digit = sum % 10;
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = digit;
        tail->next = node;
        tail = node;
    }
    tail->next = NULL;
    if (head == tail) {
        head->val = 0;
        return head;
    } else {
        struct ListNode* re = head->next;
        free(head);
        return re;
    }
}

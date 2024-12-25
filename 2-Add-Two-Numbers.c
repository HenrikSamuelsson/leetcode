/**
 * \brief Calculates the sum of two numbers.
 *
 * Both the resulting sum and the numbers are represented by linked lists.
 *
 * Definition for singly-linked list:
 * \code{.c}
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * \endcode
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Head of the linked list used to hold the sum.
    struct ListNode* head = calloc(1, sizeof(struct ListNode));
    // Variable for the carry when summing two digits.
    int carry = 0;
    // The linked list node that we are currently working on.
    struct ListNode* current = head;

    // Loop while there are input digits or a carry digit to process.
    while (l1 || l2 || carry) {
        // Add evuntual input digits and carry.
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        // Set the val digit of the current node.
        current->val = sum % 10;
        // Update he carry for the next iteration
        carry = sum / 10;

        // Move the l1 pointer to eventual next node.
        l1 = l1 ? l1->next : NULL;
        // Move the l2 pointer to eventual next node.
        l2 = l2 ? l2->next : NULL;
        if (l1 || l2 || carry) {
            // Create the next node and have the current node point to it.
            current->next = calloc(1, sizeof(struct ListNode));
            // Move the current pointer to the next node.
            current = current->next;
        }
    }

    return head;
}

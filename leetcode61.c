/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };

This solution rotates a singly linked list to the right by k positions
by performing the rotation step-by-step.

For each rotation:
- The last node is moved to the front
- The list is updated by adjusting pointers accordingly

Although this approach is intuitive and directly simulates the rotation process,
it results in O(n * k) time complexity in the worst case.

Time Complexity: O(n * k)
Space Complexity: O(1)

This implementation focuses on clarity of the rotation process and direct
manipulation of pointers rather than optimizing for minimal traversal.
*/
struct ListNode* rotateRight(struct ListNode* head, int k) {

    int size = 0, i;
    struct ListNode* ptr = head;

    while(ptr != NULL){ // Calculate size of the list
        size++;
        ptr = ptr -> next;
    }

    if(size < 2) return head;

    int n = k % size; // Reduce k to avoid unnecessary full rotations

    ptr = head;
    struct ListNode* ptr1 = head; 
    struct ListNode* ptr2 = head -> next;
    // Move ptr2 to the last node and ptr1 to second-last

    for(i = 0; i < n; i++){

        while(ptr2 -> next != NULL){
            ptr2 = ptr2 -> next;
            ptr1 = ptr1 -> next;
        }
        ptr1 -> next = NULL;
        ptr2 -> next = ptr; // Detach last node and move it to front
        ptr = ptr2;
        ptr1 = ptr;
        ptr2 = ptr -> next;
    }

    return ptr;

}

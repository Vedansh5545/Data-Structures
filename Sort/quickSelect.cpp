#include <iostream>

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to partition the linked list around a pivot
// This function returns the pivot node, and updates newHead and newEnd
ListNode* partition(ListNode* head, ListNode* end, ListNode* &newHead, ListNode* &newEnd) {
    ListNode* pivot = end;
    ListNode* prev = nullptr, *curr = head, *tail = pivot;
    ListNode* prevTemp = nullptr; // Pointer to the previous node of the current node
    // During partition, newHead and newEnd will be updated
    newHead = newEnd = nullptr;
    while (curr != pivot) {
        if (curr->val < pivot->val) {
            // First node that has a value less than the pivot - becomes the new head
            if (newHead == nullptr) newHead = curr;
            prev = curr;
            curr = curr->next;
        } else { // If current node is greater than pivot
            // Swap nodes
            if (prevTemp) prevTemp->next = curr->next;
            ListNode* temp = curr->next;
            curr->next = nullptr;
            if (prev) prev->next = temp;
            if (!prev) head = temp;
            if (temp) prevTemp = temp;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }
    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if (newHead == nullptr) newHead = pivot;
    // Update newEnd to the current tail node
    newEnd = tail;
    // Return the pivot node
    return pivot;
}

// Function to recursively find the kth smallest element using Quickselect
ListNode* quickSelect(ListNode* head, ListNode* end, int k) {
    if (!head || head == end) return head;
    ListNode* newHead = nullptr, *newEnd = nullptr;
    ListNode* pivot = partition(head, end, newHead, newEnd);
    // Count nodes before pivot
    int count = 0;
    ListNode* temp = newHead;
    while (temp != pivot) {
        count++;
        temp = temp->next;
    }
    // If pivot is at k-1, return it
    if (count == k) return pivot;
    // If count > k, recur for left list
    if (count > k) return quickSelect(newHead, pivot->next, k);
    // Else recur for right list
    return quickSelect(pivot->next, newEnd, k - count - 1);
}

// Wrapper over quickSelect
int findKthSmallest(ListNode* head, int k) {
    ListNode* end = head;
    while (end != nullptr && end->next != nullptr) end = end->next;
    ListNode* kth = quickSelect(head, end, k - 1);
    return kth ? kth->val : -1;
}

void deleteList(ListNode* &head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to print the ordinal suffix for a given number
std::string ordinalSuffix(int num) {
    if (num == 1) return "st";
    if (num == 2) return "nd";
    if (num == 3) return "rd";
    return "th";
}

int main() {
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    // Reading numbers and creating the list
    int numbers[] = {53, 12, 11, 5, 4};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    for (int i = 0; i < size; ++i) {
        ListNode* newNode = new ListNode(numbers[i]);
        if (!head) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }
    // Displaying the original list
    std::cout << "Original List: ";
    ListNode* temp = head;
    while (temp) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
    // Finding the kth smallest element
    int k = 2;
    std::cout << "The " << k << ordinalSuffix(k) << " smallest element is: " << findKthSmallest(head, k) << std::endl;
    // Clean up
    deleteList(head);
    return 0;
}
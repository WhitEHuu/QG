#include "linkedlist.h"

// 创建新的单链表节点
ListNode* createNode(int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 在单链表头部插入新节点
void insertAtBeginning(ListNode** head, int data) {
    ListNode* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// 在单链表末尾插入新节点
void insertAtEnd(ListNode** head, int data) {
    ListNode* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        ListNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 删除单链表中的指定节点
void deleteNode(ListNode** head, int key) {
    ListNode* temp = *head;
    ListNode* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key not found in the list\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// 打印单链表
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 释放单链表内存
void freeList(ListNode** head) {
    ListNode* current = *head;
    ListNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    ListNode* head = NULL;

    // 在头部插入节点
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("List after insertions at beginning: ");
    printList(head);

    // 在末尾插入节点
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("List after insertions at end: ");
    printList(head);

    // 删除节点
    deleteNode(&head, 3);

    printf("List after deleting node with key 3: ");
    printList(head);

    // 释放链表内存
    freeList(&head);

    return 0;
}
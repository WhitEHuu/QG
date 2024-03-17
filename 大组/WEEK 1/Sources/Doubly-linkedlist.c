#include "Doubly-linkedlist.h"

// 创建新的双向链表节点
DoublyListNode* createDoublyNode(int data) {
    DoublyListNode* newNode = (DoublyListNode*)malloc(sizeof(DoublyListNode)); // 分配内存以存储新节点
    if (newNode == NULL) {  // 检查内存分配是否成功
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;   // 设置新节点的数据
    newNode->prev = NULL;   // 将前一个节点的指针设置为NULL，因为这是一个新的头节点
    newNode->next = NULL;   // 将后一个节点的指针设置为NULL，因为这是一个新的尾节点
    return newNode;         // 返回新节点的指针
}

// 在双向链表末尾插入新节点
void insertAtEndDoubly(DoublyListNode** head, int data) {
    DoublyListNode* newNode = createDoublyNode(data); // 创建一个新节点
    if (*head == NULL) {  // 如果链表为空
        *head = newNode;  // 将新节点设置为头节点
    } else {
        DoublyListNode* temp = *head;
        while (temp->next != NULL) { // 遍历链表找到尾节点
            temp = temp->next;
        }
        temp->next = newNode;  // 将新节点连接到尾节点
        newNode->prev = temp;  // 将尾节点连接到新节点
    }
}

// 打印双向链表
void printDoublyList(DoublyListNode* head) {
    DoublyListNode* current = head; // 从头节点开始遍历链表
    while (current != NULL) {       // 直到遍历到链表的末尾
        printf("%d <-> ", current->data); // 打印当前节点的数据
        current = current->next;    // 将当前节点指针移动到下一个节点
    }
    printf("NULL\n"); // 打印链表的末尾
}

void freeDoublyList(DoublyListNode* head) {
    DoublyListNode* current = head;
    DoublyListNode* next;

    while (current != NULL) {
        next = current->next; // 保存下一个节点的指针
        free(current); // 释放当前节点的内存
        current = next; // 将指针移动到下一个节点
    }
}

int main() {
    DoublyListNode* head = NULL; // 定义双向链表的头节点

    // 在末尾插入节点
    insertAtEndDoubly(&head, 1);
    insertAtEndDoubly(&head, 2);
    insertAtEndDoubly(&head, 3);

    printf("Doubly Linked List: ");
    printDoublyList(head); // 打印双向链表

    freeDoublyList(head);

    return 0;
}

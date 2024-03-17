#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

ListNode* createNode(int data);
void insertAtBeginning(ListNode** head, int data);
void insertAtEnd(ListNode** head, int data);
void deleteNode(ListNode** head, int key);
void printList(ListNode* head);
void freeList(ListNode** head);

#endif

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// 定义双向链表节点结构体
typedef struct DoublyListNode {
    int data;                   // 节点存储的数据
    struct DoublyListNode *prev; // 指向前一个节点的指针
    struct DoublyListNode *next; // 指向后一个节点的指针
} DoublyListNode;

// 创建新的双向链表节点
DoublyListNode* createDoublyNode(int data);

// 在双向链表末尾插入新节点
void insertAtEndDoubly(DoublyListNode** head, int data);

// 打印双向链表
void printDoublyList(DoublyListNode* head);

//释放双向链表内存
void freeDoublyList(DoublyListNode* head);

#endif 
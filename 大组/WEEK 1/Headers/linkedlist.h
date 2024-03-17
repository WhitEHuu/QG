#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

//定义单向链表节点结构体
typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

//创建新的单向链表节点
ListNode* createNode(int data);

//在单向链表头插入新节点
void insertAtBeginning(ListNode** head, int data);

//在单向链表尾插入新节点
void insertAtEnd(ListNode** head, int data);

//删除单向链表中的一个指定节点
void deleteNode(ListNode** head, int key);

//打印单向链表
void printList(ListNode* head);

//释放单向链表内存
void freeList(ListNode** head);

#endif

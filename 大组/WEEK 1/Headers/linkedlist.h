#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

ListNode* createNode(int data);// 创建新的单链表节点

void insertAtBeginning(ListNode** head, int data);// 在单链表头部插入新节点

void insertAtEnd(ListNode** head, int data);// 在单链表末尾插入新节点

void deleteNode(ListNode** head, int key);// 删除单链表中的指定节点

void printList(ListNode* head);// 打印单链表

void freeList(ListNode** head);// 释放单链表内存

ListNode* rearrangeOddEven(ListNode* head);//链表中的奇偶互换位置

ListNode* findMiddle(ListNode* head);//寻找链表中点

bool hasCycle(ListNode* head);//判断链表是否成环

ListNode* reverseList_1(ListNode* head);//非递归方法反转链表

ListNode* reverseList_2(ListNode* head);//递归方法反转链表


// 定义双向链表节点结构体
typedef struct DoublyListNode {
    int data;                   // 节点存储的数据
    struct DoublyListNode *prev; // 指向前一个节点的指针
    struct DoublyListNode *next; // 指向后一个节点的指针
} DoublyListNode;

DoublyListNode* createDoublyNode(int data);// 创建新的双向链表节点

void insertAtEndDoubly(DoublyListNode** head, int data);// 在双向链表末尾插入新节点

void printDoublyList(DoublyListNode* head);// 打印双向链表

void freeDoublyList(DoublyListNode* head);//释放双向链表内存

#endif
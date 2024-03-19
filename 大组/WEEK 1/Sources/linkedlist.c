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

//链表中的奇偶互换位置
ListNode* rearrangeOddEven(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}

//寻找链表中点
ListNode* findMiddle(ListNode* head){
    if (head==NULL){
        return NULL;
    }
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL){  //快指针没走到最后一个或者倒数第二个
        slow=slow->next;  //慢指针走一个节点
        fast=fast->next->next;  //快指针走两个节点
    }
    return slow; //当快指针走完链表或者走到倒数第二个的时候，慢指针即为链表中点
}

//判断链表是否成环
bool hasCycle(ListNode* head) {
    if (head == NULL || head->next == NULL) {  //判断链表节点大于等于两个，否则不会成环
        return false;
    }
    ListNode* slow = head;   //慢指针从头部节点开始走
    ListNode* fast = head->next;   //快指针从第二个节点开始走
    while (fast != slow) {  //判断快慢指针是否重叠
        if (fast == NULL || fast->next == NULL) {  //判断快指针是否走到链表尾部
            return false;  //若走到链表尾部则该链表一定不成环
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true; //当快慢指针重叠时，即可证明该链表已成环
}

//非递归方法反转链表
ListNode* reverseList_1(ListNode* head) {
    ListNode* prev = NULL; //用来保存当前节点的前一个节点
    ListNode* current = head; //用来保存当前节点
    ListNode* next = NULL; //用来保存当前节点的下一个节点
    while (current != NULL) {
        next = current->next;  //保存当前节点的下一个节点
        current->next = prev;  //当前节点指向上一个节点，实现反转
        prev = current;  //prev指针移动到当前节点
        current = next;  //current指针移向下一个节点
    }
    return prev; //返回反转后的链表头节点
}

//递归方法反转链表
ListNode* reverseList_2(ListNode* head){
    if (head == NULL || head->next == NULL) { //先判断该链表是否为空或者只有一个节点
        return head; //若满足上述条件，则直接返回head
    }
    ListNode* newHead = reverseList_2(head->next); 
    /*调用递归函数,将以head->为头节点的子链表进行反转
    并将反转后的新头节点保存在newHead中*/
    head->next->next = head;
    head->next = NULL;
    /*将 head->next->next 指向 head
    实现了当前节点和下一个节点的指针方向反转
    并将 head->next 置为 NULL，断开原来的连接，以防止出现环*/
    return newHead;
    //返回newHead,即反转后的链表的头节点
}


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
    ListNode* head = NULL;
    ListNode* Middle=NULL;
    DoublyListNode* Dhead=NULL;

    char choice;
    int data, key;

    do {
        printf("\nChoose an operation:\n");
        printf("a. Create a new node\n");
        printf("b. Insert at beginning\n");
        printf("c. Insert at end\n");
        printf("d. Delete node\n");
        printf("e. Rearrange odd and even positions\n");
        printf("f. Find middle node\n");
        printf("g. Check if cycle exists\n");
        printf("h. Reverse list (iterative)\n");
        printf("i. Reverse list (recursive)\n");
        printf("j. Print list\n");
        printf("k. Creat a new doubly-node\n");
        printf("l. Insert at end in doubly linked list\n");
        printf("m. Print doubly linked list\n");
        printf("n. Free doubly linked list\n");
        printf("o. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                ListNode* newNode1 = createNode(data);
                break;
            case 'b':
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 'c':
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 'd':
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 'e':
                head = rearrangeOddEven(head);
                break;
            case 'f':
                Middle = findMiddle(head);
                if (Middle!= NULL) {
                    printf("Middle node value: %d\n", Middle->data);
                } else {
                    printf("List is empty\n");
                }
                break;
            case 'g':
                if (hasCycle(head)) {
                    printf("Cycle exists in the list\n");
                } else {
                    printf("No cycle in the list\n");
                }
                system("pause");
                break;
            case 'h':
                head = reverseList_1(head);
                break;
            case 'i':
                head = reverseList_2(head);
                break;
            case 'j':
                printList(head);
                system("pause");
                break;
            case 'k':
                printf("Enter data for the new doubly-node: ");
                scanf("%d", &data);
                DoublyListNode* newNode2 = createDoublyNode(data);
                break;
            case 'l':
                printf("Enter data to insert at end in doubly linked list: ");
                scanf("%d", &data);
                insertAtEndDoubly(&Dhead, data);
                break;
            case 'm':
                printDoublyList(Dhead);
                system("pause");
                break;
            case 'n':
                freeDoublyList(Dhead);
                head = NULL;
                break;
            case 'o':
                freeList(&head);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}
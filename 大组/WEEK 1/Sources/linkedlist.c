// 创建新的单链表节点
ListNode* createNode(int data) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode)); //分配内存以储存新的节点
    if (newNode == NULL) { //检查内存分配是否成功
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data; //设置节点数据
    newNode->next = NULL; //将下一个节点的指针设置为NULL
    return newNode;
}

// 在单链表头部插入新节点
void insertAtBeginning(ListNode** head, int data) {
    ListNode* newNode = createNode(data);   //建立一个新的节点
    newNode->next = *head;   //将新节点的指针指向头部节点的位置
    *head = newNode;   //更新头部节点指针，使其指向新插入的节点
}

// 在单链表末尾插入新节点
void insertAtEnd(ListNode** head, int data) {
    ListNode* newNode = createNode(data);  //建立一个新的节点
    if (*head == NULL) {  //判断链表是否为空
        *head = newNode;  //若链表为空，则将新节点作为头节点
    } else {  //若链表不为空，
        ListNode* temp = *head; //创建临时节点指向头节点
        while (temp->next != NULL) { //找到链表中最后一个节点
            temp = temp->next;
        }
        temp->next = newNode; //将新节点连接到标尾
    }
}

// 删除单链表中的指定节点
void deleteNode(ListNode** head, int key) {
    ListNode* temp = *head; //创建一个临时节点指向链表头部
    ListNode* prev = NULL; //创建一个指针用于追踪当前节点的前一个节点

    if (temp != NULL && temp->data == key) {  //如果头部节点就是要删除的节点
        *head = temp->next;  //将头部指向下一个节点
        free(temp);  //释放临时节点的内存
        return;
    }

    while (temp != NULL && temp->data != key) {  //遍历链表直到找到指定节点或到达链表末尾
        prev = temp;  //prev指向当前节点
        temp = temp->next;  //移动到下一个节点
    }

    if (temp == NULL) {  //如果遍历完链表仍未找到指定的节点
        printf("Key not found in the list\n");
        return;
    }

    prev->next = temp->next; //将前一个节点的next指针跳过当前节点，直接指向当前节点的下一个节点
    free(temp); //释放当前节点的内存
}

// 打印单链表
void printList(ListNode* head) {
    ListNode* current = head; //创建一个指针指向链表的头节点
    while (current != NULL) {  //遍历链表
        printf("%d -> ", current->data);  //打印当前节点的数据
        current = current->next;  //将指针移动到下一个节点
    }
    printf("NULL\n");  //打印链表末尾表示NULL
}

// 释放单链表内存
void freeList(ListNode** head) {
    ListNode* current = *head;  //创建一个指针指向链表的头节点
    ListNode* next;
    while (current != NULL) {  //遍历链表
        next = current->next;  //保存下一个节点的指针
        free(current);  //释放当前节点的内存
        current = next;  //将指针移向下一个节点
    }
    *head = NULL;  //将头指针设置为NULL
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

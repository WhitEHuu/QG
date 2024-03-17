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

    //奇数偶数互换
    rearrangeOddEven(head);
    printf("List after rerangeOddEven: ");
    printList(head);

    //寻找链表重点
    ListNode* middle = findMiddle(head);
    if (middle != NULL) {
        printf("Middle element of the list is: %d\n", middle->data);
    } else {
        printf("List is empty\n");
    }

    //判断链表是否成环
    if (hasCycle(head)) {
        printf("The linked list has a cycle.\n");
    } else {
        printf("The linked list does not have a cycle.\n");
    }
    
    // 删除节点
    deleteNode(&head, 3);

    printf("List after deleting node with key 3: ");
    printList(head);

    //利用非递归方法反转链表
    head = reverseList_1(head);
    
    printf("The first time Reversed list: ");
    printList(head);

    //利用递归方法反转链表
    head = reverseList_2(head);
    
    printf("The second time Reversed list: ");
    printList(head);

    // 释放链表内存
    freeList(&head);

    return 0;
}

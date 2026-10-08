#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next; 

}Node;


//创建一个节点
Node *creat(int a){
    Node *p = malloc(sizeof(Node));
    p->data = a;
    p->next = NULL;
    return p;
}

//清空链表
void Free(Node* head){
    Node* record;
    while (head != NULL){ //逐个节点free掉
        record = head->next; //用 "record"记下下一个节点
        free(head); //清空当前节点
        head = record; //将记录下来的剩下节点放回head中
    }
}

//头插
Node *insertH(Node *head,int n){
    Node* p = creat(n);//创建一个节点
    p->next = head; //让新建节点的下一个节点为原来的头节点，此时新建节点变为新的头节点，便实现了在头部新增一项的功能
    return p;//p为新的头节点的指针，故返回p
}

//尾插
Node *insertT(Node* head,int n){
    Node* p = creat(n);//创建一个节点
    Node *search = head; //没有直接用头指针，而是定义一个名为search的新指针将其赋值为头指针，用于找到链表的尾巴
    while (search->next != NULL){
        search = search->next; //只要search的下一个节点不为空，就一直向后推，直到找到最后一项为止
    }
    search->next = p; //原来最后一项的后一项设为p，便实现了在末尾新增一项的功能
    return head; //返回的依旧是最初的指针
}

//打印
void type(Node* head){
    Node*search = head; 
    while (search != NULL){
        printf("%d->",search->data); //逐项打印
        search = search->next;
    }
    printf("NULL\n");
}

//测量链表长度(原本这部分代码是直接写在find函数下面的，但因为删除操作时也要用上，故单独写出来)
int Length(Node* head){   
    int length = 0;
    Node*search = head; 
    while (search != NULL){ //先遍历链表，记录其长度
        search = search->next;
        length ++;
    }
    return length;
}

//查找元素
void find(Node* head,int target){
    int count = 0;
    Node*search = head; 
    int length = Length(search);
    while (search != NULL && search->data != target){ //当到链表链表末端或找到目标时结束计数
        search = search->next;
        count ++;
    }
    if(search == NULL){
        printf("false\n"); //未找到目标则输出"false"
    }
    else{
        printf("the closest distance to %d is :%d\n",target,count); //找到目标则输出离头节点最近的目标的距离
    }
}

//删除 
Node  *delete(Node* head,int n){
    int length = Length(head); //先查询链表长度
    Node *search = head,*pre = NULL;
    if(length<n){
        printf("false\n");
    }
    else{
        if(n == 1){
            head = search->next;  
            free(search);
            search = NULL;
            return head;
        }
        else{
            for(int i=1;i<n;i++){
                pre = search;
                search = search->next;//交替向前
            }
            pre->next = search->next;
        }
        printf("true\n");
    }
    free(search);
    return head;
}




int main(){
    Node *head = malloc(sizeof(Node)); //定义并初始化head头节点
    head->data = 0;
    head->next = NULL;

    insertT(head,7);
    head =insertH(head,0);
    head = insertH(head,2);
    insertT(head,11);
    insertT(head,16);
    type(head);

    find(head,9);
    find(head,11);
    find(head,0);

    insertT(head,7);
    delete(head,5);
    // delete(head,10);
    //delete(head,1);
    type(head);

    //清空所有指针(ps:写到"删除与更改"才了解到"free"的用法及其重要性）)
    Free(head);
    return 0;
}
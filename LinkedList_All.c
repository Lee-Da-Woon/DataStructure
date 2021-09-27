#include <stdio.h>
#include <stdlib.h>

struct NODE {
    struct NODE* next;
    int data;
};

void addNode(struct NODE* target, int data) {
    struct NODE* newNode = malloc(sizeof(struct NODE));
    newNode->next = target->next;
    newNode->data = data;

    target->next = newNode;
}
int removeNode(struct NODE* target,int data) {

    while(1){
        struct NODE* removeNode = target->next;
        if((target->next)->data == data)
        {
            target->next = removeNode->next;
            break;
        }
        else{
            target = target->next;
            if(target->next==NULL)
            {
                return 1;
            }
        }
    }
    free(removeNode);
    return 2;
}

int main() {
    int sel=NULL;
    struct NODE* head = malloc(sizeof(struct NODE));

    head->next = NULL;
    while (1)
    {
        printf("1. ��� �߰�\n2. ��� ����\n3. ������ ���\n4. ���α׷� ����\n");
        printf("�޴��� �����ϼ��� : ");
        scanf_s("%d", &sel);
        if (sel == 1) {
            int a;
            printf("������ ������ �Է��ϼ��� : ");
            scanf_s("%d", &a);
            addNode(head, a);
        }
        else if (sel == 2) {
            struct NODE* curr = head->next;
            int b,c=0;
            if(curr == NULL){
                printf("������ ��尡 �����ϴ�.\n");
                continue;
            }
                
            while (curr != NULL)
            {
                printf("%d\n", curr->data);
                curr = curr->next;
            }
            printf("������ ����� �����͸� �Է��ϼ��� : ");
            scanf_s("%d",&b);
            c = removeNode(head,b);
            switch(c){
                case 1:
                printf("���� �������Դϴ�.\n");
                break;
                case 2:
                printf("���Ű� �Ϸ�Ǿ����ϴ�.\n");
                
            }
            
        }
        else if (sel == 3) {
            struct NODE* curr = head->next;
            while (curr != NULL)
            {
                printf("%d\n", curr->data);
                curr = curr->next;
            }
        }
        else if (sel == 4) break;
        else 
            continue;
    }
    return 0;
}

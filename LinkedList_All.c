#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE {
    struct NODE* next;
    int data;
    char nodeName[20];
};

void addNode(struct NODE* target, int data,char *name) {
    struct NODE* newNode = malloc(sizeof(struct NODE));
    newNode->next = target->next;
    newNode->data = data;
    strcpy((newNode->nodeName),name);

    printf("%s\n",name);

    target->next = newNode;
}
int removeNode(struct NODE* target,char *name) {

    while(1){
        struct NODE* removeNode = target->next;
        if(strcmp((target->next)->nodeName,name))
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
    int sel=0;
    struct NODE* head = malloc(sizeof(struct NODE));

    head->next = NULL;
    while (1)
    {
        printf("1. ��� �߰�\n2. ��� ����\n3. ������ ���\n4. ���α׷� ����\n");
        printf("�޴��� �����ϼ��� : ");
        scanf("%d", &sel);
        if (sel == 1) {
            int a;
            char name[20];
            printf("������ ������ ��� �̸��� �Է��ϼ��� : ");
            scanf_s("%d %s", &a,name);
            addNode(head, a,name);
        }
        else if (sel == 2) {
            struct NODE* curr = head->next;
            int c=0;
            char name[20];
            if(curr == NULL){
                printf("������ ��尡 �����ϴ�.\n");
                continue;
            }
                
            while (curr != NULL)
            {
                printf("%s\n", curr->nodeName);
                curr = curr->next;
            }
            printf("������ ����� �̸��� �Է��ϼ��� : ");
            scanf_s("%s",name);
            c = removeNode(head,name);
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
                printf("%s : %d\n", curr->nodeName,curr->data);
                curr = curr->next;
            }
        }
        else if (sel == 4) break;
        else 
            continue;
    }
    return 0;
}

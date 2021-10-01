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
        printf("1. 노드 추가\n2. 노드 삭제\n3. 데이터 출력\n4. 프로그램 종료\n");
        printf("메뉴를 선택하세요 : ");
        scanf("%d", &sel);
        if (sel == 1) {
            int a;
            char name[20];
            printf("저장할 정수와 노드 이름을 입력하세요 : ");
            scanf_s("%d %s", &a,name);
            addNode(head, a,name);
        }
        else if (sel == 2) {
            struct NODE* curr = head->next;
            int c=0;
            char name[20];
            if(curr == NULL){
                printf("제거할 노드가 없습니다.\n");
                continue;
            }
                
            while (curr != NULL)
            {
                printf("%s\n", curr->nodeName);
                curr = curr->next;
            }
            printf("제거할 노드의 이름을 입력하세요 : ");
            scanf_s("%s",name);
            c = removeNode(head,name);
            switch(c){
                case 1:
                printf("없는 데이터입니다.\n");
                break;
                case 2:
                printf("제거가 완료되었습니다.\n");
                
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

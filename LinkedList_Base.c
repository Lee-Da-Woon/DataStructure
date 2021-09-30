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
        printf("1. 노드 추가\n2. 노드 삭제\n3. 데이터 출력\n4. 프로그램 종료\n");
        printf("메뉴를 선택하세요 : ");
        scanf_s("%d", &sel);
        if (sel == 1) {
            int a;
            printf("저장할 정수를 입력하세요 : ");
            scanf_s("%d", &a);
            addNode(head, a);
        }
        else if (sel == 2) {
            struct NODE* curr = head->next;
            int b,c=0;
            if(curr == NULL){
                printf("제거할 노드가 없습니다.\n");
                continue;
            }
                
            while (curr != NULL)
            {
                printf("%d\n", curr->data);
                curr = curr->next;
            }
            printf("제거할 노드의 데이터를 입력하세요 : ");
            scanf_s("%d",&b);
            c = removeNode(head,b);
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

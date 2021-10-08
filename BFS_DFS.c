#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    struct TreeNode *left;
    int data;
    struct TreeNode *right;
}TreeNode;

int queue[10000];
int stack[10000];
int head=0,tail=0,pos=0;

void BFS(TreeNode* root){
    if(root != NULL){
        if(root->left!=NULL)
            queue[tail++]=root->left;
        if(root->right!=NULL)
            queue[tail++]=root->right;
        printf("--%d\n",root->data);
        if(queue[head]!=NULL){
            BFS(queue[head++]);
        }
    }
    
}
void DFS(TreeNode* root){
if(root != NULL){
    if(root->left!=NULL)
        stack[pos++]=root->left;
    if(root->right!=NULL)
        stack[pos++]=root->right;
    printf("--%d\n",root->data);
    if(stack[pos-1]!=NULL){
        pos--;
        DFS(stack[pos]);
        }
    }
}

int main(){
    TreeNode *n1,*n2,*n3,*n4,*n5;
    //노드 생성
    n1 = (TreeNode*)malloc(sizeof(TreeNode));
    n2 = (TreeNode*)malloc(sizeof(TreeNode));
    n3 = (TreeNode*)malloc(sizeof(TreeNode));
    n4 = (TreeNode*)malloc(sizeof(TreeNode));
    n5 = (TreeNode*)malloc(sizeof(TreeNode));

    n1->data = 10;
    n1->left = n2;
    n1->right = n3;
    n2->data = 20;
    n2->left = NULL;
    n2->right = NULL;
    n3->data = 30;
    n3->left = n4;
    n3->right = n5;
    n4->data = 11;
    n4->left = NULL;
    n4->right = NULL;
    n5->data = 12;
    n5->left = NULL;
    n5->right = NULL;


    printf("===== BFS =====");
    printf("\n--root");
    BFS(n1);
    printf("\n===== DFS =====");
    printf("\n--root");
    DFS(n1);

    free(n1);
    free(n2);
    free(n3);


}

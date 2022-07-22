#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

int main(void)
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *cur = NULL;

    Node *newNode =NULL;
    int readData;

  //데이터를 입력 받는 과정
    while(1)
    {
        printf("자연수 입력: ");
        scanf("%d",&readData);
        if(readData < 1)
        {
            break;
        }

      //노드의 추가과정
        newNode = (Node*)malloc(sizeof(Node));  //노드(바구니) 생성
        newNode->data = readData; //노드에 데이터 저장
        newNode->next = NULL;  //노드의 next를 NULL로 초기화

        if(head == NULL) //첫번째 노드라면
        {
            head = newNode;  //첫번째 노드를 head가 가리키게 함
        }
        else //두번째 이후 노드라면
        {
            tail->next = newNode;
        }

        tail = newNode; //노드의 끝을 tail이 가리키게 함
    }
    printf("\n");

  //입력 받은 데이터의 출력과정
    printf("입력 받은 데이터의 전체출력! \n");
    if(head == NULL)
    {
        printf("저장된 자연수가 존재하지 않습니다. \n");
    }
    else
    {
        cur = head;
        printf("%d", cur->data); // 첫번째 데이터의 출력

        while(cur->next !=NULL) //두번째 이후의 데이터 출력
        {
            cur = cur->next;
            printf("%d", cur->data);

        }
    }
    printf("\n\n");

  //메모리의 해체과정
    if(head == NULL)
    {
        return 0; //해치할 노드가 존재하지 않는다
    }
    else
    {
        Node *delNode = head;
        Node *delNextNode = head->next;

        printf("%d을(를) 삭제합니다. \n", delNode->data);
        free(delNode); //첫번째 노드 삭제

        while(delNextNode != NULL) //두 번째 이후 노드 삭제
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;

            printf("%d을(를) 삭제합니다. \n", delNode->data);
            free(delNode);
        }
    }

    return 0;
}
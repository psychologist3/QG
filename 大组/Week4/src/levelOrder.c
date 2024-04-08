#include"record.h"
// ��ʼ������
Queue* initQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->end = NULL;
    return q;
}

// ��Ӳ���
void enqueue(Queue* q, treepoint node) {
    Queuepoint* newQueuePoint = (Queuepoint*)malloc(sizeof(Queuepoint));
    newQueuePoint->head = node;
    newQueuePoint->next = NULL;
    if (q->head == NULL) {
        q->head = newQueuePoint;
        q->end = newQueuePoint;
    } else {
        q->end->next = newQueuePoint;
        q->end = newQueuePoint;
    }
}

// ���Ӳ���
treepoint dequeue(Queue* q) {
    if (q->head == NULL) {
        return NULL;
    }
    Queuepoint* temp = q->head;
    treepoint node = temp->head;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->end = NULL;
    }
    free(temp);
    return node;
}

// �����������������
void levelOrder(treepoint root) {
    if (root == NULL) {
        return;
    }
    Queue* q = initQueue();
    enqueue(q, root);
    while (q->head != NULL) {
        int levelSize = q->end - q->head + 1; // ��¼��ǰ��Ľڵ�����
        for (int i = 0; i < levelSize; i++) {
            treepoint current = dequeue(q);
            printf("%d ", current->number);
            if (current->left != NULL) {
                enqueue(q, current->left);
            }
            if (current->right != NULL) {
                enqueue(q, current->right);
            }
        }
        printf("\n"); // ��ӡ��һ�����
    }
    free(q);
}
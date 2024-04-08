#include"record.h"
// 初始化队列
Queue* initQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->end = NULL;
    return q;
}

// 入队操作
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

// 出队操作
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

// 层序遍历二叉排序树
void levelOrder(treepoint root) {
    if (root == NULL) {
        return;
    }
    Queue* q = initQueue();
    enqueue(q, root);
    while (q->head != NULL) {
        int levelSize = q->end - q->head + 1; // 记录当前层的节点数量
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
        printf("\n"); // 打印完一层后换行
    }
    free(q);
}
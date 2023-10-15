#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct PriorityQueue {
    int heap[MAX_SIZE];
    int size;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void initialize(struct PriorityQueue* pq) {
    pq->size = 0;
}

int parent(int index) {
    return (index - 1) / 2;
}

int leftChild(int index) {
    return (2 * index) + 1;
}

int rightChild(int index) {
    return (2 * index) + 2;
}

void enqueue(struct PriorityQueue* pq, int value) {
    if (pq->size >= MAX_SIZE) {
        printf("Priority queue is full.\n");
        return;
    }

    int index = pq->size;
    pq->heap[index] = value;
    pq->size++;

    while (index > 0 && pq->heap[index] < pq->heap[parent(index)]) {
        swap(&pq->heap[index], &pq->heap[parent(index)]);
        index = parent(index);
    }
}

void heapify(struct PriorityQueue* pq, int index) {
    int smallest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < pq->size && pq->heap[left] < pq->heap[smallest])
        smallest = left;

    if (right < pq->size && pq->heap[right] < pq->heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&pq->heap[index], &pq->heap[smallest]);
        heapify(pq, smallest);
    }
}

int dequeue(struct PriorityQueue* pq) {
    if (pq->size <= 0) {
        printf("Priority queue is empty.\n");
        return -1;
    }

    int value = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;

    heapify(pq, 0);

    return value;
}

void display(struct PriorityQueue* pq) {
    if (pq->size <= 0) {
        printf("Priority queue is empty.\n");
        return;
    }

    printf("Priority queue: ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->heap[i]);
    }
    printf("\n");
}

int main() {
    struct PriorityQueue pq;
    initialize(&pq);

    enqueue(&pq, 10);
    enqueue(&pq, 30);
    enqueue(&pq, 20);
    enqueue(&pq, 50);
    enqueue(&pq, 40);

    display(&pq);

    int dequeuedValue = dequeue(&pq);
    printf("Dequeued value: %d\n", dequeuedValue);

    display(&pq);

    return 0;
}


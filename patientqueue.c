#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Patient {
    int id;
    char name[50];
    int priority;
};

struct Queue {
    struct Patient items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize the queue
void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to enqueue a patient with priority
void enqueue(struct Queue* queue, struct Patient patient) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue patient.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
        queue->items[queue->rear] = patient;
    } else {
        int i;
        for (i = queue->rear; i >= queue->front; i--) {
            if (patient.priority < queue->items[i].priority)
                queue->items[i + 1] = queue->items[i];
            else
                break;
        }
        queue->items[i + 1] = patient;
        queue->rear++;
    }
    printf("Enqueued patient: %s (Priority: %d)\n", patient.name, patient.priority);
}

// Function to dequeue the highest priority patient
struct Patient dequeue(struct Queue* queue) {
    struct Patient emptyPatient = {-1, "", 0};
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue patient.\n");
        return emptyPatient;
    }
    struct Patient patient = queue->items[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;
    printf("Dequeued patient: %s (Priority: %d)\n", patient.name, patient.priority);
    return patient;
}

// Function to display the patients in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Patients in the queue:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("ID: %d, Name: %s, Priority: %d\n", queue->items[i].id, queue->items[i].name, queue->items[i].priority);
    }
}

int main() {
    struct Queue patientQueue;
    initialize(&patientQueue);

    struct Patient p1 = {1, "John", 2};    // Priority: 2 (Cough)
    struct Patient p2 = {2, "Alice", 1};   // Priority: 1 (Heart Disease)
    struct Patient p3 = {3, "Mike", 3};    // Priority: 3 (Fever)
    struct Patient p4 = {4, "Emily", 2};   // Priority: 2 (Cough)

    enqueue(&patientQueue, p1);
    enqueue(&patientQueue, p2);
    enqueue(&patientQueue, p3);
    enqueue(&patientQueue, p4);

    display(&patientQueue);

    struct Patient highestPriorityPatient = dequeue(&patientQueue);
    printf("Highest Priority Patient: ID: %d, Name: %s, Priority: %d\n", highestPriorityPatient.id,
           highestPriorityPatient.name, highestPriorityPatient.priority);

    display(&patientQueue);

    return 0;
}

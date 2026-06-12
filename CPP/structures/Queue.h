#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class ActivityNode {

public:
    string activity;
    ActivityNode* next;

    ActivityNode(string act) {
        activity = act;
        next = nullptr;
    }
};

class ActivityQueue {

private:
    ActivityNode* front;
    ActivityNode* rear;

public:

    ActivityQueue() {
        front = rear = nullptr;
    }

    void enqueue(string activity) {

        ActivityNode* newNode = new ActivityNode(activity);

        if (front == nullptr) {

            front = rear = newNode;

            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void displayLog() {

        ActivityNode* current = front;

        while (current != nullptr) {

            cout << current->activity << endl;

            current = current->next;
        }
    }
};

#endif
# queue.py

from datetime import datetime


class ActivityNode:

    def __init__(self, activity):

        self.activity = activity
        self.next = None


class ActivityQueue:

    def __init__(self):

        self.front = None
        self.rear = None


    def enqueue(self, activity):

        timestamp = datetime.now().strftime("%H:%M:%S")

        new_node = ActivityNode(
            f"[{timestamp}] {activity}"
        )

        if self.front is None:

            self.front = self.rear = new_node

            return

        self.rear.next = new_node

        self.rear = new_node


    def dequeue(self):

        if self.front is None:
            return None

        temp = self.front

        self.front = self.front.next

        if self.front is None:
            self.rear = None

        return temp.activity


    def display_log(self):

        if self.front is None:

            print("Activity log kosong.")

            return

        current = self.front

        while current:

            print(current.activity)

            current = current.next
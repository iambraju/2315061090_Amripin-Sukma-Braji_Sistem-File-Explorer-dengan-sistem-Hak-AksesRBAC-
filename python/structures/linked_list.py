# linked_list.py

from structures.file_node import FileNode


class LinkedList:

    def __init__(self):
        self.head = None


    # CREATE FILE
    def insert_file(self, filename):

        new_node = FileNode(filename)

        if self.head is None:
            self.head = new_node
            return

        current = self.head

        while current.next:
            current = current.next

        current.next = new_node


    # DISPLAY FILE
    def display_files(self):

        current = self.head

        if current is None:
            print("Tidak ada file.")
            return

        while current:

            print("- " + current.filename)

            current = current.next


    # SEARCH FILE
    def search_file(self, filename):

        current = self.head

        while current:

            if current.filename == filename:
                return current

            current = current.next

        return None


    # DELETE FILE
    def delete_file(self, filename):

        if self.head is None:
            return False

        if self.head.filename == filename:

            self.head = self.head.next

            return True

        prev = None
        current = self.head

        while current:

            if current.filename == filename:

                prev.next = current.next

                return True

            prev = current
            current = current.next

        return False


    # RENAME FILE
    def rename_file(self, old_name, new_name):

        file_node = self.search_file(old_name)

        if file_node:

            file_node.filename = new_name

            return True

        return False


    # GET ALL FILES
    def get_files(self):

        files = []

        current = self.head

        while current:

            files.append(current.filename)

            current = current.next

        return files


    # COUNT FILES
    def count_files(self):

        count = 0

        current = self.head

        while current:

            count += 1

            current = current.next

        return count


    # CHECK EMPTY
    def is_empty(self):

        return self.head is None
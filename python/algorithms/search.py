# search.py

def linear_search(linked_list, target):

    current = linked_list.head

    while current:

        if current.filename == target:
            return True

        current = current.next

    return False
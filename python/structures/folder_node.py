# folder_node.py

from structures.linked_list import LinkedList


class FolderNode:

    def __init__(self, folder_name):

        self.folder_name = folder_name

        # daftar subfolder
        self.children = []

        # linked list file dalam folder
        self.files = LinkedList()
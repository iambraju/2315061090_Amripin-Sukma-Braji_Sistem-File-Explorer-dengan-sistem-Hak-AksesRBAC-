# tree.py

from structures.folder_node import FolderNode
from algorithms.traversal import dfs_traversal
from algorithms.search import linear_search
from algorithms.sort import bubble_sort


class FileTree:

    def __init__(self):

        self.root = FolderNode("root")

        # folder default
        self.create_folder("root", "Documents")
        self.create_folder("root", "Images")
        self.create_folder("root", "Music")

    # ==========================
    # FIND FOLDER (DFS)
    # ==========================
    def find_folder(self, current_node, folder_name):

        if current_node.folder_name == folder_name:
            return current_node

        for child in current_node.children:

            result = self.find_folder(child, folder_name)

            if result:
                return result

        return None

    # ==========================
    # CREATE FOLDER
    # ==========================
    def create_folder(self, parent_name, folder_name):

        parent = self.find_folder(self.root, parent_name)

        if parent is None:
            return False

        # cek folder duplikat
        for child in parent.children:

            if child.folder_name == folder_name:
                return False

        new_folder = FolderNode(folder_name)

        parent.children.append(new_folder)

        return True

    # ==========================
    # DELETE FOLDER
    # ==========================
    def delete_folder(self, parent_name, folder_name):

        parent = self.find_folder(self.root, parent_name)

        if parent is None:
            return False

        for child in parent.children:

            if child.folder_name == folder_name:

                parent.children.remove(child)

                return True

        return False

    # ==========================
    # CREATE FILE
    # ==========================
    def create_file(self, folder_name, filename):

        folder = self.find_folder(self.root, folder_name)

        if folder is None:
            return False

        # cek file duplikat
        if folder.files.search_file(filename):
            return False

        folder.files.insert_file(filename)

        return True

    # ==========================
    # DELETE FILE
    # ==========================
    def delete_file(self, folder_name, filename):

        folder = self.find_folder(self.root, folder_name)

        if folder:

            return folder.files.delete_file(filename)

        return False

    # ==========================
    # RENAME FILE
    # ==========================
    def rename_file(self, folder_name, old_name, new_name):

        folder = self.find_folder(self.root, folder_name)

        if folder:

            return folder.files.rename_file(old_name, new_name)

        return False

    # ==========================
    # SEARCH FILE
    # ==========================
    def search_file(self, folder_name, filename):

        folder = self.find_folder(self.root, folder_name)

        if folder:

            return linear_search(folder.files, filename)

        return False

    # ==========================
    # GLOBAL SEARCH
    # ==========================
    def global_search(self, current_node, filename):

        if current_node.files.search_file(filename):
            return current_node.folder_name

        for child in current_node.children:

            result = self.global_search(child, filename)

            if result:
                return result

        return None

    # ==========================
    # SORT FILE
    # ==========================
    def sort_files(self, folder_name):

        folder = self.find_folder(self.root, folder_name)

        if folder:

            return bubble_sort(folder.files)

        return []

    # ==========================
    # DISPLAY TREE
    # ==========================
    def display_tree(self):

        dfs_traversal(self.root)
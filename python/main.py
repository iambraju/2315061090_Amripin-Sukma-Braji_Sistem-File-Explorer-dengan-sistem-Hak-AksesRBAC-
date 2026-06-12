# main.py

from structures.tree import FileTree
from structures.queue import ActivityQueue


# ===================================
# PILIH ROLE
# ===================================
def choose_role():

    print("\n=================================")
    print("      FILE EXPLORER SYSTEM")
    print("     Role Based Access Control")
    print("=================================")
    print("1. Admin")
    print("2. Editor")
    print("3. Viewer")
    print("0. Exit")

    choice = input("\nChoose Role : ")

    roles = {
        "1": "Admin",
        "2": "Editor",
        "3": "Viewer"
    }

    return roles.get(choice)


# ===================================
# MENU
# ===================================
def admin_menu():

    print("\n========== ADMIN MENU ==========")

    print("1. Create Folder")
    print("2. Delete Folder")
    print("3. Create File")
    print("4. Delete File")
    print("5. Rename File")
    print("6. Search File")
    print("7. Sort File")
    print("8. Display File System")
    print("9. Activity Log")
    print("0. Exit")


def editor_menu():

    print("\n========== EDITOR MENU ==========")

    print("1. Create File")
    print("2. Rename File")
    print("3. Search File")
    print("4. Display File System")
    print("0. Exit")


def viewer_menu():

    print("\n========== VIEWER MENU ==========")

    print("1. Search File")
    print("2. Display File System")
    print("0. Exit")


# ===================================
# HANDLER
# ===================================
def handle_create_folder(file_tree, activity_log):

    parent = input("Parent Folder : ")
    folder = input("New Folder Name : ")

    if file_tree.create_folder(parent, folder):

        activity_log.enqueue(f"Create Folder : {folder}")

        print("Folder berhasil dibuat.")

    else:

        print("Gagal membuat folder.")


def handle_delete_folder(file_tree, activity_log):

    parent = input("Parent Folder : ")
    folder = input("Folder Name : ")

    if file_tree.delete_folder(parent, folder):

        activity_log.enqueue(f"Delete Folder : {folder}")

        print("Folder berhasil dihapus.")

    else:

        print("Folder tidak ditemukan.")


def handle_create_file(file_tree, activity_log):

    folder = input("Folder : ")
    filename = input("File Name : ")

    if file_tree.create_file(folder, filename):

        activity_log.enqueue(f"Create File : {filename}")

        print("File berhasil dibuat.")

    else:

        print("Gagal membuat file.")


def handle_delete_file(file_tree, activity_log):

    folder = input("Folder : ")
    filename = input("File Name : ")

    if file_tree.delete_file(folder, filename):

        activity_log.enqueue(f"Delete File : {filename}")

        print("File berhasil dihapus.")

    else:

        print("File tidak ditemukan.")


def handle_rename_file(file_tree, activity_log):

    folder = input("Folder : ")

    old_name = input("Old Name : ")
    new_name = input("New Name : ")

    if file_tree.rename_file(folder, old_name, new_name):

        activity_log.enqueue(
            f"Rename File : {old_name} -> {new_name}"
        )

        print("Rename berhasil.")

    else:

        print("File tidak ditemukan.")


def handle_search_file(file_tree):
    
    filename = input("File Name : ")

    folder = file_tree.global_search(
        file_tree.root,
        filename
    )

    if folder:

        print()

        print("File ditemukan.")
        print("Lokasi :", folder)

    else:

        print()
        print("File tidak ditemukan.")


def handle_sort_file(file_tree):

    folder = input("Folder : ")

    sorted_files = file_tree.sort_files(folder)

    if len(sorted_files) == 0:

        print("Folder kosong.")

    else:

        print("\n===== Sorted Files =====")

        for file in sorted_files:

            print("-", file)


def handle_display_tree(file_tree):

    print("\n===== FILE SYSTEM =====\n")

    file_tree.display_tree()


def handle_activity_log(activity_log):

    print("\n===== ACTIVITY LOG =====\n")

    activity_log.display_log()


# ===================================
# MAIN
# ===================================
def main():

    file_tree = FileTree()
    activity_log = ActivityQueue()

    role = choose_role()

    if role is None:

        print("Program selesai.")

        return

    while True:

        # -------------------
        # ADMIN
        # -------------------
        if role == "Admin":

            admin_menu()

            choice = input("\nChoose : ")

            if choice == "1":
                handle_create_folder(file_tree, activity_log)

            elif choice == "2":
                handle_delete_folder(file_tree, activity_log)

            elif choice == "3":
                handle_create_file(file_tree, activity_log)

            elif choice == "4":
                handle_delete_file(file_tree, activity_log)

            elif choice == "5":
                handle_rename_file(file_tree, activity_log)

            elif choice == "6":
                handle_search_file(file_tree)

            elif choice == "7":
                handle_sort_file(file_tree)

            elif choice == "8":
                handle_display_tree(file_tree)

            elif choice == "9":
                handle_activity_log(activity_log)

            elif choice == "0":
                break


        # -------------------
        # EDITOR
        # -------------------
        elif role == "Editor":

            editor_menu()

            choice = input("\nChoose : ")

            if choice == "1":
                handle_create_file(file_tree, activity_log)

            elif choice == "2":
                handle_rename_file(file_tree, activity_log)

            elif choice == "3":
                handle_search_file(file_tree)

            elif choice == "4":
                handle_display_tree(file_tree)

            elif choice == "0":
                break


        # -------------------
        # VIEWER
        # -------------------
        else:

            viewer_menu()

            choice = input("\nChoose : ")

            if choice == "1":
                handle_search_file(file_tree)

            elif choice == "2":
                handle_display_tree(file_tree)

            elif choice == "0":
                break


if __name__ == "__main__":
    main()
# traversal.py

def dfs_traversal(folder, level=0):

    if level == 0:

        print(folder.folder_name)

    else:

        print("│   " * (level - 1) + "├── " + folder.folder_name)

    # tampilkan file
    current = folder.files.head

    while current:

        print(
            "│   " * level +
            "├── " +
            current.filename
        )

        current = current.next

    # subfolder
    for child in folder.children:

        dfs_traversal(child, level + 1)
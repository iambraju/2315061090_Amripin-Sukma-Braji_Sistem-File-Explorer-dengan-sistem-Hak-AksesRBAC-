# sort.py

def bubble_sort(linked_list):

    files = linked_list.get_files()

    n = len(files)

    for i in range(n):

        swapped = False

        for j in range(n - i - 1):

            if files[j] > files[j + 1]:

                files[j], files[j + 1] = files[j + 1], files[j]

                swapped = True

        if not swapped:
            break

    return files
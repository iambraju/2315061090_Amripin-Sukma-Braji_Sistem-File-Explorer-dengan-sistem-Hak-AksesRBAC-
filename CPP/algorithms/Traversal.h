#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include <iostream>
#include "../structures/FolderNode.h"

using namespace std;

class Traversal {

public:

    static void dfsTraversal(FolderNode* folder, int level = 0) {

        if (level == 0)
            cout << folder->folderName << endl;
        else
            cout << string((level - 1) * 4, ' ')
                 << "├── "
                 << folder->folderName
                 << endl;

        // tampilkan file
        FileNode* current = folder->files.getHead();

        while (current != nullptr) {

            cout << string(level * 4, ' ')
                 << "├── "
                 << current->filename
                 << endl;

            current = current->next;
        }

        // rekursi ke subfolder
        for (FolderNode* child : folder->children) {

            dfsTraversal(child, level + 1);

        }
    }
};

#endif
#ifndef FOLDERNODE_H
#define FOLDERNODE_H

#include <string>
#include <vector>
#include "LinkedList.h"

using namespace std;

class FolderNode {

public:

    // nama folder
    string folderName;

    // daftar subfolder (Tree)
    vector<FolderNode*> children;

    // daftar file (Linked List)
    LinkedList files;


    FolderNode(string name) {

        folderName = name;
    }
};

#endif
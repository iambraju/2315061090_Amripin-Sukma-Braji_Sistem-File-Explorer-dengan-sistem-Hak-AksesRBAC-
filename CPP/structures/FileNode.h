#ifndef FILENODE_H
#define FILENODE_H

#include <string>
using namespace std;

class FileNode {
public:
    string filename;
    FileNode* next;

    FileNode(string name) {
        filename = name;
        next = nullptr;
    }
};

#endif
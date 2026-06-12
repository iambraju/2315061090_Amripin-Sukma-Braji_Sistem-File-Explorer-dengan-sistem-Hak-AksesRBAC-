#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>

#include "FolderNode.h"
#include "../algorithms/Search.h"
#include "../algorithms/Sort.h"
#include "../algorithms/Traversal.h"

using namespace std;

class FileTree {

private:

    FolderNode* root;

public:

    FileTree() {

        root = new FolderNode("root");

        // Folder default
        createFolder("root", "Documents");
        createFolder("root", "Images");
        createFolder("root", "Music");
    }


    FolderNode* getRoot() {

        return root;
    }


    // =====================
    // FIND FOLDER (DFS)
    // =====================
    FolderNode* findFolder(FolderNode* currentNode, string folderName) {

        if (currentNode->folderName == folderName)
            return currentNode;

        for (FolderNode* child : currentNode->children) {

            FolderNode* result = findFolder(child, folderName);

            if (result != nullptr)
                return result;
        }

        return nullptr;
    }


    // =====================
    // CREATE FOLDER
    // =====================
    bool createFolder(string parentName, string folderName) {

        FolderNode* parent = findFolder(root, parentName);

        if (parent == nullptr)
            return false;

        // cek folder duplikat
        for (FolderNode* child : parent->children) {

            if (child->folderName == folderName)
                return false;
        }

        FolderNode* newFolder = new FolderNode(folderName);

        parent->children.push_back(newFolder);

        return true;
    }


    // =====================
    // DELETE FOLDER
    // =====================
    bool deleteFolder(string parentName, string folderName) {

        FolderNode* parent = findFolder(root, parentName);

        if (parent == nullptr)
            return false;

        for (int i = 0; i < parent->children.size(); i++) {

            if (parent->children[i]->folderName == folderName) {

                parent->children.erase(parent->children.begin() + i);

                return true;
            }
        }

        return false;
    }


    // =====================
    // CREATE FILE
    // =====================
    bool createFile(string folderName, string filename) {

        FolderNode* folder = findFolder(root, folderName);

        if (folder == nullptr)
            return false;

        if (folder->files.searchFile(filename))
            return false;

        folder->files.insertFile(filename);

        return true;
    }


    // =====================
    // DELETE FILE
    // =====================
    bool deleteFile(string folderName, string filename) {

        FolderNode* folder = findFolder(root, folderName);

        if (folder == nullptr)
            return false;

        return folder->files.deleteFile(filename);
    }


    // =====================
    // RENAME FILE
    // =====================
    bool renameFile(string folderName,
                    string oldName,
                    string newName) {

        FolderNode* folder = findFolder(root, folderName);

        if (folder == nullptr)
            return false;

        return folder->files.renameFile(oldName, newName);
    }


    // =====================
    // SEARCH FILE
    // =====================
    bool searchFile(string folderName, string filename) {

        FolderNode* folder = findFolder(root, folderName);

        if (folder == nullptr)
            return false;

        return Search::linearSearch(folder->files, filename);
    }


    // =====================
    // SORT FILE
    // =====================
    vector<string> sortFiles(string folderName) {

        FolderNode* folder = findFolder(root, folderName);

        if (folder == nullptr)
            return {};

        return Sort::bubbleSort(folder->files);
    }


    // =====================
    // DISPLAY TREE
    // =====================
    void displayTree() {

        Traversal::dfsTraversal(root);
    }


    // =====================
    // GLOBAL SEARCH
    // =====================
    string globalSearch(FolderNode* currentNode,
                        string filename) {

        if (currentNode->files.searchFile(filename))
            return currentNode->folderName;

        for (FolderNode* child : currentNode->children) {

            string result = globalSearch(child, filename);

            if (result != "")
                return result;
        }

        return "";
    }

};

#endif
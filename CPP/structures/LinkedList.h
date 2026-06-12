#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <vector>
#include "FileNode.h"

using namespace std;

class LinkedList {
private:
    FileNode* head;

public:

    LinkedList() {
        head = nullptr;
    }

    FileNode* getHead() {
        return head;
    }

    void insertFile(string filename) {

        FileNode* newNode = new FileNode(filename);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        FileNode* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    bool searchFile(string filename) {

        FileNode* current = head;

        while (current != nullptr) {

            if (current->filename == filename)
                return true;

            current = current->next;
        }

        return false;
    }

    bool deleteFile(string filename) {

        if (head == nullptr)
            return false;

        if (head->filename == filename) {

            head = head->next;

            return true;
        }

        FileNode* prev = nullptr;
        FileNode* current = head;

        while (current != nullptr) {

            if (current->filename == filename) {

                prev->next = current->next;

                return true;
            }

            prev = current;
            current = current->next;
        }

        return false;
    }

    bool renameFile(string oldName, string newName) {

        FileNode* current = head;

        while (current != nullptr) {

            if (current->filename == oldName) {

                current->filename = newName;

                return true;
            }

            current = current->next;
        }

        return false;
    }

    vector<string> getFiles() {

        vector<string> files;

        FileNode* current = head;

        while (current != nullptr) {

            files.push_back(current->filename);

            current = current->next;
        }

        return files;
    }
};

#endif
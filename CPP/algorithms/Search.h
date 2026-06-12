#ifndef SEARCH_H
#define SEARCH_H

#include "../structures/LinkedList.h"

class Search {

public:

    static bool linearSearch(LinkedList& list, string target) {

        FileNode* current = list.getHead();

        while (current != nullptr) {

            if (current->filename == target)
                return true;

            current = current->next;
        }

        return false;
    }
};

#endif
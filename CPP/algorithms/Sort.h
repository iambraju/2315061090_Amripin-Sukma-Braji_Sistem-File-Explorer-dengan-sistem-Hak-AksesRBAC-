#ifndef SORT_H
#define SORT_H

#include <vector>
#include <string>
#include "../structures/LinkedList.h"

using namespace std;

class Sort {

public:

    static vector<string> bubbleSort(LinkedList& list) {

        vector<string> files = list.getFiles();

        int n = files.size();

        for (int i = 0; i < n - 1; i++) {

            bool swapped = false;

            for (int j = 0; j < n - i - 1; j++) {

                if (files[j] > files[j + 1]) {

                    swap(files[j], files[j + 1]);

                    swapped = true;
                }
            }

            if (!swapped)
                break;
        }

        return files;
    }
};

#endif
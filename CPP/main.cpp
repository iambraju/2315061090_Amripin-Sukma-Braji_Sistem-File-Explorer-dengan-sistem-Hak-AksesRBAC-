#include <iostream>
#include <vector>

#include "structures/Tree.h"
#include "structures/Queue.h"

using namespace std;


// ==========================
// MENU
// ==========================
void adminMenu() {

    cout << "\n========== ADMIN MENU ==========\n";

    cout << "1. Create Folder\n";
    cout << "2. Delete Folder\n";
    cout << "3. Create File\n";
    cout << "4. Delete File\n";
    cout << "5. Rename File\n";
    cout << "6. Search File\n";
    cout << "7. Sort File\n";
    cout << "8. Display File System\n";
    cout << "9. Activity Log\n";
    cout << "0. Exit\n";
}

void editorMenu() {

    cout << "\n========== EDITOR MENU ==========\n";

    cout << "1. Create File\n";
    cout << "2. Rename File\n";
    cout << "3. Search File\n";
    cout << "4. Display File System\n";
    cout << "0. Exit\n";
}

void viewerMenu() {

    cout << "\n========== VIEWER MENU ==========\n";

    cout << "1. Search File\n";
    cout << "2. Display File System\n";
    cout << "0. Exit\n";
}


int main() {

    FileTree fileTree;
    ActivityQueue activityLog;

    int role;

    cout << "=================================\n";
    cout << "      FILE EXPLORER SYSTEM\n";
    cout << "     Role Based Access Control\n";
    cout << "=================================\n";

    cout << "1. Admin\n";
    cout << "2. Editor\n";
    cout << "3. Viewer\n";
    cout << "0. Exit\n";

    cout << "\nChoose Role : ";
    cin >> role;

    while (true) {

        int choice;

        // ================= ADMIN =================
        if (role == 1) {

            adminMenu();

            cout << "\nChoose : ";
            cin >> choice;

            if (choice == 1) {

                string parent, folder;

                cout << "Parent Folder : ";
                cin >> parent;

                cout << "New Folder Name : ";
                cin >> folder;

                if (fileTree.createFolder(parent, folder)) {

                    activityLog.enqueue("Create Folder : " + folder);

                    cout << "Folder berhasil dibuat.\n";
                }
                else {

                    cout << "Gagal membuat folder.\n";
                }
            }

            else if (choice == 2) {

                string parent, folder;

                cout << "Parent Folder : ";
                cin >> parent;

                cout << "Folder Name : ";
                cin >> folder;

                if (fileTree.deleteFolder(parent, folder)) {

                    activityLog.enqueue("Delete Folder : " + folder);

                    cout << "Folder berhasil dihapus.\n";
                }
                else {

                    cout << "Folder tidak ditemukan.\n";
                }
            }

            else if (choice == 3) {

                string folder, filename;

                cout << "Folder : ";
                cin >> folder;

                cout << "File Name : ";
                cin >> filename;

                if (fileTree.createFile(folder, filename)) {

                    activityLog.enqueue("Create File : " + filename);

                    cout << "File berhasil dibuat.\n";
                }
                else {

                    cout << "Gagal membuat file.\n";
                }
            }

            else if (choice == 4) {

                string folder, filename;

                cout << "Folder : ";
                cin >> folder;

                cout << "File Name : ";
                cin >> filename;

                if (fileTree.deleteFile(folder, filename)) {

                    activityLog.enqueue("Delete File : " + filename);

                    cout << "File berhasil dihapus.\n";
                }
                else {

                    cout << "File tidak ditemukan.\n";
                }
            }

            else if (choice == 5) {

                string folder, oldName, newName;

                cout << "Folder : ";
                cin >> folder;

                cout << "Old Name : ";
                cin >> oldName;

                cout << "New Name : ";
                cin >> newName;

                if (fileTree.renameFile(folder, oldName, newName)) {

                    activityLog.enqueue(
                        "Rename File : " + oldName + " -> " + newName
                    );

                    cout << "Rename berhasil.\n";
                }
                else {

                    cout << "File tidak ditemukan.\n";
                }
            }

            else if (choice == 6) {

                string filename;

                cout << "File Name : ";
                cin >> filename;

                string folder = fileTree.globalSearch(
                    fileTree.getRoot(),
                    filename
                );

                if (folder != "") {

                    cout << "File ditemukan pada folder "
                         << folder
                         << endl;
                }
                else {

                    cout << "File tidak ditemukan.\n";
                }
            }

            else if (choice == 7) {

                string folder;

                cout << "Folder : ";
                cin >> folder;

                vector<string> files = fileTree.sortFiles(folder);

                cout << "\n===== Sorted Files =====\n";

                for (string file : files) {

                    cout << "- " << file << endl;
                }
            }

            else if (choice == 8) {

                fileTree.displayTree();
            }

            else if (choice == 9) {

                cout << "\n===== ACTIVITY LOG =====\n";

                activityLog.displayLog();
            }

            else if (choice == 0) {

                break;
            }
        }

        // ================= EDITOR =================
        else if (role == 2) {

            editorMenu();

            cout << "\nChoose : ";
            cin >> choice;

            if (choice == 1) {

                string folder, filename;

                cout << "Folder : ";
                cin >> folder;

                cout << "File Name : ";
                cin >> filename;

                fileTree.createFile(folder, filename);
            }

            else if (choice == 2) {

                string folder, oldName, newName;

                cout << "Folder : ";
                cin >> folder;

                cout << "Old Name : ";
                cin >> oldName;

                cout << "New Name : ";
                cin >> newName;

                fileTree.renameFile(folder, oldName, newName);
            }

            else if (choice == 3) {

                string filename;

                cout << "File Name : ";
                cin >> filename;

                string folder = fileTree.globalSearch(
                    fileTree.getRoot(),
                    filename
                );

                if (folder != "")
                    cout << "File ditemukan pada folder "
                         << folder
                         << endl;
                else
                    cout << "File tidak ditemukan.\n";
            }

            else if (choice == 4) {

                fileTree.displayTree();
            }

            else if (choice == 0) {

                break;
            }
        }

        // ================= VIEWER =================
        else if (role == 3) {

            viewerMenu();

            cout << "\nChoose : ";
            cin >> choice;

            if (choice == 1) {

                string filename;

                cout << "File Name : ";
                cin >> filename;

                string folder = fileTree.globalSearch(
                    fileTree.getRoot(),
                    filename
                );

                if (folder != "")
                    cout << "File ditemukan pada folder "
                         << folder
                         << endl;
                else
                    cout << "File tidak ditemukan.\n";
            }

            else if (choice == 2) {

                fileTree.displayTree();
            }

            else if (choice == 0) {

                break;
            }
        }

        else {

            break;
        }
    }

    return 0;
}
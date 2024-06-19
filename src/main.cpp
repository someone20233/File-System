#include "../include/FileSystemManager.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    FileSystemManager fs;
    string command;

    cout << "Simple Filesystem CLI" << endl;
    while (true) {
        cout << "Current Directory: " << fs.getCurrentDirectoryPath() << " > ";
        getline(cin, command);

        if (command == "exit") break;
        try {
            if (command.compare(0, 12, "create file ") == 0) {
                fs.createFile(command.substr(12));
            } else if (command.compare(0, 12, "delete file ") == 0) {
                fs.deleteFile(command.substr(12));
            } else if (command.compare(0, 10, "open file ") == 0) {
                auto fd = fs.openFile(command.substr(10));
                cout << "Opened file: " << fd->getFile()->getName() << endl;
            } else if (command.compare(0, 6, "write ") == 0) {
                string name = command.substr(6, command.find(' ', 6) - 6);
                string content = command.substr(command.find(' ', 6) + 1);
                auto fd = fs.openFile(name);
                fs.writeFile(fd, content);
                fs.closeFile(fd);
            } else if (command.compare(0, 5, "read ") == 0) {
                auto fd = fs.openFile(command.substr(5));
                cout << fs.readFile(fd, 1024) << endl; // Read up to 1024 bytes
                fs.closeFile(fd);
            } else if (command.compare(0, 11, "create dir ") == 0) {
                fs.createDirectory(command.substr(11));
            } else if (command.compare(0, 11, "delete dir ") == 0) {
                fs.deleteDirectory(command.substr(11));
            } else if (command == "list") {
                auto contents = fs.listDirectoryWithDetails();
                for (const auto& [name, size, modified] : contents) {
                    cout << setw(20) << name << setw(10) << size << setw(20) << modified << endl;
                }
            } else if (command.compare(0, 3, "cd ") == 0) {
                fs.changeDirectory(command.substr(3));
            } else if (command == "back") {
                fs.goBack();
            } else {
                cout << "Unknown command: " << command << endl;
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}

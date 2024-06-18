#include <iostream>
#include "../header/Directory.h"
#include "../header/File.h"

int main() {
    // Create a root Directory
    Directory rootDir("root");

    // Create a subdirectory and a file
    auto subDir = make_unique<Directory>("subdir", &rootDir);
    auto file1 = make_unique<File>("file1.txt");
    auto file2 = make_unique<File>("file2.txt");

    // Add subdirectory and files to root directory
    rootDir.addObject(move(subDir));
    rootDir.addObject(move(file1));
    rootDir.addObject(move(file2));

    // List contents of root directory
    cout << "Contents of root directory:" << endl;
    for (const auto& name : rootDir.listContents()) {
        cout << name << endl;
    }

    // Retrieve and interact with an object from the directory
    FileSystemObject* fileObject = rootDir.getObject("file1.txt");
    if (fileObject != nullptr) {
        File* file = dynamic_cast<File*>(fileObject);
        if (file != nullptr) {
            file->write("Hello, world!");
            cout << "Content of file1.txt: " << file->read() << endl;
        }
    }

    // Remove file1 from the root directory
    rootDir.removeObject("file1.txt");

    // List contents of root directory again
    cout << "Contents of root directory after removing file1.txt:" << endl;
    for (const auto& name : rootDir.listContents()) {
        cout << name << endl;
    }

    // Check if file1.txt is really removed
    if (rootDir.getObject("file1.txt") == nullptr) {
        cout << "file1.txt successfully removed from root directory." << endl;
    }

    // List contents of subdir directory
    FileSystemObject* subdirObject = rootDir.getObject("subdir");
    if (subdirObject != nullptr) {
        Directory* subDir = dynamic_cast<Directory*>(subdirObject);
        if (subDir != nullptr) {
            cout << "Contents of subdir directory:" << endl;
            for (const auto& name : subDir->listContents()) {
                cout << name << endl;
            }
        }
    }

    return 0;
}

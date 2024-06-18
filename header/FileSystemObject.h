#ifndef FILESYSTEMOBJECT_H
#define FILESYSTEMOBJECT_H

#include <string>
#include <chrono>
using namespace std;

// Parent Class for the File and Directory classes
// Contains the name and last modified time of the object
class FileSystemObject {
protected:
    string name;    // Name of the object
    chrono::system_clock::time_point lastModified;  // Last modified time of the object

public:
    // Constructor
    FileSystemObject(const std::string& name);
    // Destructor
    virtual ~FileSystemObject() = default;
    // Getters and Setters
    string getName() const;
    chrono::system_clock::time_point getLastModified() const;
    void setLastModified(std::chrono::system_clock::time_point time);
};

#endif // FILESYSTEMOBJECT_H

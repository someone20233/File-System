#include <iostream>
#include <thread> // for sleep_for
#include "../header/File.h"
using namespace std;

int main() {
    // Create a File object
    File myFile("example.txt");

    // Test getName()
    cout << "File name: " << myFile.getName() << endl;

    // Test write() and read()
    myFile.write("Hello, world!");
    cout << "File content after write: " << myFile.read() << endl;

    // Capture and print last modified time
    auto lastModified = myFile.getLastModified();
    time_t lastModifiedTime = system_clock::to_time_t(lastModified);
    cout << "Last modified time after write: " << ctime(&lastModifiedTime) << endl;

    // Wait for a second to ensure lastModified changes
    this_thread::sleep_for(chrono::seconds(2));

    // Test deleteContent()
    myFile.deleteContent();
    cout << "File content after delete: " << myFile.read() << endl;

    // Capture and print last modified time again
    lastModified = myFile.getLastModified();
    lastModifiedTime = system_clock::to_time_t(lastModified);
    cout << "Last modified time after delete: " << ctime(&lastModifiedTime) << endl;

    return 0;
}

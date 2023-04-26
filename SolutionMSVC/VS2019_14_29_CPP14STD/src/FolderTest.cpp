// FolderTest1
#include <iostream>
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

void CreateFolder() {
    bool result = fs::create_directory("folder");
    printf("CreateFolder result = %s", result? "true":"false");
}
bool FolderExists(const std::string& folderName) {
    return fs::exists(folderName);
}
void RenameFolder(const std::string& oldName, const std::string& newName) {
    fs::rename(oldName, newName);
}
void RenameFolderTest() {
    CreateFolder();
    std::string oldName = "folder";
    std::string newName = "folder_old";
    RenameFolder(oldName, newName);
}
void CreateFolderWhileNot() {
    std::string folderName = "folder";
    if (FolderExists(folderName)) {
        std::cout << "Folder exists" << std::endl;
    }
    else {
        std::cout << "Folder does not exist" << std::endl;
        CreateFolder();
    }
}
void FolderTest() {
    RenameFolderTest();
}
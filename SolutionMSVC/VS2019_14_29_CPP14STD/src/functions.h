#pragma once
#include <Windows.h>
#include <string>
void CreateFolder();															// 创建文件夹
bool FolderExists(const std::string& folderName);								// 判断文件夹是否存在
void RenameFolder(const std::string& oldName, const std::string& newName);		// 重命名文件夹
void FolderTest();

void TimeTest();




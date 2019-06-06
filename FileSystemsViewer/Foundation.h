#pragma once

#include <string> 
#include <iostream> 
#include <windows.h>

#include "FileHandle.h"
#include "Cluster.h"

using namespace std;

class Foundation
{
public:
	FileHandle* fileHandle;
	int bytesPerSector;
	int bytesPerCluster;
	int totalSectors;
	int totalClusters;
	unsigned int totalBytes;
	Foundation(FileHandle* fileHandle);
	Cluster* GetCluster(int number);
	void ShowInfo();
	~Foundation();
};


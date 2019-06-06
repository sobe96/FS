#include "pch.h"
#include "Foundation.h"
#include "FileHandle.h"

using namespace std;

Foundation::Foundation(FileHandle* handle)
{
	fileHandle = handle;
}

Cluster * Foundation::GetCluster(int clusterNumber)
{
	int clusterPosition = (clusterNumber - 1)*bytesPerCluster;
	BYTE *data = fileHandle->GetData(clusterPosition, bytesPerCluster);
	return new Cluster(data, bytesPerCluster);
}

void Foundation::ShowInfo()
{
	cout << "Bytes per sector: " << bytesPerSector << endl;
	cout << "Bytes per cluster: " << bytesPerCluster << endl;
	cout << "Total sectors: " << totalSectors << endl;
	cout << "Total clusters: " << totalClusters << endl;
	cout << "Total bytes: " << totalBytes << endl;
}

Foundation::~Foundation() { }
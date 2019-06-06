#include "pch.h"
#include <iostream> 
#include <windows.h>
#include "NTFS.h"

using namespace std;

NTFSReader::NTFSReader(FileHandle* fileReader): Foundation(fileReader)
{
	NTFSBootRecord *ntfsBootRecord = (NTFSBootRecord*)fileHandle->GetData(0, 1024);
	bytesPerSector = *(unsigned short*)ntfsBootRecord->BytesPerSector;
	int sectorsPerCluster = *(unsigned short*)ntfsBootRecord->SectorsPerCluster;
	bytesPerCluster = bytesPerSector * sectorsPerCluster;
	totalSectors = ntfsBootRecord->TotalSectors;
	totalClusters = totalSectors / sectorsPerCluster;
	totalBytes = bytesPerSector * totalSectors;
}

NTFSReader::~NTFSReader() 
{

}
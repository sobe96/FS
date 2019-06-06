#include "pch.h"
#include "Iterator.h"
#include "Foundation.h"

Iterator::Iterator(Foundation * newReader)
{
	currentClusterNumber = 0;
	reader = newReader;
}

Cluster* Iterator::GetNext() {
	// Увеличиваем номер текущего кластера, что бы получить следующий
	currentClusterNumber++;
	return reader->GetCluster(currentClusterNumber);
}

bool Iterator::HasMore() {
	// Смотрим, больше ли номер следующего кластера, чем общее количество кластеров
	return (currentClusterNumber + 1) < reader->totalClusters;
}

Iterator::~Iterator() 
{

}

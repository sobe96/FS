#pragma once
#include "Foundation.h"

using namespace std;

class Iterator
{
public:
	int currentClusterNumber;
	Foundation* reader;
	Iterator(Foundation* reader);
	virtual Cluster* GetNext();
	virtual bool HasMore();
	~Iterator();
};


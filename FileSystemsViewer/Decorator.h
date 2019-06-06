#pragma once
#include "Iterator.h"
#include "Cluster.h"

class Decorator :
	public Iterator
{
public:
	Iterator *iterator;
	Decorator(Iterator* newIterator);
	Cluster* GetNext() override;
	bool HasMore() override;
	~Decorator();
};


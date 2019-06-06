#include "pch.h"
#include "Decorator.h"

Decorator::Decorator(Iterator* newIterator)
	: Iterator(NULL)
{
	iterator = newIterator;
}

Cluster* Decorator::GetNext()
{
	return iterator->GetNext();
}

bool Decorator::HasMore()
{
	iterator->GetNext();
	return iterator->HasMore();
}

Decorator::~Decorator()
{
}

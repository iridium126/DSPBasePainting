#pragma once
#include "DataContainer.h"
#include <QImage>

class DataAccessor
{
public:
	DataAccessor(DataContainer& container);
	~DataAccessor();
	void ProcessPicture(const QString& fileName);

private:
	DataContainer& container;
};

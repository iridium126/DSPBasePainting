#pragma once
#include <vector>
#include <QtGlobal>

class DataGenerator;
class DataAccessor;

class DataContainer
{
	friend DataGenerator;
	friend DataAccessor;
public:
	DataContainer(qreal polar_angle, qreal azimuth_angle, qreal painting_central_angle);
	~DataContainer();
	void Load();
	void Save();

private:
	qreal polar_angle, azimuth_angle; // 极角、方位角
	qreal painting_central_angle;     // 图片在球面上的边界的直径所对的圆心角

};
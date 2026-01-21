#pragma once
#include "DataContainer.h"
#include <QPoint>
#include <QHash>

class TileRawData {
private:
	int point_index[4];
};

class DataGenerator
{
public:
	DataGenerator(DataContainer* container);
	~DataGenerator();

private:
	DataContainer* container;
	static constexpr int latitudinal_zone_y[12] = { 0,80,130,155,180,195,210,220,230,235,240,245 }; // 纬度带最低纬度的y值
	static constexpr int precomputed_gcd_of_latitudinal_zone[78] = { 1000,200,200,100,100,100,100,20,20,20,20,20,
																	 800,200,100,100,100,100,20,20,20,20,20,
																	 600,100,100,100,100,20,20,20,20,20,
																	 500,100,100,100,20,20,20,20,20,
																	 400,100,100,20,20,20,20,20,
																	 300,100,20,20,20,20,20,
																	 200,40,20,20,20,20,
																	 160,20,20,20,20,
																	 100,20,20,20,
																	 80,40,20,
																	 40,20,
																	 20 };
	static constexpr const int* gcd_of_latitudinal_zone[12] = { precomputed_gcd_of_latitudinal_zone, precomputed_gcd_of_latitudinal_zone + 11,
		precomputed_gcd_of_latitudinal_zone + 21, precomputed_gcd_of_latitudinal_zone + 30, precomputed_gcd_of_latitudinal_zone + 38,
		precomputed_gcd_of_latitudinal_zone + 45, precomputed_gcd_of_latitudinal_zone + 51, precomputed_gcd_of_latitudinal_zone + 56,
		precomputed_gcd_of_latitudinal_zone + 60, precomputed_gcd_of_latitudinal_zone + 63, precomputed_gcd_of_latitudinal_zone + 65,
		precomputed_gcd_of_latitudinal_zone + 66 };
	QHash<QPoint, int> index_map;
	std::vector<QPoint> points;
	std::vector<TileRawData> raw_data;
};

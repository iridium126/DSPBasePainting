#include "DataGenerator.h"

DataGenerator::DataGenerator(DataContainer* container) :container(container)
{
	GenerateData();
}

DataGenerator::~DataGenerator()
{
}

void DataGenerator::GenerateData()
{
	bool p_0_in_painting, p_90_a_0_in_painting, p_90_a_90_in_painting, p_90_a_180_in_painting, p_90_a_270_in_painting, p_180_in_painting;
	bool low_p_1_a_zone = true, low_p_2_a_zone = true, low_p_3_a_zone = true, low_p_4_a_zone = true, high_p_1_a_zone = true, high_p_2_a_zone = true, high_p_3_a_zone = true, high_p_4_a_zone = true;
	p_0_in_painting = point_is_in_painting(0, 0);
	p_90_a_0_in_painting = point_is_in_painting(M_PI_2, 0);
	p_90_a_90_in_painting = point_is_in_painting(M_PI_2, M_PI_2);
	p_90_a_180_in_painting = point_is_in_painting(M_PI_2, M_PI);
	p_90_a_270_in_painting = point_is_in_painting(M_PI_2, M_PI_2 * 3);
	p_180_in_painting = point_is_in_painting(M_PI, 0);
	if (!p_0_in_painting || !p_90_a_0_in_painting || !p_90_a_90_in_painting)
	{
		if (p_0_in_painting || p_90_a_0_in_painting || p_90_a_90_in_painting)
			GenerateData(0, M_PI_2, 0, M_PI_2, p_0_in_painting, p_0_in_painting, p_90_a_0_in_painting, p_90_a_90_in_painting);
		low_p_1_a_zone = false;
	}
	if (!p_0_in_painting || !p_90_a_90_in_painting || !p_90_a_180_in_painting)
	{
		if (p_0_in_painting || p_90_a_90_in_painting || p_90_a_180_in_painting)
			GenerateData(0, M_PI_2, M_PI_2, M_PI, p_0_in_painting, p_0_in_painting, p_90_a_90_in_painting, p_90_a_180_in_painting);
		low_p_2_a_zone = false;
	}
	if (!p_0_in_painting || !p_90_a_180_in_painting || !p_90_a_270_in_painting)
	{
		if (p_0_in_painting || p_90_a_180_in_painting || p_90_a_270_in_painting)
			GenerateData(0, M_PI_2, M_PI, M_PI_2 * 3, p_0_in_painting, p_0_in_painting, p_90_a_180_in_painting, p_90_a_270_in_painting);
		low_p_3_a_zone = false;
	}
	if (!p_0_in_painting || !p_90_a_270_in_painting || !p_90_a_0_in_painting)
	{
		if (p_0_in_painting || p_90_a_270_in_painting || p_90_a_0_in_painting)
			GenerateData(0, M_PI_2, M_PI_2 * 3, M_PI * 2, p_0_in_painting, p_0_in_painting, p_90_a_270_in_painting, p_90_a_0_in_painting);
		low_p_4_a_zone = false;
	}
	if (!p_180_in_painting || !p_90_a_0_in_painting || !p_90_a_90_in_painting)
	{
		if (p_180_in_painting || p_90_a_0_in_painting || p_90_a_90_in_painting)
			GenerateData(M_PI_2, M_PI, 0, M_PI_2, p_90_a_0_in_painting, p_90_a_90_in_painting, p_180_in_painting, p_180_in_painting);
		high_p_1_a_zone = false;
	}
	if (!p_180_in_painting || !p_90_a_90_in_painting || !p_90_a_180_in_painting)
	{
		if (p_180_in_painting || p_90_a_90_in_painting || p_90_a_180_in_painting)
			GenerateData(M_PI_2, M_PI, M_PI_2, M_PI, p_90_a_90_in_painting, p_90_a_180_in_painting, p_180_in_painting, p_180_in_painting);
		high_p_2_a_zone = false;
	}
	if (!p_180_in_painting || !p_90_a_180_in_painting || !p_90_a_270_in_painting)
	{
		if (p_180_in_painting || p_90_a_180_in_painting || p_90_a_270_in_painting)
			GenerateData(M_PI_2, M_PI, M_PI, M_PI_2 * 3, p_90_a_180_in_painting, p_90_a_270_in_painting, p_180_in_painting, p_180_in_painting);
		high_p_3_a_zone = false;
	}
	if (!p_180_in_painting || !p_90_a_270_in_painting || !p_90_a_0_in_painting)
	{
		if (p_180_in_painting || p_90_a_270_in_painting || p_90_a_0_in_painting)
			GenerateData(M_PI_2, M_PI, M_PI_2 * 3, M_PI * 2, p_90_a_270_in_painting, p_90_a_0_in_painting, p_180_in_painting, p_180_in_painting);
		high_p_4_a_zone = false;
	}
	int min_y, max_y, min_n, max_n;
	if (low_p_1_a_zone || low_p_2_a_zone || low_p_3_a_zone || low_p_4_a_zone)
	{
		get_y_range(0, M_PI_2, min_y, max_y, min_n, max_n);
		if (low_p_1_a_zone)
			init_tile_zone(min_y, max_y, min_n, max_n, 0, M_PI_2);
		if (low_p_2_a_zone)
			init_tile_zone(min_y, max_y, min_n, max_n, M_PI_2, M_PI);
		if (low_p_3_a_zone)
			init_tile_zone(min_y, max_y, min_n, max_n, M_PI, M_PI_2 * 3);
		if (low_p_4_a_zone)
			init_tile_zone(min_y, max_y, min_n, max_n, M_PI_2 * 3, M_PI * 2);
	}
	if (high_p_1_a_zone || high_p_2_a_zone || high_p_3_a_zone || high_p_4_a_zone)
	{
		get_y_range(M_PI_2, M_PI, min_y, max_y, min_n, max_n);
		if (high_p_1_a_zone)
			init_tile_zone(min_y, max_y, min_n, max_n, 0, M_PI_2);
		if (high_p_2_a_zone)
			init_tile_zone(min_y, max_y, min_n, max_n, M_PI_2, M_PI);
		if (high_p_3_a_zone)
			init_tile_zone(min_y, max_y, min_n, max_n, M_PI, M_PI_2 * 3);
		if (high_p_4_a_zone)
			init_tile_zone(min_y, max_y, min_n, max_n, M_PI_2 * 3, M_PI * 2);
	}
}

void DataGenerator::GenerateData(qreal min_polar_angle, qreal max_polar_angle, qreal min_azimuth_angle, qreal max_azimuth_angle, bool min_p_min_a_in_painting, bool min_p_max_a_in_painting, bool max_p_min_a_in_painting, bool max_p_max_a_in_painting)
{
	double mid_polar_angle, mid_azimuth_angle;
	mid_polar_angle = get_nearest_multiple((min_polar_angle + max_polar_angle) / 2, M_PI / 500 / edge_segments);
	mid_azimuth_angle = get_nearest_multiple((min_azimuth_angle + max_azimuth_angle) / 2, get_minimal_azimuth_angle(min_polar_angle, max_polar_angle));
	bool min_p_mid_a_in_painting, mid_p_min_a_in_painting, mid_p_mid_a_in_painting, max_p_mid_a_in_painting, mid_p_max_a_in_painting;
	bool low_p_low_a_zone = true, low_p_high_a_zone = true, high_p_low_a_zone = true, high_p_high_a_zone = true;
	if (float_equal(mid_azimuth_angle, min_azimuth_angle))
	{
		min_p_mid_a_in_painting = min_p_min_a_in_painting;
		max_p_mid_a_in_painting = max_p_min_a_in_painting;
		low_p_low_a_zone = false;
		high_p_low_a_zone = false;
		if (float_equal(mid_polar_angle, min_polar_angle))
		{
			mid_p_min_a_in_painting = min_p_min_a_in_painting;
			mid_p_max_a_in_painting = min_p_max_a_in_painting;
			low_p_high_a_zone = false;
		}
		else if (float_equal(mid_polar_angle, max_polar_angle))
		{
			mid_p_min_a_in_painting = max_p_min_a_in_painting;
			mid_p_max_a_in_painting = max_p_max_a_in_painting;
			high_p_high_a_zone = false;
		}
		else
		{
			mid_p_min_a_in_painting = point_is_in_painting(mid_polar_angle, min_azimuth_angle);
			mid_p_max_a_in_painting = point_is_in_painting(mid_polar_angle, max_azimuth_angle);
		}
		mid_p_mid_a_in_painting = mid_p_min_a_in_painting;
	}
	else if (float_equal(mid_azimuth_angle, max_azimuth_angle))
	{
		min_p_mid_a_in_painting = min_p_max_a_in_painting;
		max_p_mid_a_in_painting = max_p_max_a_in_painting;
		low_p_high_a_zone = false;
		high_p_high_a_zone = false;
		if (float_equal(mid_polar_angle, min_polar_angle))
		{
			mid_p_min_a_in_painting = min_p_min_a_in_painting;
			mid_p_max_a_in_painting = min_p_max_a_in_painting;
			low_p_low_a_zone = false;
		}
		else if (float_equal(mid_polar_angle, max_polar_angle))
		{
			mid_p_min_a_in_painting = max_p_min_a_in_painting;
			mid_p_max_a_in_painting = max_p_max_a_in_painting;
			high_p_low_a_zone = false;
		}
		else
		{
			mid_p_min_a_in_painting = point_is_in_painting(mid_polar_angle, min_azimuth_angle);
			mid_p_max_a_in_painting = point_is_in_painting(mid_polar_angle, max_azimuth_angle);
		}
		mid_p_mid_a_in_painting = mid_p_max_a_in_painting;
	}
	else
	{
		min_p_mid_a_in_painting = point_is_in_painting(min_polar_angle, mid_azimuth_angle);
		max_p_mid_a_in_painting = point_is_in_painting(max_polar_angle, mid_azimuth_angle);
		if (float_equal(mid_polar_angle, min_polar_angle))
		{
			mid_p_min_a_in_painting = min_p_min_a_in_painting;
			mid_p_max_a_in_painting = min_p_max_a_in_painting;
			mid_p_mid_a_in_painting = min_p_mid_a_in_painting;
			low_p_low_a_zone = false;
			low_p_high_a_zone = false;
		}
		else if (float_equal(mid_polar_angle, max_polar_angle))
		{
			mid_p_min_a_in_painting = max_p_min_a_in_painting;
			mid_p_max_a_in_painting = max_p_max_a_in_painting;
			mid_p_mid_a_in_painting = max_p_mid_a_in_painting;
			high_p_low_a_zone = false;
			high_p_high_a_zone = false;
		}
		else
		{
			mid_p_min_a_in_painting = point_is_in_painting(mid_polar_angle, min_azimuth_angle);
			mid_p_max_a_in_painting = point_is_in_painting(mid_polar_angle, max_azimuth_angle);
			mid_p_mid_a_in_painting = point_is_in_painting(mid_polar_angle, mid_azimuth_angle);
		}
	}
	if (low_p_low_a_zone && (!min_p_min_a_in_painting || !min_p_mid_a_in_painting || !mid_p_min_a_in_painting || !mid_p_mid_a_in_painting))
	{
		if ((min_p_min_a_in_painting || min_p_mid_a_in_painting || mid_p_min_a_in_painting || mid_p_mid_a_in_painting)
			&& (!float_equal(mid_polar_angle - min_polar_angle, M_PI / 500 / edge_segments) || !float_equal(mid_azimuth_angle - min_azimuth_angle, get_minimal_azimuth_angle((mid_polar_angle + min_polar_angle) / 2))))
			GenerateData(min_polar_angle, mid_polar_angle, min_azimuth_angle, mid_azimuth_angle, min_p_min_a_in_painting, min_p_mid_a_in_painting, mid_p_min_a_in_painting, mid_p_mid_a_in_painting);
		low_p_low_a_zone = false;
	}
	if (low_p_high_a_zone && (!min_p_mid_a_in_painting || !min_p_max_a_in_painting || !mid_p_mid_a_in_painting || !mid_p_max_a_in_painting))
	{
		if ((min_p_mid_a_in_painting || min_p_max_a_in_painting || mid_p_mid_a_in_painting || mid_p_max_a_in_painting)
			&& (!float_equal(mid_polar_angle - min_polar_angle, M_PI / 500 / edge_segments) || !float_equal(max_azimuth_angle - mid_azimuth_angle, get_minimal_azimuth_angle((mid_polar_angle + min_polar_angle) / 2))))
			GenerateData(min_polar_angle, mid_polar_angle, mid_azimuth_angle, max_azimuth_angle, min_p_mid_a_in_painting, min_p_max_a_in_painting, mid_p_mid_a_in_painting, mid_p_max_a_in_painting);
		low_p_high_a_zone = false;
	}
	if (high_p_low_a_zone && (!mid_p_min_a_in_painting || !mid_p_mid_a_in_painting || !max_p_min_a_in_painting || !max_p_mid_a_in_painting))
	{
		if ((mid_p_min_a_in_painting || mid_p_mid_a_in_painting || max_p_min_a_in_painting || max_p_mid_a_in_painting)
			&& (!float_equal(max_polar_angle - mid_polar_angle, M_PI / 500 / edge_segments) || !float_equal(mid_azimuth_angle - min_azimuth_angle, get_minimal_azimuth_angle((mid_polar_angle + max_polar_angle) / 2))))
			GenerateData(mid_polar_angle, max_polar_angle, min_azimuth_angle, mid_azimuth_angle, mid_p_min_a_in_painting, mid_p_mid_a_in_painting, max_p_min_a_in_painting, max_p_mid_a_in_painting);
		high_p_low_a_zone = false;
	}
	if (high_p_high_a_zone && (!mid_p_mid_a_in_painting || !mid_p_max_a_in_painting || !max_p_mid_a_in_painting || !max_p_max_a_in_painting))
	{
		if ((mid_p_mid_a_in_painting || mid_p_max_a_in_painting || max_p_mid_a_in_painting || max_p_max_a_in_painting)
			&& (!float_equal(max_polar_angle - mid_polar_angle, M_PI / 500 / edge_segments) || !float_equal(max_azimuth_angle - mid_azimuth_angle, get_minimal_azimuth_angle((mid_polar_angle + max_polar_angle) / 2))))
			GenerateData(mid_polar_angle, max_polar_angle, mid_azimuth_angle, max_azimuth_angle, mid_p_mid_a_in_painting, mid_p_max_a_in_painting, max_p_mid_a_in_painting, max_p_max_a_in_painting);
		high_p_high_a_zone = false;
	}
	int min_y, max_y, min_n, max_n;
	if (low_p_low_a_zone || low_p_high_a_zone)
	{
		get_y_range(min_polar_angle, mid_polar_angle, min_y, max_y, min_n, max_n);
		if (low_p_low_a_zone)
			init_tile_zone(min_y, max_y, min_n, max_n, min_azimuth_angle, mid_azimuth_angle);
		if (low_p_high_a_zone)
			init_tile_zone(min_y, max_y, min_n, max_n, mid_azimuth_angle, max_azimuth_angle);
	}
	if (high_p_low_a_zone || high_p_high_a_zone)
	{
		get_y_range(mid_polar_angle, max_polar_angle, min_y, max_y, min_n, max_n);
		if (high_p_low_a_zone)
			init_tile_zone(min_y, max_y, min_n, max_n, min_azimuth_angle, mid_azimuth_angle);
		if (high_p_high_a_zone)
			init_tile_zone(min_y, max_y, min_n, max_n, mid_azimuth_angle, max_azimuth_angle);
	}
}

inline bool DataGenerator::point_is_in_painting(qreal theta, qreal phi)
{
	return sin(container->polar_angle) * sin(theta) * cos(container->azimuth_angle - phi) + cos(container->azimuth_angle) * cos(phi) >= cos(container->painting_central_angle / 2);
}

inline constexpr bool DataGenerator::float_equal(qreal lhs, qreal rhs)
{
	return abs(lhs - rhs) < 0.0000000001;
}

inline qreal DataGenerator::get_nearest_multiple(qreal value, qreal multiple_base)
{
	return multiple_base * round(value / multiple_base);
}

qreal DataGenerator::get_minimal_azimuth_angle(qreal min_polar_angle, qreal max_polar_angle)
{
	int min_y = floor(min_polar_angle / M_PI * 500);
	qreal temp_max_y = max_polar_angle / M_PI * 500;
	int max_y = floor(temp_max_y);
	if (float_equal(temp_max_y, max_y))
		max_y--;
	if (min_y >= 250)
	{
		min_y -= 250;
		max_y -= 250;
	}
	else if (max_y < 250)
	{
		int temp = max_y;
		max_y = 249 - min_y;
		min_y = 249 - temp;
	}
	else {
		if (min_y + max_y >= 500)
			max_y -= 250;
		else
			max_y = 249 - min_y;
		min_y = 0;
	}
	int min_l = 11, max_l = 11, i = 1;
	for (; i < 12; i++)
		if (min_y < latitudinal_zone_y[i])
		{
			min_l = i - 1;
			break;
		}
	for (; i < 12; i++)
		if (max_y < latitudinal_zone_y[i])
		{
			max_l = i - 1;
			break;
		}
	return 2 * M_PI / edge_segments / gcd_of_latitudinal_zone[min_l][max_l];
}

qreal DataGenerator::get_minimal_azimuth_angle(qreal the_polar_angle)
{
	int y = floor(the_polar_angle / M_PI * 500);
	if (y < 250)
		y = 249 - y;
	else if (y == 500)
		y--;
	return 2 * M_PI / edge_segments / (reformOffsets[y + 1] - reformOffsets[y]);
}

void DataGenerator::get_y_range(qreal min_polar_angle, qreal max_polar_angle, int& min_y, int& max_y, int& min_n, int& max_n)
{
	min_y = floor(min_polar_angle / M_PI * 500);
	double temp_max_y = max_polar_angle / M_PI * 500;
	max_y = floor(temp_max_y);
	if (float_equal(temp_max_y, max_y))
		max_y--;
	min_n = round((min_polar_angle / M_PI * 500 - min_y) * edge_segments);
	max_n = round((temp_max_y - max_y) * edge_segments) - 1;
	if (max_y < 250)
	{
		int temp = max_y;
		max_y = 249 - min_y;
		min_y = 249 - temp;
		temp = max_n;
		max_n = min_n;
		min_n = temp;
	}
	else if (min_y < 250)
		min_y = 249 - min_y;
}

void DataGenerator::get_x_range(qreal min_azimuth_angle, qreal max_azimuth_angle, int y, int& min_x, int& max_x, int& min_m, int& max_m)
{
	double minimal_azimuth_angle = 2 * M_PI / (reformOffsets[y + 1] - reformOffsets[y]);
	min_x = floor(min_azimuth_angle / minimal_azimuth_angle);
	double temp_max_x = max_azimuth_angle / minimal_azimuth_angle;
	max_x = floor(temp_max_x);
	if (float_equal(temp_max_x, max_x))
		max_x--;
	min_m = round((min_azimuth_angle / minimal_azimuth_angle - min_x) * edge_segments);
	max_m = round((temp_max_x - max_x) * edge_segments) - 1;
	if (min_x >= 500)
	{
		int temp = max_x;
		max_x = 1499 - min_x;
		min_x = 1499 - temp;
		temp = max_m;
		max_m = min_m;
		min_m = temp;
	}
	else if (max_x >= 500)
		max_x = 1499 - max_x;
}

void DataGenerator::init_tile_zone(int min_y, int max_y, int min_n, int max_n, double min_azimuth_angle, double max_azimuth_angle)
{
	if (min_y != max_y)
	{
		if (min_y < 250 && max_y < 250)
		{
			init_tile_stripe(min_y, 0, min_n, min_azimuth_angle, max_azimuth_angle);
			for (int y = min_y + 1; y < max_y; y++)
				init_tile_stripe(y, 0, 9, min_azimuth_angle, max_azimuth_angle);
			init_tile_stripe(max_y, max_n, 9, min_azimuth_angle, max_azimuth_angle);
		}
		else if (min_y >= 250 && max_y >= 250)
		{
			init_tile_stripe(min_y, min_n, 9, min_azimuth_angle, max_azimuth_angle);
			for (int y = min_y + 1; y < max_y; y++)
				init_tile_stripe(y, 0, 9, min_azimuth_angle, max_azimuth_angle);
			init_tile_stripe(max_y, 0, max_n, min_azimuth_angle, max_azimuth_angle);
		}
		else
		{
			init_tile_stripe(min_y, min_n, 9, min_azimuth_angle, max_azimuth_angle);
			for (int y = min_y - 1; y >= 0; y--)
				init_tile_stripe(y, 0, 9, min_azimuth_angle, max_azimuth_angle);
			for (int y = 250; y < max_y; y++)
				init_tile_stripe(y, 0, 9, min_azimuth_angle, max_azimuth_angle);
			init_tile_stripe(max_y, 0, max_n, min_azimuth_angle, max_azimuth_angle);
		}
	}
	else
		init_tile_stripe(min_y, min_n, max_n, min_azimuth_angle, max_azimuth_angle);
}

void DataGenerator::init_tile_stripe(int y, int min_n, int max_n, double min_azimuth_angle, double max_azimuth_angle)
{
}

#include "calc.h"

t_map	map_values(float nl, float nh, float ol, float oh)
{
	t_map	map;

	map.nl = nl;
	map.nh = nh;
	map.ol = ol;
	map.oh = oh;
	return (map);
}

float	scale(float i, t_map map)
{
	float	result;

	result = (map.nh - map.nl) * (i - map.ol) / (map.oh - map.ol) + map.nl;
	return (result);
}

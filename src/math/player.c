#include "calc.h"

void	init_player(t_player *player)
{
	player->dir = 'N';//or anything else
	player->view = 0.0f;//facing forward
	player->x = 0.0;
	player->y = 0.0;
}

void	move_player(t_player *player, float xd, float yd)
{
	player->x += xd;
	player->y += yd;
}

void	cast_rays(t_player *player)
{
	int map[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	const int num_rays = WIDTH;
	const float fov = 3.14159265358979323846 / 3.0; // 60 degrees
	const float delta_angle = fov / num_rays;
	float angle = player->view - (fov / 2.0);

	int	i;
	i = 0;
	while (i < num_rays)
	{
		float ray_x = cos(angle);
		float ray_y = sin(angle);
		float distance = 0;
		int hit = 0;
		while (!hit)
		{
			distance += 0.1f;
			int map_x = (int)(player->x + ray_x * distance);
			int map_y = (int)(player->y + ray_y * distance);
			if (map_x >= 0 && map_x < WIDTH && map_y >= 0 && map_y < HEIGHT)
			{
				if (map[map_y][map_x] == 1)
					hit = 1;
			}
			else
				break ;
		}
		printf("Ray %d hit at distance %.2f\n", i, distance);
		angle += delta_angle;
		i++;
	}
}
#include <cstdint>

#ifndef GEOM2D_POINT_H
#define GEOM2D_POINT_H

namespace Geom2D
{
	/*	Point
	*	A Structure that represent a 2D point on 
	*	a screen pixel space.
	*/
	struct Point
	{
		private:
			int16_t PosX;
			int16_t PosY;

		public:
			Point()
			{
				PosX = 0;
				PosY = 0;
			}

			Point(int16_t x, int16_t y)
			{
				PosX = x;
				PosY = y;
			}

			inline int16_t X() const { return PosX; }
			inline int16_t Y() const { return PosY; }
	};
}
#endif //GEOM2D_POINT_H
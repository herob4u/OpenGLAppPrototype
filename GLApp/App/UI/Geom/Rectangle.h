#include <cstdint>
#include <App/UI/Geom/Point.h>

#ifndef GEOM2D_RECT_H
#define GEOM2D_RECT_H

namespace Geom2D
{
	/*	A Structure to represent rectangles on
	*	a screen pixel space.
	*/
	struct Rectangle
	{
		private:
			// Storing the coordinates that make up the 2 points of the rectangle in
			// an array for faster access and improved caching
			//  [x1,y1,x2,y2]
			uint16_t coords[4];

		public:
			Rectangle(const Point& fromCorner, const Point& toCorner)
			{
				coords[0] = fromCorner.X();
				coords[1] = fromCorner.Y();
				coords[2] = toCorner.X();
				coords[3] = toCorner.Y();
			}

			Rectangle(const Point& toCorner)
			{
				coords[0] = 0;
				coords[1] = 0;
				coords[2] = toCorner.X();
				coords[3] = toCorner.Y();
			}

			/* Begin Rectangle Boundaries */
			inline uint16_t GetTop() const
			{
				return (coords[1] > coords[3] ? coords[1] : coords[3]);
			}

			inline uint16_t GetBottom() const
			{
				return (coords[1] > coords[3] ? coords[3] : coords[1]);
			}

			inline uint16_t GetRight() const
			{
				return (coords[0] > coords[2] ? coords[0] : coords[2]);
			}

			inline uint16_t GetLeft() const
			{
				return (coords[0] > coords[2] ? coords[2] : coords[0]);
			}
			/* End Rectangle Boundaries */


			/* Begin Rectangle Points*/
			inline Point GetUpperRight() const
			{
				return Point(GetRight(), GetTop());
			}

			inline Point GetUpperLeft() const
			{
				return Point(GetLeft(), GetTop());
			}

			inline Point GetLowerLeft() const
			{
				return Point(GetLeft(), GetBottom());
			}

			inline Point GetLowerRight() const
			{
				return Point(GetRight(), GetBottom());
			}

			/* End Rectangle Points*/
	};
}
#endif //GEOM2D_RECT_H
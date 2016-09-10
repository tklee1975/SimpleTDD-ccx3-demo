//
//  GeometryHelper.hpp
//  GhostLeg
//
//  Created by Ken Lee on 15/3/2016.
//
//

#ifndef GeometryHelper_hpp
#define GeometryHelper_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class GeometryHelper {
		public:
		static bool isLineIntersect(const Vec2 &point1, const Vec2 &point2,
									const Vec2 &check,
									bool excludePoint1 = false,
									bool excludePoint2 = false);

		static Rect scaleRect(const Rect &inputRect, const float &scale);
		
		static float findAngleDegree(const Vec2 &point1, const Vec2 &point2);
		static float findAngleRadian(const Vec2 &point1, const Vec2 &point2);
		
		
		static Vec2 resolveVec2(float distance, float angleRadian);
		static Vec2 calculateNewTracePosition(const Vec2 &myPos,
						const Vec2 &targetPos,
						float velocity, float timeDelta, bool stopAtTarget=true);
};

#endif /* GeometryHelper_hpp */

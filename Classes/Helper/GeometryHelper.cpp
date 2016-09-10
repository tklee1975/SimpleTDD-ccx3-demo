//
//  GeometryHelper.cpp
//  GhostLeg
//
//  Created by Ken Lee on 15/3/2016.
//
//

#include "GeometryHelper.h"

bool GeometryHelper::isLineIntersect(const Vec2 &point1, const Vec2 &point2, const Vec2 &check,
									 bool excludePoint1, bool excludePoint2)
{
	
	if(excludePoint1) {	// No true if point1 or point2 same as the check point
		if(point1 == check) {
			return false;
		}
	}
	
	if(excludePoint2) {	// No true if point1 or point2 same as the check point
		if(point2 == check) {
			return false;
		}
	}

	
	// Match vertically
	if(check.x == point1.x && check.x == point2.x) {
		float minY = MIN(point1.y, point2.y);
		float maxY = MAX(point1.y, point2.y);
		
		return check.y >= minY && check.y <= maxY;
	}

	// Match horizontally
	if(check.y == point1.y && check.y == point2.y) {
		float minX = MIN(point1.x, point2.x);
		float maxX = MAX(point1.x, point2.x);
		
		return check.x >= minX && check.x <= maxX;
	}

	return false;
}

Rect GeometryHelper::scaleRect(const Rect &inputRect, const float &scale)
{
	float absScale = fabs(scale);		// make it absolute
	
	Vec2 origin = inputRect.origin * absScale;
	Size size = inputRect.size * absScale;
//	log("scale=%f origin=%s size=%s", scale,
//				POINT_TO_STR(origin).c_str(), SIZE_TO_STR(size).c_str());

	return Rect(origin, size);
}


float GeometryHelper::findAngleRadian(const Vec2 &point1, const Vec2 &point2)
{
	float opposite = point2.y - point1.y;
	float adjacent = point2.x - point1.x;
	
	float plus = 0;
	if(point1.x > point2.x) {
		plus = MATH_DEG_TO_RAD(180);
	} else {
		plus = point2.y >= point1.y ? 0 : MATH_DEG_TO_RAD(360);
	}
	
	return plus + atanf(opposite / adjacent);
}

float GeometryHelper::findAngleDegree(const Vec2 &point1, const Vec2 &point2)
{
	float rad = findAngleRadian(point1, point2);
	return MATH_RAD_TO_DEG(rad);
}

Vec2 GeometryHelper::resolveVec2(float distance, float angleRadian)
{
	Vec2 result;
	
	result.x = distance * cosf(angleRadian);
	result.y = distance * sinf(angleRadian);
	
	return result;
}

Vec2 GeometryHelper::calculateNewTracePosition(
					const Vec2 &myPos, const Vec2 &targetPos,
					float velocity, float timeDelta, bool stopAtTarget)
{
	float distance = targetPos.distance(myPos);
	
	if(distance <= velocity * timeDelta) {
		return targetPos;
	}
	
	
	float angle = GeometryHelper::findAngleRadian(myPos, targetPos);
	Vec2 diff = GeometryHelper::resolveVec2(timeDelta * velocity, angle);
	return myPos + diff;
}


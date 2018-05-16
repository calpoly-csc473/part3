
#include "Plane.hpp"


Plane::Plane(const glm::vec3 & n, const float d)
 : normal(n), distance(d)
{}

float Plane::Intersect(const Ray & ray) const
{
	float const denominator = glm::dot(ray.direction, normal);

	if (denominator != 0.f)
	{
		const float numerator = distance - glm::dot(ray.origin, normal);
		const float t = numerator / denominator;

		if (t >= 0)
		{
			return t;
		}
	}

	return -1;
}

glm::vec3 Plane::CalculateNormal(glm::vec3 const & intersectionPoint) const
{
	return normal;
}

std::string Plane::GetObjectType() const
{
	return "Plane";
}
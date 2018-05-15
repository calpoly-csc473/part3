
#pragma once

#include <glm/glm.hpp>
#include <parser/Objects.hpp>

#include "Ray.hpp"
#include "RayHitResults.hpp"


struct Material
{
	parser::Finish finish;
	glm::vec3 color;
	float filter = 0;
};

class Object
{

public:

	Object();

	void SetCastsShadows(bool const CastsShadows);
	void SetID(int const ID);
	void SetTransform(glm::mat4 const & transform);

	bool CastsShadows() const;
	int GetID() const;

	Material & GetMaterial();
	Material const & GetMaterial() const;

	virtual bool Intersect(Ray const & Ray, RayHitResults * const HitInformation) const = 0;

	virtual std::string GetObjectType() const = 0;

protected:

	Material material;
	int ID = -1;

};
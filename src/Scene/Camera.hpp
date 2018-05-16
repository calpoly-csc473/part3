
// Copyright (C) 2018 Ian Dunn
// For conditions of distribution and use, see the LICENSE file


#pragma once

#include <glm/glm.hpp>

#include <RayTracer/Ray.hpp>


class Camera
{

public:

	const glm::vec3 & GetPosition() const;
	const glm::vec3 & GetViewVector() const;
	const glm::vec3 & GetUpVector() const;
	const glm::vec3 & GetRightVector() const;
	const glm::vec3 & GetLookAt() const;

	void SetPosition(glm::vec3 const & position);
	void SetLookAt(glm::vec3 const & LookAt);
	void SetUpVector(glm::vec3 const & upVector);
	void SetRightVector(glm::vec3 const & rightVector);

	static glm::vec2 PixelToView(glm::ivec2 const & Pixel, glm::ivec2 const & ScreenSize);
	Ray GetPixelRay(glm::ivec2 const & Pixel, glm::ivec2 const & ScreenSize) const;

protected:

	glm::vec3 Position = glm::vec3(0, 0, 0);
	glm::vec3 ViewVector = glm::vec3(0, 0, 1);
	glm::vec3 UpVector = glm::vec3(0, 1, 0);
	glm::vec3 RightVector = glm::vec3(1, 0, 0);
	glm::vec3 LookAt = glm::vec3(0, 0, 1);

};

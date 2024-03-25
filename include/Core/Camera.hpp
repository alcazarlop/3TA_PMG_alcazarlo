
#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <memory>

#include "glm.hpp"
#include "Shader.hpp"
#include "Input.hpp"

class Camera {
public:
	Camera(float fov, float aspect, float near, float far);
	Camera();
	~Camera();

	glm::vec3 position_;
	glm::vec3 orientation_;
	glm::vec3 up_;

	void Update(std::shared_ptr<Shader>&);
	void SetupInput(Engine::Input&);

private:
	float fov_;
	float aspect_;
	float near_;
	float far_;
	float speed_;

	void MoveForward();
	void MoveBackwards();
	void MoveRight();
	void MoveLeft();

};

#endif

#include "Camera.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtx/rotate_vector.hpp"
#include "gtx/vector_angle.hpp"
#include "gtc/type_ptr.hpp"
#include "glew.h"

#include <functional>
#include <cstdio>


Camera::Camera(float fov, float aspect, float near, float far) {
	position_ = glm::vec3(0.0f, 0.0f, -5.0f);
	orientation_ = glm::vec3(0.0f, 0.0f, -1.0f);
	up_ = glm::vec3(0.0f, 1.0f, 0.0f);

	this->fov_ = fov;
	this->aspect_ = aspect;
	this->near_ = near;
	this->far_ = far;
	this->speed_ = 0.1f;
}

Camera::Camera() {
	position_ = glm::vec3(0.0f, 0.0f, 5.0f);
	orientation_ = glm::vec3(0.0f, 0.0f, -1.0f);
	up_ = glm::vec3(0.0f, 1.0f, 0.0f);

	this->fov_ = 45.0f;
	this->aspect_ = 640.0f / 480.0f;
	this->near_ = 0.2f;
	this->far_ = 100.0f;
	this->speed_ = 0.1f;
}

Camera::~Camera() {

}

void Camera::Update(std::shared_ptr<Shader>& shader) {
	glm::mat4 projection_matrix = glm::mat4(1.0f);
	glm::mat4 view_matrix = glm::mat4(1.0f);
	
	view_matrix = glm::lookAt(position_, position_ + orientation_, up_);
	projection_matrix = glm::perspective(glm::radians(fov_), aspect_, near_, far_);

	GLuint projection_view = glGetUniformLocation(shader->program_id, "projection_view");
	glUniformMatrix4fv(projection_view, 1, GL_FALSE, glm::value_ptr(projection_matrix * view_matrix));
}


void Camera::SetupInput(Engine::Input& input) {
	input.BindAction(W, IA_Repeat, std::bind(&Camera::MoveForward, this));
	input.BindAction(S, IA_Repeat, std::bind(&Camera::MoveBackwards, this));
	input.BindAction(D, IA_Repeat, std::bind(&Camera::MoveRight, this));
	input.BindAction(A, IA_Repeat, std::bind(&Camera::MoveLeft, this));
}


void Camera::MoveForward() {
	position_ += speed_ * orientation_;
}

void Camera::MoveBackwards() {
	position_ += speed_ * -orientation_;
}

void Camera::MoveRight() {
	position_ += speed_ * glm::normalize(glm::cross(orientation_, up_));
}

void Camera::MoveLeft() {
	position_ += speed_ * -glm::normalize(glm::cross(orientation_, up_));
}
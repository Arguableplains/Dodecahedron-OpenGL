#pragma once
#include <iomanip>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Class that holds math and matrices operations focused on GLM

class ElementsMath{

public:
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
    glm::mat4 transform;

    ElementsMath();

    // Operations related to matricial essencial steps
    void rotate(std::string matrix, float angle, float X, float Y, float Z);
    void translate(std::string matrix, float X, float Y, float Z);
    void scale(std::string matrix, float X, float Y, float Z);
    void perspective();
    glm::mat4 getTransformMatrix();
    void MountTransformMatrix();

    // Reset matrices to avoid problems
    void Reset();

};

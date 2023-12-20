#include "ElementsMath.h"
#include <iomanip>
#include <iostream>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

ElementsMath::ElementsMath(){

    Reset();

}

void ElementsMath::Reset(){

    model = glm::mat4(1.0f);
    view = glm::mat4(1.0f);
    projection = glm::mat4(1.0f);

    // First rotation
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    // Addicional Config
    model = glm::rotate(model, glm::radians((float)glfwGetTime()*90), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));

    view = glm::translate(view, glm::vec3(0.0f, -1.0f, -8.0f));
    view = glm::translate(view, glm::vec3(1*sin(glfwGetTime()), 0.0f, 2*cos(glfwGetTime())));
    projection = glm::perspective(glm::radians(55.0f), 1.0f, 1.0f, 100.0f);

}

void ElementsMath::rotate(std::string matrix, float angle, float X, float Y, float Z){

    if(matrix == "model"){
        model = glm::rotate(model, glm::radians(angle), glm::vec3(X, Y, Z));
    }
    else if(matrix == "view"){
        view = glm::rotate(view, glm::radians(angle), glm::vec3(X, Y, Z));
    }
    else if(matrix == "projection"){
        projection = glm::rotate(projection, glm::radians(angle), glm::vec3(X, Y, Z));
    }

}

void ElementsMath::scale(std::string matrix, float X, float Y, float Z){

    if(matrix == "model"){
        model = glm::scale(model, glm::vec3(X, Y, Z));
    }
    else if(matrix == "view"){
        view = glm::scale(view, glm::vec3(X, Y, Z));
    }
    else if(matrix == "projection"){
        projection = glm::scale(projection, glm::vec3(X, Y, Z));
    }

}

void ElementsMath::translate(std::string matrix, float X, float Y, float Z){

    if(matrix == "model"){
        model = glm::translate(model, glm::vec3(X, Y, Z));
    }
    else if(matrix == "view"){
        view = glm::translate(view, glm::vec3(X, Y, Z));
    }
    else if(matrix == "projection"){
        projection = glm::translate(projection, glm::vec3(X, Y, Z));
    }

}

void ElementsMath::perspective(){

    projection = glm::perspective(glm::radians(60.0f), 1.0f, 1.0f, 100.0f);

}

void ElementsMath::MountTransformMatrix(){
    // This order is important - matrices do not have the commutative properties
    transform = projection * view * model;
}

glm::mat4 ElementsMath::getTransformMatrix(){
    return transform;
}

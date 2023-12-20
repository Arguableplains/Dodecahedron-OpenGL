#include "Utils.h"
#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define PI 3.141596f

void Utils::framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void Utils::processInput(GLFWwindow *window){

     // To close, press ESC
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    // To show only lines, press 1
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // To show the filled vision, press 2
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // To show only points, press 3
    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);

}

float Utils::Xdistance(int angle){
    return (float)(cos(To_radians(angle)));
}

float Utils::Ydistance(int angle){;
    return (float)(sin(To_radians(angle)));
}

float Utils::Sqrt(int value){
    return (float)sqrt(value);
}

float Utils::Sin(float angle){
    return (float)sin(angle);
}

float Utils::Cos(float angle){
    return (float)cos(angle);
}

float Utils::To_radians(double angle){
    return glm::radians(angle);
}

float Utils::To_radians(float angle){
    return glm::radians(angle);
}

float Utils::To_radians(int angle){
    return glm::radians((float)angle);
}

float* Utils::RGB_vector_change(float* array){

    array[3] = -cos(glfwGetTime())/2 +0.5f;
    array[4] = sin(glfwGetTime())/2 + 0.5f;
    array[5] = cos(glfwGetTime())/2 + 0.5f;

    return array;
}

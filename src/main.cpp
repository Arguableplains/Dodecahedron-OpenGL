#include <iostream>
#include <iomanip>
#include "Utils.h"
#include "Shaders.h"
#include "Elements.h"
#include "ElementsMath.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

int main(){

    // Constants
    const float z_translate = (Utils::Sin(Utils::To_radians(54)))*(Utils::Sin(Utils::To_radians(63.44f)));
    const float y_translate = (Utils::Sin(Utils::To_radians(54))) + (Utils::Cos(Utils::To_radians(63.44f))) * (Utils::Sin(Utils::To_radians(54)));
    const float top_translate = (Utils::Sqrt(5))*(2*Utils::Cos(Utils::To_radians(54))) - 0.01f;

    if (!glfwInit())
        return -1;

    // Window Object
    GLFWwindow* window = glfwCreateWindow(600, 600, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    // Elements vertices and indices to draw

    float vertices[] = {
        // positions                                                       // colors
         0.0f, 0.0f, 0.5f,                                                  0.0f, 1.0f, 0.0f,           // Center
         0.0f, 1.0f, 0.0f,                                                  0.0f, 0.0f, 0.0f,           // TOP
         Utils::Xdistance(18),  Utils::Ydistance(18), 0.0f,         0.0f, 0.0f, 0.0f,           // TOP - Right
         Utils::Xdistance(54), -(Utils::Ydistance(54)), 0.0f,       0.0f, 0.0f, 0.0f,           // BOTTOM - Right
        -(Utils::Xdistance(54)), -(Utils::Ydistance(54)), 0.0f,     0.0f, 0.0f, 0.0f,           // BOTTOM - Left
        -(Utils::Xdistance(18)),  Utils::Ydistance(18), 0.0f,       0.0f, 0.0f, 0.0f            // TOP - Left
    };

    unsigned int indices[] = {
        0,
        1, 2,
        2, 3,
        3, 4,
        4, 5,
        5, 1
    };

    // Main GL objects
    Shaders shader_obj;
    ElementsMath elementsmath;

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)){

        // Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Capturing keypress
        Utils::processInput(window);

        // Clear the previous frame
        glClear(GL_COLOR_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST | GL_DEPTH_BUFFER_BIT);

        // Elements object
        Elements elements(Utils::RGB_vector_change(vertices), indices, sizeof(vertices), sizeof(indices));

        // Writing the shaders stringsm, creating and compile the shaders programs
        std::string fragmentShader = shader_obj.FragShader();
        std::string vertexShader =  shader_obj.VertexShader();
        unsigned int shader = shader_obj.CreateShader(vertexShader, fragmentShader);
        glUseProgram(shader);

        // Base rendering
        elementsmath.rotate("model", 180.0f, 0.0f, 1.0f, 0.0f);
        elementsmath.MountTransformMatrix();
        shader_obj.UniformConfig("transform", shader, elementsmath.getTransformMatrix());

        glDrawElements(GL_TRIANGLE_FAN, 11, GL_UNSIGNED_INT, 0);
        elementsmath.Reset();

        // Top Rendering
        elementsmath.rotate("model", 180.0f, 0.0f, 0.0f, 1.0f);
        elementsmath.translate("model", 0.0f, 0.0f, top_translate);
        elementsmath.MountTransformMatrix();
        shader_obj.UniformConfig("transform", shader, elementsmath.getTransformMatrix());

        glDrawElements(GL_TRIANGLE_FAN, 11, GL_UNSIGNED_INT, 0);
        elementsmath.Reset();

        // Body Rendering
        for(int i = 0; i < 20; i++){

            if(i % 2 != 0){

                if(i < 10){
                    glMatrixMode(GL_MODELVIEW);

                    elementsmath.rotate("model", 36.0f*i, 0.0f, 0.0f, 1.0f);
                    elementsmath.translate("model", 0.0f, y_translate, z_translate);
                    elementsmath.rotate("model", 63.44f, 1.0f, 0.0f, 0.0f);
                    elementsmath.rotate("model", 180.0f, 0.0f, 1.0f, 0.0f);

                    elementsmath.MountTransformMatrix();
                    shader_obj.UniformConfig("transform", shader, elementsmath.getTransformMatrix());

                    glDrawElements(GL_TRIANGLE_FAN, 11, GL_UNSIGNED_INT, 0);

                    elementsmath.Reset();
                }
                else{
                    glMatrixMode(GL_MODELVIEW);

                    elementsmath.translate("model", 0.0f, 0.0f, top_translate);
                    elementsmath.rotate("model", 180.0f, 0.0f, 0.0f, 1.0f);
                    elementsmath.rotate("model", 36.0f*i, 0.0f, 0.0f, 1.0f);
                    elementsmath.translate("model", 0.0f, y_translate, -z_translate);
                    elementsmath.rotate("model", -63.44f, 1.0f, 0.0f, 0.0f);

                    elementsmath.MountTransformMatrix();

                    shader_obj.UniformConfig("transform", shader, elementsmath.getTransformMatrix());

                    glDrawElements(GL_TRIANGLE_FAN, 11, GL_UNSIGNED_INT, 0);

                    elementsmath.Reset();

                }

            }

        }

        // Swap front and back buffers
        glfwSwapBuffers(window);

        //Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


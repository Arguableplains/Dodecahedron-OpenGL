#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// This Class holds only static methods which have mathematical and general uses in the main code

class Utils{

    public:
        // OpenGL callback function which resizes the viewport at each window width and height change
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

        // Window Input Detection
        static void processInput(GLFWwindow *window);

        // Trigonometry
        static float Sin(float angle);
        static float Cos(float angle);

        // Square Root
        static float Sqrt(int value);

        // Geometrical purpose methods to render the regular pentagons
        static float Xdistance(int angle);
        static float Ydistance(int angle);

        // Convertion methods - glm is the base convertion library - Degrees to Radians
        static float To_radians(double angle);
        static float To_radians(float angle);
        static float To_radians(int angle);

        // Vector changer which gives new values to the main vertex buffer array
        static float* RGB_vector_change(float* array);

};

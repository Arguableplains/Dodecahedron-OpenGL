#include "Shaders.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

unsigned int Shaders::CreateShader(const std::string& vertexShader, const std::string& fragmentShader){

    // Shader compiled objects
    vertex_shader = CompileShader(GL_VERTEX_SHADER, vertexShader);
    fragment_shader = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    // The Shader's program object link all the recently compiled shaders
    program = glCreateProgram();

    // Attachment phase
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);

    // Link phase
    glLinkProgram(program);
    glValidateProgram(program);

    // The shader objects must be deleted after attachment
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return program;

}
unsigned int Shaders::CompileShader(unsigned int type, const std::string& source){

    // Shader Object Id
    id = glCreateShader(type);
    src = source.c_str();

    // Pass the shader object and string address to be compiled
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    // Verification
    if(!result){
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*) alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Failed to compile the " << (type == GL_VERTEX_SHADER ? "Vertex " : "Fragment ") <<"shader!!" << std::endl;
        std::cout << message << std::endl;

        glDeleteShader(id);
        return 0;
    }

    return id;

}

std::string Shaders::VertexShader(){

        vertexShader_obj =
        "#version 330 core\n"
        "\n"
        "layout(location = 0) in vec3 vector_position;" // positions are in location 0
        "layout(location = 1) in vec3 vector_color;"    // colors are in location 1
        "\n"
        "uniform mat4 transform;"
        "\n"
        "out vec3 colors;"
        "\n"
        "void main()\n"
        "{\n"
        "   gl_Position = transform * vec4(vector_position, 1.0f);"
        "   colors = vector_color;"
        "}\n";

    return vertexShader_obj;

}
std::string Shaders::FragShader(){

        fragmentShader_obj =
        "#version 330 core\n"
        "\n"
        "out vec4 FragColor;"
        "in vec3 colors;"
        "\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(colors, 1.0f);"
        "}\n";

        return fragmentShader_obj;

}

void Shaders::UniformConfig(const char* uniform_name, float timeValue, unsigned int shaderProgram){

    // These changes are applicated to all vertices and pixels

    float redValue = (Utils::Sin(timeValue) / 2.0f) + 0.5f;
    float greenValue = (Utils::Sin(timeValue) / 2.0f) + 0.5f;
    float blueValue = -(Utils::Sin(timeValue) / 2.0f + 0.5f);

    // Getting the uniform to change and set
    int vertexColorLocation = glGetUniformLocation(shaderProgram, uniform_name);
    // The found uniform is setted with the following parameters and then, sent to the shader strings
    glUniform4f(vertexColorLocation, redValue, greenValue, blueValue, 1.0f);

}

void Shaders::UniformConfig(const char* uniform_name, unsigned int shaderProgram, glm::mat4 trans){

    unsigned int transform = glGetUniformLocation(shaderProgram, uniform_name);
    glUniformMatrix4fv(transform, 1, GL_FALSE, glm::value_ptr(trans));

}

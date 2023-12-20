#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Shader's class declaration which holds all the processes related to shaders, textures, lighting and so on

class Shaders{

    public:
        unsigned int vertex_shader;
        unsigned int fragment_shader;
        unsigned int program;
        unsigned int id;
        const char* src;
        std::string vertexShader_obj;
        std::string fragmentShader_obj;

        // Shader program's strings getters
        std::string VertexShader();
        std::string FragShader();

        // Shader's program creation and compilation
        unsigned int CreateShader( const std::string& vertexShader, const std::string& fragmentShader );
        unsigned int CompileShader(unsigned int type, const std::string& source);

        // Methods to perform shader's communication between vertex and fragment section
        void UniformConfig(const char* uniform_name, float timeValue, unsigned int shaderProgram);
        void UniformConfig(const char* uniform_name, unsigned int shaderProgram, glm::mat4 trans);

};

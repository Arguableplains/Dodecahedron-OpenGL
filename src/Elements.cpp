#include "Elements.h"
#include "Utils.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Elements::Elements(float* vertices, unsigned int* indices, int size_of_vetices, int size_of_indices){

    // Buffers

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, size_of_vetices, vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*) (3 * (sizeof(float))));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_of_indices, indices, GL_STATIC_DRAW);

}

Elements::~Elements(){

    glDeleteBuffers( 1, &VBO );
    glDeleteBuffers( 1, &VAO );
    glDeleteBuffers( 1, &EBO );

}

// Class which holds the OpenGL most important elements and its base construction

class Elements{

    public:
        unsigned int VBO;
        unsigned int VAO;
        unsigned int EBO;

        Elements(float* vertices, unsigned int* indices, int size_of_vertices, int size_of_indices);
        ~Elements();

};

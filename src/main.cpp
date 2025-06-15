#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

int g_windowSizeX = 1920;
int g_windowSizeY = 1080;

void glfwWindowSizeCallBack(GLFWwindow* window, int width, int height)
{
    g_windowSizeX = width;
    g_windowSizeY = height;
    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
}

void glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}
int main(void)
{   

    /* Initialize the library */
    if (!glfwInit()){
        cout << "glfwInit не удалось загрузить" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "Hello World", glfwGetPrimaryMonitor(), NULL);
    if (!window)
    {
        cout << "glfwCreateWindow Сломалось" << endl;
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(window, glfwWindowSizeCallBack);
    glfwSetKeyCallback(window, glfwKeyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGL())
    {
        cout << "ERROR CAN'T LOAD GLAD" << endl;
        return -1;
    }

    cout << "Renderer: " << glGetString(GL_RENDERER) << endl;
    cout << "OpenGL verison" << glGetString(GL_VERSION) << endl;

    glClearColor(0, 1, 0, 1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
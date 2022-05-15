
#include <GLFW/glfw3.h>
#include <adder.h>
#include <cmaketutsConfig.h>

#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Hello World\n";
    std::cout << add(72.1f, 73.8f) << std::endl;

    std::cout << argv[0] << " Version " << CMAKETUTS_VERSION_MAJOR << "."
              << CMAKETUTS_VERSION_MINOR << "\n";

    GLFWwindow* window;

    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }
    window = glfwCreateWindow(300, 300, "Gears", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to open GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Draw gears
        // draw();

        // Update animation
        // animate();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}
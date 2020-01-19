#include <Engine/Engine.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace VoxelEngine;

Engine::Engine() {
    glfwSetErrorCallback([](int errorCode, const char* description) {
        std::cout << "GLFW error: " << description << std::endl;
    });
    glfwInit();

    m_updateClock = std::make_unique<Clock>(0.0f);
    m_updateGroup = std::make_unique<SystemGroup>(*m_updateClock);
}

Engine::~Engine() {
    glfwTerminate();
}

void Engine::setGraphics(Graphics&& graphics) {
    m_graphics = std::make_unique<Graphics>(std::move(graphics));
}

void Engine::addWindow(Window& window) {
    m_window = &window;
}

void Engine::run() {
    while (!m_window->shouldClose()) {
        m_window->update();
        m_updateClock->update();
        m_updateGroup->update();
    }
}
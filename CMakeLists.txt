cmake_minimum_required(VERSION 4.0.2 FATAL_ERROR)

set(PROJECT_NAME Reposit2)
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
   src/main.cpp

   src/Resources/ResourceManager.cpp
   src/Resources/ResourceManager.h
   src/Resources/stb_image.h

   src/Renderer/Texture2D.cpp
   src/Renderer/Texture2D.h
   src/Renderer/Sprite.cpp
   src/Renderer/Sprite.h
   src/Renderer/AnimatedSprite.h
   src/Renderer/AnimatedSprite.cpp
   src/Renderer/ShaderProgram.cpp
   src/Renderer/ShaderProgram.h
   src/Renderer/VertexBuffer.cpp
   src/Renderer/VertexBuffer.h
   src/Renderer/VertexArray.cpp
   src/Renderer/VertexArray.h
   src/Renderer/IndexBuffer.cpp
   src/Renderer/IndexBuffer.h
   src/Renderer/VertexBufferLayout.cpp
   src/Renderer/VertexBufferLayout.h
   
   src/Game/Game.cpp
   src/Game/Game.h
   src/Game/Player.cpp
   src/Game/Player.h
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLE OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_linK_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad )

include_directories(external/glm)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
					COMMAND ${CMAKE_COMMAND} -E copy_directory
					${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)
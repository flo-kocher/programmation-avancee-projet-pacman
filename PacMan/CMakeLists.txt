cmake_minimum_required(VERSION 3.7)

project(PacManGame LANGUAGES CXX)


find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PRIVATE main.cpp include/MapInitialization.h src/MapInitialization.cpp include/Constante.h include/KeyboardManager.h src/KeyboardManager.cpp include/Zone.h src/Zone.cpp include/Intersection.h src/Intersection.cpp include/GameInterface.h src/GameInterface.cpp include/Character.h src/Character.cpp include/Ghost.h src/Ghost.cpp include/Pacman.h src/Pacman.cpp include/Pellet.h src/Pellet.cpp include/BigPellet.h src/BigPellet.cpp include/GameManager.h src/GameManager.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_compile_definitions(${PROJECT_NAME} PRIVATE "SDL_MAIN_HANDLED")
IF(WIN32)
	target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2::SDL2main)
	add_custom_command(
        TARGET PacManGame POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:SDL2::SDL2>" "$<TARGET_FILE_DIR:PacManGame>"
        VERBATIM
    )
ELSE()
	target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})
ENDIF()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/pacman_sprites.bmp
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)	

IF (MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
ENDIF()

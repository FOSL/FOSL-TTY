project(FOSL-TTY)

add_library(
	${PROJECT_NAME}

	./FOSL/TTY.hpp
	./FOSL/TTY/Base.cpp
	./FOSL/TTY/Base.hpp
)

target_include_directories(
	${PROJECT_NAME} PUBLIC

	${PROJECT_SOURCE_DIR}
)

target_link_libraries(
	${PROJECT_NAME}

	FOSL-Utilities
	FOSL-Math
)

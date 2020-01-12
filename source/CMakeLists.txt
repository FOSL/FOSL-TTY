project(FOSL-TTY)

add_library(
	${PROJECT_NAME}

	./FOSL/TTY.hpp
	./FOSL/TTY/base.cpp
	./FOSL/TTY/base.hpp
)

target_include_directories(
	${PROJECT_NAME} PUBLIC

	${PROJECT_SOURCE_DIR}
)

target_link_libraries(
	${PROJECT_NAME}

	FOSL-math
)

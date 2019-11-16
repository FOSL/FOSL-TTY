project(fosl-tty)

add_library(
	${PROJECT_NAME}

	./fosl/tty/base.cpp
	./fosl/tty/base.h
)

target_include_directories(
	${PROJECT_NAME} PUBLIC

	${PROJECT_SOURCE_DIR}

	${fosl-math_SOURCE_DIR}
	${fosl-util_SOURCE_DIR}
	${fosl-arm-util_SOURCE_DIR}
)

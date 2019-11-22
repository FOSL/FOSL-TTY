project(fosl-tty)

add_library(
	${PROJECT_NAME}

	./fosl/tty.h
	./fosl/tty/base.cpp
	./fosl/tty/base.h
)

target_include_directories(
	${PROJECT_NAME} PUBLIC

	${PROJECT_SOURCE_DIR}
)

target_link_libraries(
	${PROJECT_NAME}

	fosl-util
)

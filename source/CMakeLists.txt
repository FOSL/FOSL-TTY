project(tty)

add_library(
	${PROJECT_NAME}

	./tty/Base.cpp
	./tty/Base.h
)

target_include_directories(
	${PROJECT_NAME} PUBLIC

	${PROJECT_SOURCE_DIR}

	${util_SOURCE_DIR}
	${math_SOURCE_DIR}
)

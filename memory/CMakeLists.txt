cmake_minimum_required(VERSION 3.9)

# list the header files
set(HEADER_FILES
	include/memory/memory.h
)

# list the source files
set(SOURCE_FILES
	src/memory/memory.cpp
)


# add library target
add_library(memory
	${HEADER_FILES}
	${SOURCE_FILES}
)

# make it reflect the same structure as the one on disk
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${HEADER_FILES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

target_include_directories(memory
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/../external/stb
)

# Windows specfic flags to enable W variations of winapi
if(WIN32)
	target_compile_definitions(memory
		PRIVATE
			OS_WINDOWS=1
	)
endif()


# enable C++17
# disable any compiler specifc extensions
# add d suffix in debug mode
target_compile_features(memory PUBLIC cxx_std_17)
set_target_properties(memory PROPERTIES
	CXX_EXTENSIONS OFF
	DEBUG_POSTFIX d
)

# define debug macro
target_compile_definitions(memory PRIVATE "$<$<CONFIG:DEBUG>:DEBUG>")

# generate exports header file
include(GenerateExportHeader)
generate_export_header(memory
	EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/include/memory/Exports.h
)

# list include directories
target_include_directories(memory
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
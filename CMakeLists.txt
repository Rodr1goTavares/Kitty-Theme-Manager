
cmake_minimum_required(VERSION 3.0)
project(ktm C)

###############################################################################
## Project files ########################################################
###############################################################################

file(GLOB_RECURSE sources src/main/*.c src/main/*.h)

if(NOT sources)
    message(FATAL_ERROR "Nenhum arquivo .c encontrado em src/main/")
endif()

###############################################################################
## Definition of the Executable ####################################################
###############################################################################

add_executable(ktm ${sources})

target_compile_options(ktm PUBLIC -std=c11 -Wall -Wextra -Wpedantic)

target_include_directories(ktm PUBLIC src/main)

###############################################################################
## Tests ##########################################################
###############################################################################

find_package(CUnit)

if(CUNIT_FOUND)
    file(GLOB_RECURSE sources_test src/test/*.c)

    if(sources_test)
        add_executable(unit_tests ${sources_test} ${sources})
        target_compile_definitions(unit_tests PUBLIC UNIT_TESTS)
        target_link_libraries(unit_tests PUBLIC ${CUNIT_LIBRARIES})
        target_include_directories(unit_tests PUBLIC ${CUNIT_INCLUDE_DIRS})
    else()
        message(WARNING "Nenhum arquivo de teste encontrado em src/test/")
    endif()
endif()

###############################################################################
## Installation and Packaging #################################################
###############################################################################

install(TARGETS ktm DESTINATION bin)
install(DIRECTORY resources DESTINATION bin)

set(CPACK_PACKAGE_NAME "KTM")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_MONOLITHIC_INSTALL 1)

include(CPack)



cmake_minimum_required(VERSION 3.0) # Definir versão mínima do CMake
project(ktm C) # Especifica que o projeto usa C

###############################################################################
## Arquivos do projeto ########################################################
###############################################################################

# Buscar recursivamente os arquivos fonte e cabeçalhos em src/main/
file(GLOB_RECURSE sources src/main/*.c src/main/*.h)

# Se a variável 'sources' estiver vazia, forçamos pelo menos um arquivo principal
if(NOT sources)
    message(FATAL_ERROR "Nenhum arquivo .c encontrado em src/main/")
endif()

###############################################################################
## Definição do Executável ####################################################
###############################################################################

# Criar o executável sem incluir arquivos de recursos
add_executable(ktm ${sources})

# Definir opções de compilação para C
target_compile_options(ktm PUBLIC -std=c11 -Wall -Wextra -Wpedantic)

# Permitir includes relativos ao diretório src/main
target_include_directories(ktm PUBLIC src/main)

###############################################################################
## Testes (Opcional) ##########################################################
###############################################################################

# Buscar biblioteca CUnit para testes (opcional)
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
## Instalação e Empacotamento #################################################
###############################################################################

install(TARGETS ktm DESTINATION bin)
install(DIRECTORY resources DESTINATION bin)

set(CPACK_PACKAGE_NAME "KTM")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_MONOLITHIC_INSTALL 1)

include(CPack)


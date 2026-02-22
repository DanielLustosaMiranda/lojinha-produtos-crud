cmake_minimum_required(VERSION 3.16)
project(eda_1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Binario main
add_executable(${PROJECT_NAME}
    src/main.c
    src/caixa.c
    src/cliente.c
    src/produto.c
    src/menuProduto.c
    src/menuCliente.c
    utils/utils.c
)
target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)
target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/utils
)
target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall
        -Wextra
        -Wshadow
)

file(COPY codes DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

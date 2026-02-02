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
    src/menuProduto.c
    src/menucliente.c
    src/produto.c
)
target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall
        -Wextra
        -Wshadow
)
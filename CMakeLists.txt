cmake_minimum_required(VERSION 3.16)
project(eda_1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    src/main.c
    src/produto.c
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

add_executable(test_app
    src/produto.c
    test/testProduto.c
)

target_include_directories(test_app
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)
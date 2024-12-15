cmake_minimum_required(VERSION 3.16)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 1.0.${PATCH_VERSION})

# Для Debug:
set(CMAKE_CXX_FLAGS_DEBUG "-static-libgcc -static-libstdc++ -std=gnu++17")

# Для Release:
set(CMAKE_CXX_FLAGS_RELEASE "-static-libgcc -static-libstdc++ -std=gnu++17")


project(VectorGraphicEditor VERSION ${PROJECT_VESRION})


set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(VectorGraphicEditor main.cpp)

if(MSVC)
    
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
    
    set(CPACK_GENERATOR ZIP)

elseif(UNIX)
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)

    set(CPACK_GENERATOR DEB)
endif()

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dmitryanons@gmail.com)


# Включаем тестирование
include(CTest)




# Настройки для пакета
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


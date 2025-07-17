# Install script for directory: /home/nabil/cub3D/SDL/SDL2_image

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "library" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2_image-2.0.so.0.800.8"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2_image-2.0.so.0"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/nabil/cub3D/SDL/SDL2_image/build/libSDL2_image-2.0.so.0.800.8"
    "/home/nabil/cub3D/SDL/SDL2_image/build/libSDL2_image-2.0.so.0"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2_image-2.0.so.0.800.8"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2_image-2.0.so.0"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "library" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/nabil/cub3D/SDL/SDL2_image/build/libSDL2_image-2.0.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "DEVEL" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES "/home/nabil/cub3D/SDL/SDL2_image/include/SDL_image.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2_image" TYPE FILE FILES
    "/home/nabil/cub3D/SDL/SDL2_image/build/SDL2_imageConfig.cmake"
    "/home/nabil/cub3D/SDL/SDL2_image/build/SDL2_imageConfigVersion.cmake"
    "/home/nabil/cub3D/SDL/SDL2_image/cmake/Findlibjxl.cmake"
    "/home/nabil/cub3D/SDL/SDL2_image/cmake/Findwebp.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "devel" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2_image/SDL2_image-shared-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2_image/SDL2_image-shared-targets.cmake"
         "/home/nabil/cub3D/SDL/SDL2_image/build/CMakeFiles/Export/996dff568264449ea4952561e3028d60/SDL2_image-shared-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2_image/SDL2_image-shared-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2_image/SDL2_image-shared-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2_image" TYPE FILE FILES "/home/nabil/cub3D/SDL/SDL2_image/build/CMakeFiles/Export/996dff568264449ea4952561e3028d60/SDL2_image-shared-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/SDL2_image" TYPE FILE FILES "/home/nabil/cub3D/SDL/SDL2_image/build/CMakeFiles/Export/996dff568264449ea4952561e3028d60/SDL2_image-shared-targets-noconfig.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "devel" OR NOT CMAKE_INSTALL_COMPONENT)
  
            # FIXME: use file(COPY_FILE) if minimum CMake version >= 3.21
            execute_process(COMMAND "${CMAKE_COMMAND}" -E copy_if_different
                "/home/nabil/cub3D/SDL/SDL2_image/build/SDL2_image-.pc"
                "/home/nabil/cub3D/SDL/SDL2_image/build/SDL2_image.pc")
            file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig"
                TYPE FILE
                FILES "/home/nabil/cub3D/SDL/SDL2_image/build/SDL2_image.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/home/nabil/cub3D/SDL/SDL2_image/build/libSDL2_image.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "library" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/SDL2_image" TYPE FILE FILES "/home/nabil/cub3D/SDL/SDL2_image/LICENSE.txt")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/nabil/cub3D/SDL/SDL2_image/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

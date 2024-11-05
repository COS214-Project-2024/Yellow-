# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt" AND EXISTS "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitinfo.txt" AND
  "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt" IS_NEWER_THAN "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/build/_deps/ftxui-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/build/_deps/ftxui-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"
            clone --no-checkout --config "advice.detachedHead=false" "https://github.com/ArthurSonzogni/ftxui" "ftxui-src"
    WORKING_DIRECTORY "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/build/_deps"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/ArthurSonzogni/ftxui'")
endif()

execute_process(
  COMMAND "/usr/bin/git"
          checkout "v5.0.0" --
  WORKING_DIRECTORY "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/build/_deps/ftxui-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'v5.0.0'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/build/_deps/ftxui-src"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/build/_deps/ftxui-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitinfo.txt" "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt'")
endif()

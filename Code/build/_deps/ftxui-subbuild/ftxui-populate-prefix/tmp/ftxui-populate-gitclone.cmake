# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

<<<<<<< HEAD
if(EXISTS "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt" AND EXISTS "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitinfo.txt" AND
  "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt" IS_NEWER_THAN "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt'"
=======
if(EXISTS "/Users/joshuacilliers/Documents/2024/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt" AND EXISTS "/Users/joshuacilliers/Documents/2024/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitinfo.txt" AND
  "/Users/joshuacilliers/Documents/2024/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt" IS_NEWER_THAN "/Users/joshuacilliers/Documents/2024/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitinfo.txt")
  message(VERBOSE
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/Users/joshuacilliers/Documents/2024/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt'"
>>>>>>> 5ed6fd9fbbc33feab7df21f4a1a7e48efebf6e20
  )
  return()
endif()

<<<<<<< HEAD
execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-src'")
=======
# Even at VERBOSE level, we don't want to see the commands executed, but
# enabling them to be shown for DEBUG may be useful to help diagnose problems.
cmake_language(GET_MESSAGE_LOG_LEVEL active_log_level)
if(active_log_level MATCHES "DEBUG|TRACE")
  set(maybe_show_command COMMAND_ECHO STDOUT)
else()
  set(maybe_show_command "")
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/Users/joshuacilliers/Documents/2024/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-src"
  RESULT_VARIABLE error_code
  ${maybe_show_command}
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/Users/joshuacilliers/Documents/2024/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-src'")
>>>>>>> 5ed6fd9fbbc33feab7df21f4a1a7e48efebf6e20
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"
            clone --no-checkout --config "advice.detachedHead=false" "https://github.com/ArthurSonzogni/ftxui" "ftxui-src"
<<<<<<< HEAD
    WORKING_DIRECTORY "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps"
    RESULT_VARIABLE error_code
=======
    WORKING_DIRECTORY "/Users/joshuacilliers/Documents/2024/COS214/Project/COS-214-Project/Code/build/_deps"
    RESULT_VARIABLE error_code
    ${maybe_show_command}
>>>>>>> 5ed6fd9fbbc33feab7df21f4a1a7e48efebf6e20
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
<<<<<<< HEAD
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
=======
  message(NOTICE "Had to git clone more than once: ${number_of_tries} times.")
>>>>>>> 5ed6fd9fbbc33feab7df21f4a1a7e48efebf6e20
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/ArthurSonzogni/ftxui'")
endif()

execute_process(
  COMMAND "/usr/bin/git"
          checkout "v5.0.0" --
<<<<<<< HEAD
  WORKING_DIRECTORY "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-src"
  RESULT_VARIABLE error_code
=======
  WORKING_DIRECTORY "/Users/joshuacilliers/Documents/2024/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-src"
  RESULT_VARIABLE error_code
  ${maybe_show_command}
>>>>>>> 5ed6fd9fbbc33feab7df21f4a1a7e48efebf6e20
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'v5.0.0'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git" 
            submodule update --recursive --init 
<<<<<<< HEAD
    WORKING_DIRECTORY "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-src"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-src'")
=======
    WORKING_DIRECTORY "/Users/joshuacilliers/Documents/2024/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-src"
    RESULT_VARIABLE error_code
    ${maybe_show_command}
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/Users/joshuacilliers/Documents/2024/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-src'")
>>>>>>> 5ed6fd9fbbc33feab7df21f4a1a7e48efebf6e20
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
<<<<<<< HEAD
  COMMAND ${CMAKE_COMMAND} -E copy "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitinfo.txt" "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt'")
=======
  COMMAND ${CMAKE_COMMAND} -E copy "/Users/joshuacilliers/Documents/2024/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitinfo.txt" "/Users/joshuacilliers/Documents/2024/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  ${maybe_show_command}
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/Users/joshuacilliers/Documents/2024/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/ftxui-populate-gitclone-lastrun.txt'")
>>>>>>> 5ed6fd9fbbc33feab7df21f4a1a7e48efebf6e20
endif()

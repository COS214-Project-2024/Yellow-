# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-src"
  "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-build"
  "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix"
  "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/tmp"
  "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp"
  "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src"
  "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/media/daniel/STORE/1. Silver/_UPWork/Year 3/Semester 2/COS214/Project/COS-214-Project/Code/build/_deps/ftxui-subbuild/ftxui-populate-prefix/src/ftxui-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

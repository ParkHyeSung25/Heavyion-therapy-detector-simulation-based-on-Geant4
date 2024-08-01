# Install script for directory: /Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3

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
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/G4tut")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/G4tut" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/G4tut")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/hyesungpark/geant4_install/11.0.3/lib"
      -delete_rpath "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/G4tut")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -u -r "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/G4tut")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/G4tut" TYPE FILE FILES
    "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/tutorial.in"
    "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/tutorial.out"
    "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/icons.mac"
    "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/gui.mac"
    "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/run.png"
    "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/init.mac"
    "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/init_vis.mac"
    "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/run1.mac"
    "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/vis.mac"
    "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/scoring.mac"
    "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/draw.mac"
    "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/drawSlice.mac"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/rootIO/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/hyesungpark/geant4_install/11.0.3/crystal_detector_11.0.3/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

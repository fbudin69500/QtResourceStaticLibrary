CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )
CMAKE_POLICY(VERSION 2.6)
PROJECT(QtIcon)


find_package(Qt4 REQUIRED )
include(${QT_USE_FILE})

find_package(SlicerExecutionModel REQUIRED )
include(${SlicerExecutionModel_USE_FILE})

# Use the include path and library for Qt that is used by VTK.
INCLUDE_DIRECTORIES(
  ${QT_INCLUDE_DIR}
  ${TestQt4_BINARY_DIR}
  ${TestQt4_SOURCE_DIR}
)

QT4_WRAP_CPP(MOC_FILES TestQt4.h)
QT4_WRAP_UI(UI_FILES TestQt4.ui)
QT4_ADD_RESOURCES(RESOURCES resources.qrc)

#set(TestQt4_SOURCE main.cxx TestQt4.cxx ${MOC_FILES} ${UI_FILES} ${RESOURCES})

#add_executable( TestQt4 ${TestQt4_SOURCE})
#target_link_libraries(TestQt4 ${QT_LIBRARIES})


set(TestQt4_SOURCE TestQt4.cxx ${MOC_FILES} ${UI_FILES} ${RESOURCES})

SEMMacroBuildCLI(
NAME QtIcon
EXECUTABLE_ONLY
ADDITIONAL_SRCS ${TestQt4_SOURCE}
TARGET_LIBRARIES ${QT_LIBRARIES}
LINK_DIRECTORIES ${QT_LIBRARY_DIRS}
INCLUDE_DIRECTORIES ${QT_INCLUDE_DIR}
)
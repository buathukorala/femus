#
#  femusMacroBuildUnitTest.cmake
#  maf
#
#  Created by Simone Bnà 
#
#


MACRO(femusMacroBuildUnitTest foldername appname)

INCLUDE(CTest)

# Build the executable
ADD_EXECUTABLE(${appname} ${CMAKE_SOURCE_DIR}/unittests/${foldername}/main.cpp)

# Link the executable to the petsc anf femttu libs
TARGET_LINK_LIBRARIES(${appname} femus)
TARGET_LINK_LIBRARIES(${appname} ${PETSC_LIBRARIES})
TARGET_LINK_LIBRARIES(${appname} ${B64_LIBRARIES})
TARGET_LINK_LIBRARIES(${appname} ${JSONCPP_LIBRARIES})
TARGET_LINK_LIBRARIES(${appname} ${ADEPT_LIBRARIES})

IF(FPARSER_FOUND)
  TARGET_LINK_LIBRARIES(${appname} ${FPARSER_LIBRARY})
ENDIF(FPARSER_FOUND)

IF(MPI_FOUND)
  TARGET_LINK_LIBRARIES(${appname} ${MPI_EXTRA_LIBRARY})
ENDIF(MPI_FOUND)

IF(HDF5_FOUND)
  TARGET_LINK_LIBRARIES(${appname} ${HDF5_LIBRARIES})
ENDIF(HDF5_FOUND)

ADD_TEST(NAME ${appname} COMMAND ${appname})

ENDMACRO(femusMacroBuildUnitTest)
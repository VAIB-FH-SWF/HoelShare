#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/EnumConverter.o \
	${OBJECTDIR}/InputHandler.o \
	${OBJECTDIR}/P2PGMPicture.o \
	${OBJECTDIR}/Picture.o \
	${OBJECTDIR}/PictureFactory.o \
	${OBJECTDIR}/exception/FileNotFoundException.o \
	${OBJECTDIR}/exception/HoelShareException.o \
	${OBJECTDIR}/exception/IndexOutOfRangeException.o \
	${OBJECTDIR}/exception/InputException.o \
	${OBJECTDIR}/exception/InvalidPictureException.o \
	${OBJECTDIR}/exception/NotImplementedException.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/7.bildbearbeitung

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/7.bildbearbeitung: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/7.bildbearbeitung ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/EnumConverter.o: EnumConverter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/EnumConverter.o EnumConverter.cpp

${OBJECTDIR}/InputHandler.o: InputHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InputHandler.o InputHandler.cpp

${OBJECTDIR}/P2PGMPicture.o: P2PGMPicture.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/P2PGMPicture.o P2PGMPicture.cpp

${OBJECTDIR}/Picture.o: Picture.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Picture.o Picture.cpp

${OBJECTDIR}/PictureFactory.o: PictureFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PictureFactory.o PictureFactory.cpp

${OBJECTDIR}/exception/FileNotFoundException.o: exception/FileNotFoundException.cpp 
	${MKDIR} -p ${OBJECTDIR}/exception
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exception/FileNotFoundException.o exception/FileNotFoundException.cpp

${OBJECTDIR}/exception/HoelShareException.o: exception/HoelShareException.cpp 
	${MKDIR} -p ${OBJECTDIR}/exception
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exception/HoelShareException.o exception/HoelShareException.cpp

${OBJECTDIR}/exception/IndexOutOfRangeException.o: exception/IndexOutOfRangeException.cpp 
	${MKDIR} -p ${OBJECTDIR}/exception
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exception/IndexOutOfRangeException.o exception/IndexOutOfRangeException.cpp

${OBJECTDIR}/exception/InputException.o: exception/InputException.cpp 
	${MKDIR} -p ${OBJECTDIR}/exception
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exception/InputException.o exception/InputException.cpp

${OBJECTDIR}/exception/InvalidPictureException.o: exception/InvalidPictureException.cpp 
	${MKDIR} -p ${OBJECTDIR}/exception
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exception/InvalidPictureException.o exception/InvalidPictureException.cpp

${OBJECTDIR}/exception/NotImplementedException.o: exception/NotImplementedException.cpp 
	${MKDIR} -p ${OBJECTDIR}/exception
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exception/NotImplementedException.o exception/NotImplementedException.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/7.bildbearbeitung

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

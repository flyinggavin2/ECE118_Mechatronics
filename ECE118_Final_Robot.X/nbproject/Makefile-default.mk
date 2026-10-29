#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ECE118_Final_Robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ECE118_Final_Robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=/Users/gavinwang/Desktop/mech/ECE118/src/AD.c /Users/gavinwang/Desktop/mech/ECE118/src/BOARD.c /Users/gavinwang/Desktop/mech/ECE118/src/IO_Ports.c /Users/gavinwang/Desktop/mech/ECE118/src/LED.c /Users/gavinwang/Desktop/mech/ECE118/src/pwm.c /Users/gavinwang/Desktop/mech/ECE118/src/serial.c /Users/gavinwang/Desktop/mech/ECE118/src/timers.c /Users/gavinwang/Desktop/mech/ECE118/src/ES_CheckEvents.c /Users/gavinwang/Desktop/mech/ECE118/src/ES_Framework.c /Users/gavinwang/Desktop/mech/ECE118/src/ES_KeyboardInput.c /Users/gavinwang/Desktop/mech/ECE118/src/ES_PostList.c /Users/gavinwang/Desktop/mech/ECE118/src/ES_Queue.c /Users/gavinwang/Desktop/mech/ECE118/src/ES_TattleTale.c /Users/gavinwang/Desktop/mech/ECE118/src/ES_Timers.c "/Users/gavinwang/Desktop/ECE118 Robot/final_project_ece118/Robot_Project.X/RobotEventChecker.c" /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ES_Main.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/TopHSM.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/SetupSubHSM.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/TapeFollowingSubHSM.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ObstacleAvoidance.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ShootingSubHSM.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/motors.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Bumper_Sensor.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Beacon_Detector.c "/Users/gavinwang/Desktop/ECE118 Robot/final_project_ece118/Robot_Project.X/Tape_Sensor.c" "/Users/gavinwang/Desktop/ECE118 Robot/final_project_ece118/Robot_Project.X/Trackwire_Sensor.c" /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Beacon_Service.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1009044124/AD.o ${OBJECTDIR}/_ext/1009044124/BOARD.o ${OBJECTDIR}/_ext/1009044124/IO_Ports.o ${OBJECTDIR}/_ext/1009044124/LED.o ${OBJECTDIR}/_ext/1009044124/pwm.o ${OBJECTDIR}/_ext/1009044124/serial.o ${OBJECTDIR}/_ext/1009044124/timers.o ${OBJECTDIR}/_ext/1009044124/ES_CheckEvents.o ${OBJECTDIR}/_ext/1009044124/ES_Framework.o ${OBJECTDIR}/_ext/1009044124/ES_KeyboardInput.o ${OBJECTDIR}/_ext/1009044124/ES_PostList.o ${OBJECTDIR}/_ext/1009044124/ES_Queue.o ${OBJECTDIR}/_ext/1009044124/ES_TattleTale.o ${OBJECTDIR}/_ext/1009044124/ES_Timers.o ${OBJECTDIR}/_ext/840847969/RobotEventChecker.o ${OBJECTDIR}/_ext/168271290/ES_Main.o ${OBJECTDIR}/_ext/168271290/TopHSM.o ${OBJECTDIR}/_ext/168271290/SetupSubHSM.o ${OBJECTDIR}/_ext/168271290/TapeFollowingSubHSM.o ${OBJECTDIR}/_ext/168271290/ObstacleAvoidance.o ${OBJECTDIR}/_ext/168271290/ShootingSubHSM.o ${OBJECTDIR}/_ext/168271290/motors.o ${OBJECTDIR}/_ext/168271290/Bumper_Sensor.o ${OBJECTDIR}/_ext/168271290/Beacon_Detector.o ${OBJECTDIR}/_ext/840847969/Tape_Sensor.o ${OBJECTDIR}/_ext/840847969/Trackwire_Sensor.o ${OBJECTDIR}/_ext/168271290/Beacon_Service.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1009044124/AD.o.d ${OBJECTDIR}/_ext/1009044124/BOARD.o.d ${OBJECTDIR}/_ext/1009044124/IO_Ports.o.d ${OBJECTDIR}/_ext/1009044124/LED.o.d ${OBJECTDIR}/_ext/1009044124/pwm.o.d ${OBJECTDIR}/_ext/1009044124/serial.o.d ${OBJECTDIR}/_ext/1009044124/timers.o.d ${OBJECTDIR}/_ext/1009044124/ES_CheckEvents.o.d ${OBJECTDIR}/_ext/1009044124/ES_Framework.o.d ${OBJECTDIR}/_ext/1009044124/ES_KeyboardInput.o.d ${OBJECTDIR}/_ext/1009044124/ES_PostList.o.d ${OBJECTDIR}/_ext/1009044124/ES_Queue.o.d ${OBJECTDIR}/_ext/1009044124/ES_TattleTale.o.d ${OBJECTDIR}/_ext/1009044124/ES_Timers.o.d ${OBJECTDIR}/_ext/840847969/RobotEventChecker.o.d ${OBJECTDIR}/_ext/168271290/ES_Main.o.d ${OBJECTDIR}/_ext/168271290/TopHSM.o.d ${OBJECTDIR}/_ext/168271290/SetupSubHSM.o.d ${OBJECTDIR}/_ext/168271290/TapeFollowingSubHSM.o.d ${OBJECTDIR}/_ext/168271290/ObstacleAvoidance.o.d ${OBJECTDIR}/_ext/168271290/ShootingSubHSM.o.d ${OBJECTDIR}/_ext/168271290/motors.o.d ${OBJECTDIR}/_ext/168271290/Bumper_Sensor.o.d ${OBJECTDIR}/_ext/168271290/Beacon_Detector.o.d ${OBJECTDIR}/_ext/840847969/Tape_Sensor.o.d ${OBJECTDIR}/_ext/840847969/Trackwire_Sensor.o.d ${OBJECTDIR}/_ext/168271290/Beacon_Service.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1009044124/AD.o ${OBJECTDIR}/_ext/1009044124/BOARD.o ${OBJECTDIR}/_ext/1009044124/IO_Ports.o ${OBJECTDIR}/_ext/1009044124/LED.o ${OBJECTDIR}/_ext/1009044124/pwm.o ${OBJECTDIR}/_ext/1009044124/serial.o ${OBJECTDIR}/_ext/1009044124/timers.o ${OBJECTDIR}/_ext/1009044124/ES_CheckEvents.o ${OBJECTDIR}/_ext/1009044124/ES_Framework.o ${OBJECTDIR}/_ext/1009044124/ES_KeyboardInput.o ${OBJECTDIR}/_ext/1009044124/ES_PostList.o ${OBJECTDIR}/_ext/1009044124/ES_Queue.o ${OBJECTDIR}/_ext/1009044124/ES_TattleTale.o ${OBJECTDIR}/_ext/1009044124/ES_Timers.o ${OBJECTDIR}/_ext/840847969/RobotEventChecker.o ${OBJECTDIR}/_ext/168271290/ES_Main.o ${OBJECTDIR}/_ext/168271290/TopHSM.o ${OBJECTDIR}/_ext/168271290/SetupSubHSM.o ${OBJECTDIR}/_ext/168271290/TapeFollowingSubHSM.o ${OBJECTDIR}/_ext/168271290/ObstacleAvoidance.o ${OBJECTDIR}/_ext/168271290/ShootingSubHSM.o ${OBJECTDIR}/_ext/168271290/motors.o ${OBJECTDIR}/_ext/168271290/Bumper_Sensor.o ${OBJECTDIR}/_ext/168271290/Beacon_Detector.o ${OBJECTDIR}/_ext/840847969/Tape_Sensor.o ${OBJECTDIR}/_ext/840847969/Trackwire_Sensor.o ${OBJECTDIR}/_ext/168271290/Beacon_Service.o

# Source Files
SOURCEFILES=/Users/gavinwang/Desktop/mech/ECE118/src/AD.c /Users/gavinwang/Desktop/mech/ECE118/src/BOARD.c /Users/gavinwang/Desktop/mech/ECE118/src/IO_Ports.c /Users/gavinwang/Desktop/mech/ECE118/src/LED.c /Users/gavinwang/Desktop/mech/ECE118/src/pwm.c /Users/gavinwang/Desktop/mech/ECE118/src/serial.c /Users/gavinwang/Desktop/mech/ECE118/src/timers.c /Users/gavinwang/Desktop/mech/ECE118/src/ES_CheckEvents.c /Users/gavinwang/Desktop/mech/ECE118/src/ES_Framework.c /Users/gavinwang/Desktop/mech/ECE118/src/ES_KeyboardInput.c /Users/gavinwang/Desktop/mech/ECE118/src/ES_PostList.c /Users/gavinwang/Desktop/mech/ECE118/src/ES_Queue.c /Users/gavinwang/Desktop/mech/ECE118/src/ES_TattleTale.c /Users/gavinwang/Desktop/mech/ECE118/src/ES_Timers.c /Users/gavinwang/Desktop/ECE118 Robot/final_project_ece118/Robot_Project.X/RobotEventChecker.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ES_Main.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/TopHSM.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/SetupSubHSM.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/TapeFollowingSubHSM.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ObstacleAvoidance.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ShootingSubHSM.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/motors.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Bumper_Sensor.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Beacon_Detector.c /Users/gavinwang/Desktop/ECE118 Robot/final_project_ece118/Robot_Project.X/Tape_Sensor.c /Users/gavinwang/Desktop/ECE118 Robot/final_project_ece118/Robot_Project.X/Trackwire_Sensor.c /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Beacon_Service.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

# The following macros may be used in the pre and post step lines
_/_=/
ShExtension=.sh
Device=PIC32MX320F128H
ProjectDir=/Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X
ProjectName=ECE118_Final_Robot
ConfName=default
ImagePath=dist/default/${IMAGE_TYPE}/ECE118_Final_Robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
ImageDir=dist/default/${IMAGE_TYPE}
ImageName=ECE118_Final_Robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif
MDFUHostPath=/Applications/microchip/mplabx/v6.30/MPLAB\ X\ IDE\ v6.30.app/Contents/Resources/mplab_ide/mplab-pymdfu/bin/mac/pymdfu-bin
PYFWImageBuilderPath=/Applications/microchip/mplabx/v6.30/MPLAB\ X\ IDE\ v6.30.app/Contents/Resources/mplab_ide/mplab-pymdfu/bin/mac/pyfwimagebuilder-bin

.build-conf:  .pre ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/ECE118_Final_Robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX320F128H
MP_LINKER_FILE_OPTION=,--script="/Users/gavinwang/Desktop/mech/ECE118/bootloader320.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1009044124/AD.o: /Users/gavinwang/Desktop/mech/ECE118/src/AD.c  .generated_files/flags/default/3973506df19f50459cdf261d52fdea3fbcecdf38 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/AD.o.d" -o ${OBJECTDIR}/_ext/1009044124/AD.o /Users/gavinwang/Desktop/mech/ECE118/src/AD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/BOARD.o: /Users/gavinwang/Desktop/mech/ECE118/src/BOARD.c  .generated_files/flags/default/8fd1231a45ef83e14d04aa96452ad59bba7d67ca .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/BOARD.o.d" -o ${OBJECTDIR}/_ext/1009044124/BOARD.o /Users/gavinwang/Desktop/mech/ECE118/src/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/IO_Ports.o: /Users/gavinwang/Desktop/mech/ECE118/src/IO_Ports.c  .generated_files/flags/default/5c2921ecd8daa4c732404b86c3ab6a5044a05d44 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/1009044124/IO_Ports.o /Users/gavinwang/Desktop/mech/ECE118/src/IO_Ports.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/LED.o: /Users/gavinwang/Desktop/mech/ECE118/src/LED.c  .generated_files/flags/default/be850ba83c73704d27a8551016dc62b9cdfea63c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/LED.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/LED.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/LED.o.d" -o ${OBJECTDIR}/_ext/1009044124/LED.o /Users/gavinwang/Desktop/mech/ECE118/src/LED.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/pwm.o: /Users/gavinwang/Desktop/mech/ECE118/src/pwm.c  .generated_files/flags/default/4a27f62eb65963994a67de939e1307d7d7fdedf7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/pwm.o.d" -o ${OBJECTDIR}/_ext/1009044124/pwm.o /Users/gavinwang/Desktop/mech/ECE118/src/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/serial.o: /Users/gavinwang/Desktop/mech/ECE118/src/serial.c  .generated_files/flags/default/a0064d7d2ba0ae3ce39a4a01e33a61370106d49f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/serial.o.d" -o ${OBJECTDIR}/_ext/1009044124/serial.o /Users/gavinwang/Desktop/mech/ECE118/src/serial.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/timers.o: /Users/gavinwang/Desktop/mech/ECE118/src/timers.c  .generated_files/flags/default/3357db5ba58694e04ec90fbe124b323cd2363926 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/timers.o.d" -o ${OBJECTDIR}/_ext/1009044124/timers.o /Users/gavinwang/Desktop/mech/ECE118/src/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/ES_CheckEvents.o: /Users/gavinwang/Desktop/mech/ECE118/src/ES_CheckEvents.c  .generated_files/flags/default/dc1256f5c149b1c6f1cfa0ae9e2dd399e3344000 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_CheckEvents.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/ES_CheckEvents.o.d" -o ${OBJECTDIR}/_ext/1009044124/ES_CheckEvents.o /Users/gavinwang/Desktop/mech/ECE118/src/ES_CheckEvents.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/ES_Framework.o: /Users/gavinwang/Desktop/mech/ECE118/src/ES_Framework.c  .generated_files/flags/default/64ed0849a7245fd160c11743d73980a78fe59698 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_Framework.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/ES_Framework.o.d" -o ${OBJECTDIR}/_ext/1009044124/ES_Framework.o /Users/gavinwang/Desktop/mech/ECE118/src/ES_Framework.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/ES_KeyboardInput.o: /Users/gavinwang/Desktop/mech/ECE118/src/ES_KeyboardInput.c  .generated_files/flags/default/ff3f17d71acca56d7ed55914ab11ba8aa5eb87f2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_KeyboardInput.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/_ext/1009044124/ES_KeyboardInput.o /Users/gavinwang/Desktop/mech/ECE118/src/ES_KeyboardInput.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/ES_PostList.o: /Users/gavinwang/Desktop/mech/ECE118/src/ES_PostList.c  .generated_files/flags/default/9acaa7a1e6d0ff91ca809962fd331390401a87f8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_PostList.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/ES_PostList.o.d" -o ${OBJECTDIR}/_ext/1009044124/ES_PostList.o /Users/gavinwang/Desktop/mech/ECE118/src/ES_PostList.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/ES_Queue.o: /Users/gavinwang/Desktop/mech/ECE118/src/ES_Queue.c  .generated_files/flags/default/caa978de9a67329c32049aa94265abaeaa2784f3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_Queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/ES_Queue.o.d" -o ${OBJECTDIR}/_ext/1009044124/ES_Queue.o /Users/gavinwang/Desktop/mech/ECE118/src/ES_Queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/ES_TattleTale.o: /Users/gavinwang/Desktop/mech/ECE118/src/ES_TattleTale.c  .generated_files/flags/default/44135188dba218a68e2b4b9f7aa59196c8143ab0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_TattleTale.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/ES_TattleTale.o.d" -o ${OBJECTDIR}/_ext/1009044124/ES_TattleTale.o /Users/gavinwang/Desktop/mech/ECE118/src/ES_TattleTale.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/ES_Timers.o: /Users/gavinwang/Desktop/mech/ECE118/src/ES_Timers.c  .generated_files/flags/default/2b548647013466dd745e302d4ad4aa1a323e5645 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/ES_Timers.o.d" -o ${OBJECTDIR}/_ext/1009044124/ES_Timers.o /Users/gavinwang/Desktop/mech/ECE118/src/ES_Timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/840847969/RobotEventChecker.o: /Users/gavinwang/Desktop/ECE118\ Robot/final_project_ece118/Robot_Project.X/RobotEventChecker.c  .generated_files/flags/default/fb1779c788850d0a5d73ec2426987d01195a309 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/840847969" 
	@${RM} ${OBJECTDIR}/_ext/840847969/RobotEventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/840847969/RobotEventChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/840847969/RobotEventChecker.o.d" -o ${OBJECTDIR}/_ext/840847969/RobotEventChecker.o "/Users/gavinwang/Desktop/ECE118 Robot/final_project_ece118/Robot_Project.X/RobotEventChecker.c"    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/ES_Main.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ES_Main.c  .generated_files/flags/default/40d77603dd3d623fcdd620de9d900c76628b844b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/ES_Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/ES_Main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/ES_Main.o.d" -o ${OBJECTDIR}/_ext/168271290/ES_Main.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ES_Main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/TopHSM.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/TopHSM.c  .generated_files/flags/default/b6b4fa82440d785d86703bb3c42c36a67e3be3d9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/TopHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/TopHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/TopHSM.o.d" -o ${OBJECTDIR}/_ext/168271290/TopHSM.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/TopHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/SetupSubHSM.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/SetupSubHSM.c  .generated_files/flags/default/92b6adbf8c581dff222db2d9220eedcb01747c03 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/SetupSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/SetupSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/SetupSubHSM.o.d" -o ${OBJECTDIR}/_ext/168271290/SetupSubHSM.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/SetupSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/TapeFollowingSubHSM.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/TapeFollowingSubHSM.c  .generated_files/flags/default/8cb649459b08dd0bb71cee5236b7494d83141df4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/TapeFollowingSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/TapeFollowingSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/TapeFollowingSubHSM.o.d" -o ${OBJECTDIR}/_ext/168271290/TapeFollowingSubHSM.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/TapeFollowingSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/ObstacleAvoidance.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ObstacleAvoidance.c  .generated_files/flags/default/d3836c74fbee5a88be102d10f953ac57aceb334b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/ObstacleAvoidance.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/ObstacleAvoidance.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/ObstacleAvoidance.o.d" -o ${OBJECTDIR}/_ext/168271290/ObstacleAvoidance.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ObstacleAvoidance.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/ShootingSubHSM.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ShootingSubHSM.c  .generated_files/flags/default/8cbe9a8f5cca4ff557d489ad298d51af4ee27898 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/ShootingSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/ShootingSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/ShootingSubHSM.o.d" -o ${OBJECTDIR}/_ext/168271290/ShootingSubHSM.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ShootingSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/motors.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/motors.c  .generated_files/flags/default/79452971390d04ea154dcca08f6575680e74ed32 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/motors.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/motors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/motors.o.d" -o ${OBJECTDIR}/_ext/168271290/motors.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/motors.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/Bumper_Sensor.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Bumper_Sensor.c  .generated_files/flags/default/d133a06602df1b1206a7bacdb70d37144fe07278 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/Bumper_Sensor.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/Bumper_Sensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/Bumper_Sensor.o.d" -o ${OBJECTDIR}/_ext/168271290/Bumper_Sensor.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Bumper_Sensor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/Beacon_Detector.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Beacon_Detector.c  .generated_files/flags/default/55a6483ea95e588a7de1a52bcba04c3c64d515d0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/Beacon_Detector.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/Beacon_Detector.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/Beacon_Detector.o.d" -o ${OBJECTDIR}/_ext/168271290/Beacon_Detector.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Beacon_Detector.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/840847969/Tape_Sensor.o: /Users/gavinwang/Desktop/ECE118\ Robot/final_project_ece118/Robot_Project.X/Tape_Sensor.c  .generated_files/flags/default/8ff2608366ae7788e7723d902bd5a04ed2795168 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/840847969" 
	@${RM} ${OBJECTDIR}/_ext/840847969/Tape_Sensor.o.d 
	@${RM} ${OBJECTDIR}/_ext/840847969/Tape_Sensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/840847969/Tape_Sensor.o.d" -o ${OBJECTDIR}/_ext/840847969/Tape_Sensor.o "/Users/gavinwang/Desktop/ECE118 Robot/final_project_ece118/Robot_Project.X/Tape_Sensor.c"    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/840847969/Trackwire_Sensor.o: /Users/gavinwang/Desktop/ECE118\ Robot/final_project_ece118/Robot_Project.X/Trackwire_Sensor.c  .generated_files/flags/default/cde1fd3f27a87e3e089044d2ef322a545bb57bd0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/840847969" 
	@${RM} ${OBJECTDIR}/_ext/840847969/Trackwire_Sensor.o.d 
	@${RM} ${OBJECTDIR}/_ext/840847969/Trackwire_Sensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/840847969/Trackwire_Sensor.o.d" -o ${OBJECTDIR}/_ext/840847969/Trackwire_Sensor.o "/Users/gavinwang/Desktop/ECE118 Robot/final_project_ece118/Robot_Project.X/Trackwire_Sensor.c"    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/Beacon_Service.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Beacon_Service.c  .generated_files/flags/default/c11887306a2900fca53fa8f2e2dc83c4e4626d1e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/Beacon_Service.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/Beacon_Service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/Beacon_Service.o.d" -o ${OBJECTDIR}/_ext/168271290/Beacon_Service.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Beacon_Service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/_ext/1009044124/AD.o: /Users/gavinwang/Desktop/mech/ECE118/src/AD.c  .generated_files/flags/default/1ae99cdd02dedd1c3a2f2397ac9b6b799cb47b80 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/AD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/AD.o.d" -o ${OBJECTDIR}/_ext/1009044124/AD.o /Users/gavinwang/Desktop/mech/ECE118/src/AD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/BOARD.o: /Users/gavinwang/Desktop/mech/ECE118/src/BOARD.c  .generated_files/flags/default/2eb4b3b5a62e96c017995976e2f21a4b967279f6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/BOARD.o.d" -o ${OBJECTDIR}/_ext/1009044124/BOARD.o /Users/gavinwang/Desktop/mech/ECE118/src/BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/IO_Ports.o: /Users/gavinwang/Desktop/mech/ECE118/src/IO_Ports.c  .generated_files/flags/default/8e3cb0cbd61014220c575618865bc09c0caddb51 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/IO_Ports.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/1009044124/IO_Ports.o /Users/gavinwang/Desktop/mech/ECE118/src/IO_Ports.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/LED.o: /Users/gavinwang/Desktop/mech/ECE118/src/LED.c  .generated_files/flags/default/62b3c97d25b09d83f8738b8cf3c7270e8a904162 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/LED.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/LED.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/LED.o.d" -o ${OBJECTDIR}/_ext/1009044124/LED.o /Users/gavinwang/Desktop/mech/ECE118/src/LED.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/pwm.o: /Users/gavinwang/Desktop/mech/ECE118/src/pwm.c  .generated_files/flags/default/8007c32e1112cc62225f1195122f0562c57297ad .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/pwm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/pwm.o.d" -o ${OBJECTDIR}/_ext/1009044124/pwm.o /Users/gavinwang/Desktop/mech/ECE118/src/pwm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/serial.o: /Users/gavinwang/Desktop/mech/ECE118/src/serial.c  .generated_files/flags/default/68ce65bc07cc361c1a03417ad1c56c890f20f366 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/serial.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/serial.o.d" -o ${OBJECTDIR}/_ext/1009044124/serial.o /Users/gavinwang/Desktop/mech/ECE118/src/serial.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/timers.o: /Users/gavinwang/Desktop/mech/ECE118/src/timers.c  .generated_files/flags/default/a0834c2c7df01048b1245dfe5d167c9bffd12bf8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/timers.o.d" -o ${OBJECTDIR}/_ext/1009044124/timers.o /Users/gavinwang/Desktop/mech/ECE118/src/timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/ES_CheckEvents.o: /Users/gavinwang/Desktop/mech/ECE118/src/ES_CheckEvents.c  .generated_files/flags/default/633aae990dcd9d937d8bc55ec75d4edd532e7150 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_CheckEvents.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/ES_CheckEvents.o.d" -o ${OBJECTDIR}/_ext/1009044124/ES_CheckEvents.o /Users/gavinwang/Desktop/mech/ECE118/src/ES_CheckEvents.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/ES_Framework.o: /Users/gavinwang/Desktop/mech/ECE118/src/ES_Framework.c  .generated_files/flags/default/3e6ace27e132059d76941e1d2eb0efc23774223b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_Framework.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/ES_Framework.o.d" -o ${OBJECTDIR}/_ext/1009044124/ES_Framework.o /Users/gavinwang/Desktop/mech/ECE118/src/ES_Framework.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/ES_KeyboardInput.o: /Users/gavinwang/Desktop/mech/ECE118/src/ES_KeyboardInput.c  .generated_files/flags/default/761234d0c72b69b7625d6665d324ef8c35b2f8ca .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_KeyboardInput.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/_ext/1009044124/ES_KeyboardInput.o /Users/gavinwang/Desktop/mech/ECE118/src/ES_KeyboardInput.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/ES_PostList.o: /Users/gavinwang/Desktop/mech/ECE118/src/ES_PostList.c  .generated_files/flags/default/1c4c4ce11bcddea68c8d06f46ba7af5fc667f797 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_PostList.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/ES_PostList.o.d" -o ${OBJECTDIR}/_ext/1009044124/ES_PostList.o /Users/gavinwang/Desktop/mech/ECE118/src/ES_PostList.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/ES_Queue.o: /Users/gavinwang/Desktop/mech/ECE118/src/ES_Queue.c  .generated_files/flags/default/7e25f284e992b6b88002d9f01aad9b0ae340da56 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_Queue.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/ES_Queue.o.d" -o ${OBJECTDIR}/_ext/1009044124/ES_Queue.o /Users/gavinwang/Desktop/mech/ECE118/src/ES_Queue.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/ES_TattleTale.o: /Users/gavinwang/Desktop/mech/ECE118/src/ES_TattleTale.c  .generated_files/flags/default/87bcc064ee8538922a29c537f4a458418bd4d1ad .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_TattleTale.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/ES_TattleTale.o.d" -o ${OBJECTDIR}/_ext/1009044124/ES_TattleTale.o /Users/gavinwang/Desktop/mech/ECE118/src/ES_TattleTale.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/1009044124/ES_Timers.o: /Users/gavinwang/Desktop/mech/ECE118/src/ES_Timers.c  .generated_files/flags/default/b2698b44ec49f0952426eefe930151d080f53f54 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1009044124" 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1009044124/ES_Timers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/1009044124/ES_Timers.o.d" -o ${OBJECTDIR}/_ext/1009044124/ES_Timers.o /Users/gavinwang/Desktop/mech/ECE118/src/ES_Timers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/840847969/RobotEventChecker.o: /Users/gavinwang/Desktop/ECE118\ Robot/final_project_ece118/Robot_Project.X/RobotEventChecker.c  .generated_files/flags/default/c310f1b4260d4c47e4a9a6dc69cde357964e5c3e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/840847969" 
	@${RM} ${OBJECTDIR}/_ext/840847969/RobotEventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/840847969/RobotEventChecker.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/840847969/RobotEventChecker.o.d" -o ${OBJECTDIR}/_ext/840847969/RobotEventChecker.o "/Users/gavinwang/Desktop/ECE118 Robot/final_project_ece118/Robot_Project.X/RobotEventChecker.c"    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/ES_Main.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ES_Main.c  .generated_files/flags/default/84cadefdebb2b2e9ddf938a5214b726e2b261630 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/ES_Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/ES_Main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/ES_Main.o.d" -o ${OBJECTDIR}/_ext/168271290/ES_Main.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ES_Main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/TopHSM.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/TopHSM.c  .generated_files/flags/default/a27bda4899271156a9fd99c1cd40832ef95b1920 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/TopHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/TopHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/TopHSM.o.d" -o ${OBJECTDIR}/_ext/168271290/TopHSM.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/TopHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/SetupSubHSM.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/SetupSubHSM.c  .generated_files/flags/default/cf05fc20abe3a90491b74aa9c01d09f8d25f8686 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/SetupSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/SetupSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/SetupSubHSM.o.d" -o ${OBJECTDIR}/_ext/168271290/SetupSubHSM.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/SetupSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/TapeFollowingSubHSM.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/TapeFollowingSubHSM.c  .generated_files/flags/default/167eaaa1a51a62e71a942e5b7689f93eaa0b669e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/TapeFollowingSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/TapeFollowingSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/TapeFollowingSubHSM.o.d" -o ${OBJECTDIR}/_ext/168271290/TapeFollowingSubHSM.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/TapeFollowingSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/ObstacleAvoidance.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ObstacleAvoidance.c  .generated_files/flags/default/416c4183d5a17e65df3d43bb97fa6578319f5260 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/ObstacleAvoidance.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/ObstacleAvoidance.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/ObstacleAvoidance.o.d" -o ${OBJECTDIR}/_ext/168271290/ObstacleAvoidance.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ObstacleAvoidance.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/ShootingSubHSM.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ShootingSubHSM.c  .generated_files/flags/default/5d950d23bd670488f0f25d19405004392b57d13f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/ShootingSubHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/ShootingSubHSM.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/ShootingSubHSM.o.d" -o ${OBJECTDIR}/_ext/168271290/ShootingSubHSM.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/ShootingSubHSM.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/motors.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/motors.c  .generated_files/flags/default/cecd0329a90f6a01e0a5ca82d84fc2a58d2cac5a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/motors.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/motors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/motors.o.d" -o ${OBJECTDIR}/_ext/168271290/motors.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/motors.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/Bumper_Sensor.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Bumper_Sensor.c  .generated_files/flags/default/396da94174a6df309349747c64909ccaf47dfaaf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/Bumper_Sensor.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/Bumper_Sensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/Bumper_Sensor.o.d" -o ${OBJECTDIR}/_ext/168271290/Bumper_Sensor.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Bumper_Sensor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/Beacon_Detector.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Beacon_Detector.c  .generated_files/flags/default/5a9c859987802321b2fc8f5a9b8ffa56303986cc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/Beacon_Detector.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/Beacon_Detector.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/Beacon_Detector.o.d" -o ${OBJECTDIR}/_ext/168271290/Beacon_Detector.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Beacon_Detector.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/840847969/Tape_Sensor.o: /Users/gavinwang/Desktop/ECE118\ Robot/final_project_ece118/Robot_Project.X/Tape_Sensor.c  .generated_files/flags/default/9950a0d4636584fa1d92ba45dece72f50ae4f01d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/840847969" 
	@${RM} ${OBJECTDIR}/_ext/840847969/Tape_Sensor.o.d 
	@${RM} ${OBJECTDIR}/_ext/840847969/Tape_Sensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/840847969/Tape_Sensor.o.d" -o ${OBJECTDIR}/_ext/840847969/Tape_Sensor.o "/Users/gavinwang/Desktop/ECE118 Robot/final_project_ece118/Robot_Project.X/Tape_Sensor.c"    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/840847969/Trackwire_Sensor.o: /Users/gavinwang/Desktop/ECE118\ Robot/final_project_ece118/Robot_Project.X/Trackwire_Sensor.c  .generated_files/flags/default/d9e9b4a412081ee68bebb3ed1ad93fd6cafbcc97 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/840847969" 
	@${RM} ${OBJECTDIR}/_ext/840847969/Trackwire_Sensor.o.d 
	@${RM} ${OBJECTDIR}/_ext/840847969/Trackwire_Sensor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/840847969/Trackwire_Sensor.o.d" -o ${OBJECTDIR}/_ext/840847969/Trackwire_Sensor.o "/Users/gavinwang/Desktop/ECE118 Robot/final_project_ece118/Robot_Project.X/Trackwire_Sensor.c"    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/_ext/168271290/Beacon_Service.o: /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Beacon_Service.c  .generated_files/flags/default/2a8f96a3edabe8758aca97138b533086a0740772 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/168271290" 
	@${RM} ${OBJECTDIR}/_ext/168271290/Beacon_Service.o.d 
	@${RM} ${OBJECTDIR}/_ext/168271290/Beacon_Service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -O0 -fno-common -MP -MMD -MF "${OBJECTDIR}/_ext/168271290/Beacon_Service.o.d" -o ${OBJECTDIR}/_ext/168271290/Beacon_Service.o /Users/gavinwang/Desktop/mech/MPLABXProjects/ECE118_Final_Robot.X/Beacon_Service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/ECE118_Final_Robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    /Users/gavinwang/Desktop/mech/ECE118/bootloader320.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/ECE118_Final_Robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/ECE118_Final_Robot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   /Users/gavinwang/Desktop/mech/ECE118/bootloader320.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/ECE118_Final_Robot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}/xc32-bin2hex ${DISTDIR}/ECE118_Final_Robot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif

.pre:
	@echo "--------------------------------------"
	@echo "User defined pre-build step: [python3 /Users/gavinwang/Desktop/mech/ECE118/scripts/Enum_To_String.py]"
	@python3 /Users/gavinwang/Desktop/mech/ECE118/scripts/Enum_To_String.py
	@echo "--------------------------------------"

# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif

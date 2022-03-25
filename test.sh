#!/bin/bash

###############################################
##################### VARS ####################
###############################################

TIMEOUT="timeout 2s"
TIMEOUT_RET="124"
OPT_LIST=$*
SCRIPT=$(basename "$0")

TESTS_DIR=tests/

LOGS_DIR=logs/
mkdir -p $LOGS_DIR
CUR_LOGS_DIR=$LOGS_DIR$(date +"%F_%T")
find $CUR_LOGS_DIR 2>/dev/null 1>/dev/null
if [ "$?" == "0" ]
then
	printf "Duplicated log directory, wait 1 sec\n"
	sleep 1
	CUR_LOGS_DIR=$LOGS_DIR$(date +"%F_%T")
fi
mkdir $CUR_LOGS_DIR
LOG_RESULT="result.log"
LOG_RESEARCH="research.log"
LOG_TEST="test.cpp"

RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
PURPLE="\033[0;35m"
CYAN="\033[0;36m"
WHITE="\033[0;37m"


###############################################
##################### OPT #####################
###############################################


function get_opt()
{
	if [ "$OPT_LIST" == "" ]
	then
		if [ "$*" == "" ]
		then
			return 1
		fi
		return 0
	fi
	for i in $OPT_LIST
	do
		for j in $*
		do
			if [ "$j" == "$i" ]
			then
				return 1
			fi
		done
	done
	return 0
}

get_opt "-h" "--help"
if [ "$?" == "1" ]
then
	echo "Options :"
	echo "	--help (-h)"
	echo "	--verbose (-v)"
	echo "	--stop (-s)"
	echo "	--logclean (-lc)"
	echo "	--clean (-c)"
	echo "	--fclean (-fc)"
	echo "	--test (-t)"
	echo "	--subtest (-st)"
	echo "test options :"
	echo "	vector"
	echo "	subtest options :"
	echo "		a"
	exit
fi

get_opt "-lc" "--logclean"
if [ "$?" == "1" ]
then
	rm -rf $LOGS_DIR
	exit
fi

get_opt "-c" "--clean"
CLEAN="$?"

get_opt "-fc" "--fclean"
FCLEAN="$?"

get_opt	"-v" "--verbose"
VERBOSE="$?"

get_opt "-s" "--stop"
STOP="$?"

get_opt "-t" "--test"
FTEST="$?"

get_opt "-st" "--subtest"
SUBTEST="$?"

###############################################
################ FUNCTION TEST ################
###############################################

function	test()
{
	if [ "$1" == "" ]
	then
		printf "$SCRIPT: line $BASH_LINENO: Function require the name of the test\n"
		exit
	fi
	if [ "$2" == "" ]
	then
		printf "$SCRIPT: line $BASH_LINENO: Function require the name of the main test\n"
		exit
	fi
	if [ "$3" == "" ]
	then
		printf "$SCRIPT: line $BASH_LINENO: Function require the path of the main test\n"
		exit
	fi
	TEST="$2"
	CUR_LOG_DIR=$CUR_LOGS_DIR/$1/

	if [ "$SUBTEST" == "1" ]
	then
		get_opt "$1"
		if [ "$?" == "0" ]
		then
			return 0
		fi
	fi

	STD_EXE=std
	FT_EXE=ft
	STDF="STD_FLAG=-DNAMESPACE=std SRCS=$TEST EXE=$STD_EXE"
	FTF="SRCS=$TEST EXE=$FT_EXE"


	if [ "$FCLEAN" == "1" ]
	then
		make fclean $STDF
		make fclean $FTF
	elif [ "$CLEAN" == "1" ]
	then
		make clean $STDF
		make clean $FTF
	else
		(make $STDF; make $FTF;) 1>/dev/null
		RESEARCH=$($TIMEOUT ./$STD_EXE)
		RESEARCH_RET="$?"
		RESULT=$($TIMEOUT ./$FT_EXE)
		RESULT_RET="$?"

		mkdir -p $CUR_LOG_DIR 
		echo "$RESULT" > $CUR_LOG_DIR/$LOG_RESULT
		echo "$RESEARCH" > $CUR_LOG_DIR/$LOG_RESEARCH
		cat "$3/$TEST" > $CUR_LOG_DIR/$LOG_TEST
		mv $STD_EXE $CUR_LOG_DIR
		mv $FT_EXE $CUR_LOG_DIR
		if [ "$RESEARCH" != "$RESULT" ] || [ "$RESULT_RET" == "$TIMEOUT_RET" ]
		then
			printf $BLUE"TEST\n"
			cat $3/$TEST
			printf $WHITE
			if [ "$RESEARCH_RET" == "$TIMEOUT_RET" ]
			then
				printf $GREEN"\nRESEARCH\n"
				printf "timeout\n"$WHITE
			else
				printf $GREEN"\nRESEARCH\n"
				printf "$RESEARCH\n"$WHITE
			fi
			if [ "$RESULT_RET" == "$TIMEOUT_RET" ]
			then
				printf $RED"\nRESULT\n"
				printf "timeout\n"$WHITE
			else
				printf $RED"\nRESULT\n"
				printf "$RESULT\n"$WHITE
			fi
			if [ "$STOP" == "1" ]
			then
				exit
			fi
		else
			printf $1$GREEN": Ok"$WHITE"\n"
			
			if [ "$VERBOSE" == "1" ]
			then
				printf $BLUE"TEST\n"
				cat $3/$TEST
				printf $WHITE
				printf $GREEN"\nRESULT\n"
				printf "$RESULT\n"$WHITE

			fi
		fi
	fi
}

function	is_called_test()
{
	if [ "$1" == "" ]
	then
		printf "$SCRIPT: line $BASH_LINENO: Function require the name of the test\n"
		exit
	fi
	
	if [ "$CLEAN" == "1" ] || [ "$FCLEAN" == "1" ]
	then
		return 1
	fi

	if [ "$FTEST" == "1" ]
	then
		get_opt "$1"
		if [ "$?" == "1" ]
		then
			printf "***** TEST $1 *****\n"
			return 1
		fi
		return 0
	else
		printf "TEST $1\n"
		return 1
	fi
}

###############################################
##################### TEST ####################
###############################################

is_called_test "vector"
if [ "$?" == "1" ]
then
	test "a" "my_main.cpp" "srcs"
fi

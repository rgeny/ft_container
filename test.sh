#!/bin/bash

###############################################
#################### TESTS ####################
###############################################

declare -a vector_test=(
	"size_sample sample.cpp srcs/vector/size"
	"iterator_sample sample.cpp srcs/vector/iterator"
	"constructor_int int.cpp srcs/vector/constructor"
	"constructor_string string.cpp srcs/vector/constructor" )

declare -a stack_test=(
	"" )

declare -A lib_test=(
	['vector']="${vector_test[@]}" 
	['stack']="${stack_test[@]}" )

declare -a test_name=(
	"vector"
	"stack" )

###############################################
##################### VARS ####################
###############################################

##### TESTS VARS #####
TESTS_DIR=tests/
N_PAR=3
LINE_DEL=14

##### SCRIPT VARS #####
TIMEOUT="timeout 1s"
TIMEOUT_RET="124"
DEL_PRINT="1>/dev/null 2>/dev/null"
OPT_LIST=$*
SCRIPT=$(basename "$0")

##### LOGS #####
LOGS_DIR=logs/
eval "find $LOGS_DIR$(date +"%F_%T") $DEL_PRINT"
while [ "$?" == "0" ]
do
	sleep 0.01
	eval "find $LOGS_DIR$(date +"%F_%T") $DEL_PRINT"
done
CUR_LOGS_DIR=$LOGS_DIR$(date +"%F_%T")
TEST_LOG_DIR="$CUR_LOGS_DIR/\$1/"
LOG_RESULT="result.log"
LOG_RESEARCH="research.log"
LOG_TEST="test.cpp"
ERR_RESULT="result.err"
ERR_RESEARCH="research.err"

##### MAKEFILE VARS #####
STD_EXE=std
FT_EXE=ft
TEST="\$2"
STDF="STD_FLAG=-DNAMESPACE=std SRCS=$TEST EXE=$STD_EXE"
FTF="SRCS=$TEST EXE=$FT_EXE"

##### COLOR VARS #####
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
PURPLE="\033[0;35m"
CYAN="\033[0;36m"
WHITE="\033[0;37m"
RESET="\033[0m"

##### ERROR VARS #####
declare PRINT_ERR="echo $SCRIPT: line \$i: Function require the"
declare RETURN_ERR="return 2"
declare -A FCT_ERR=(
	['1']="$PRINT_ERR name of the test; $RETURN_ERR"
	['2']="$PRINT_ERR name of the main test; $RETURN_ERR"
	['3']="$PRINT_ERR path of the main test; $RETURN_ERR" )
declare -A ERR=(
	['1']="return 0"
	['2']="exit" )


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
	for ((i = 0; i < ${#test_name[@]}; i++))
	do
		echo "	${test_name[$i]}"
		echo "	subtest options :"
		k=0
		for j in ${lib_test[${test_name[$i]}]}
		do
			k=$(expr $k + 1)
			if [ "$k" == "1" ]
			then
				echo " 		$j"
			elif [ "$k" == "$N_PAR" ]
			then
				k=0;
			fi
		done
	done
	exit
fi

declare -A opt_lst=(
	["verbose1"]="printf \$BLUE\"TEST\n\"
					eval cat \$3/\$TEST | sed 1,${LINE_DEL}d
					printf \$BLUE\"\nRESEARCH\n\"
					printf \"\$RESEARCH\n\"\$RESET
					printf \$GREEN\"\nRESULT\n\"
					printf \"\$RESULT\n\"\$RESET"
	["stop1"]="exit"
	["subtest1"]="get_opt \"\$1\"; if [ "\$?" == "0" ]; then return 0; fi" )

get_opt "-lc" "--logclean"
if [ "$?" == "1" ]
then
	rm -rf $LOGS_DIR
	exit
fi

get_opt "-fc" "--fclean"
if [ "$?" == "1" ]
then
	make fclean
	exit
fi

get_opt "-c" "--clean"
if [ "$?" == "1" ]
then
	make clean
	exit
fi

get_opt	"-v" "--verbose"
VERBOSE="verbose$?"

get_opt "-s" "--stop"
STOP="stop$?"

get_opt "-t" "--test"
FTEST="$?"

get_opt "-st" "--subtest"
SUBTEST="subtest$?"


###############################################
################ FUNCTION TEST ################
###############################################


function	save_log()
{
	eval "mkdir -p $TEST_LOG_DIR"
	eval "echo "$RESULT" > $TEST_LOG_DIR$LOG_RESULT"
	eval "echo "$RESEARCH" > $TEST_LOG_DIR$LOG_RESEARCH"
	eval "cat "$3/$TEST" > $TEST_LOG_DIR$LOG_TEST"
	eval "mv $STD_EXE $TEST_LOG_DIR"
	eval "mv $FT_EXE $TEST_LOG_DIR"
	eval "mv $ERR_RESEARCH $TEST_LOG_DIR"
	eval "mv $ERR_RESULT $TEST_LOG_DIR"
}

function	do_test()
{
	TIME=$(date +"%s%N")
	RESEARCH=$(2>>$ERR_RESEARCH $TIMEOUT valgrind ./$STD_EXE)
	RESEARCH_RET="$?"
	RESEARCH_TIME=$(expr $(date +"%s%N") - $TIME)
	RESEARCH_ERROR=$(cat $ERR_RESEARCH | grep "usage" | awk '{ printf (($5 - $7)) }')

	TIME=$(date +"%s%N")
	RESULT=$(2>>$ERR_RESULT $TIMEOUT valgrind ./$FT_EXE)
	RESULT_RET="$?"
	RESULT_TIME=$(expr $(date +"%s%N") - $TIME)
	RESULT_ERROR=$(cat $ERR_RESULT | grep "usage" | awk '{ printf (($5 - $7)) }')
}

function	check_result()
{
	if [ "$MAKE_RESEARCH_ERROR" != "0" ] ||
		[ "$MAKE_RESULT_ERROR" != "0" ]
	then
		printf "$1:$RED Ko (Compile error)\n$RESET"
		if [ "$VERBOSE" == "verbose1" ]
		then
			printf $BLUE"\nRESEARCH\n"
			eval cat $TEST_LOG_DIR$ERR_RESEARCH
			printf $RED"\nRESULT\n"
			eval cat $TEST_LOG_DIR$ERR_RESULT
			printf $RESET
		fi
		${opt_lst[$STOP]}
	elif [ "$RESEARCH" != "$RESULT" ] ||
		[ "$RESULT_RET" == "$TIMEOUT_RET" ]
	then
		printf $1":"$RED" Ko$RESET\n"
#		TEST
		printf $BLUE"TEST\n"
		eval "cat $3/$TEST | sed 1,${LINE_DEL}d"
		printf $RESET

#		RESEARCH
		printf $GREEN"\nRESEARCH\n"
		if [ "$RESEARCH_RET" == "$TIMEOUT_RET" ]
		then
			printf "timeout\n"$RESET
		else
			printf "$RESEARCH\n"$RESET
		fi

#		RESULT
		printf $RED"\nRESULT\n"
		if [ "$RESULT_RET" == "$TIMEOUT_RET" ]
		then
			printf "timeout\n"$RESET
		else
			printf "$RESULT\n"$RESET
		fi

		${opt_lst[$STOP]}
	elif [ "$RESULT_ERROR" != "$RESEARCH_ERROR" ]
	then
		printf "$1:$RED Ko (Memory leak)\n$RESET"
		if [ "$VERBOSE" == "verbose1" ]
		then
			printf $BLUE"\nRESEARCH\n"
			eval cat $TEST_LOG_DIR$ERR_RESEARCH
			printf $RED"\nRESULT\n"
			eval cat $TEST_LOG_DIR$ERR_RESULT
			printf $RESET
		fi
		${opt_lst[$STOP]}
	else
		printf $1": "$GREEN"Ok"$RESET"\n"
		eval "${opt_lst[$VERBOSE]}"
	fi
}

function	test()
{
#	CHECK PARAMETERS
	eval "${opt_lst[$SUBTEST]}"
	(eval make -j $STDF MAKE_DIR="$3") 1>/dev/null 2>$ERR_RESEARCH
	MAKE_RESEARCH_ERROR="$?"
	(eval make -j $FTF MAKE_DIR="$3") 1>/dev/null 2>$ERR_RESULT
	MAKE_RESULT_ERROR="$?"
	do_test
	save_log $*
	check_result $*
	make fclean 1>/dev/null
}

function	is_called_test()
{
	if [ "$1" == "" ]
	then
		printf "$SCRIPT: line $BASH_LINENO: Function require the name of the test\n"
		exit
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

function	main()
{
	mkdir -p $LOGS_DIR
	mkdir $CUR_LOGS_DIR
	for ((k = 0; k < ${#test_name[@]}; k++))
	do
		is_called_test ${test_name[$k]}
		if [ "$?" == "1" ]
		then
			m=0
			for l in ${lib_test[${test_name[$k]}]}
			do
				m=$(expr $m + 1)
				ARG+="$l "
				if [ "$m" == "$N_PAR" ]
				then
					test $ARG
					m=0
					ARG=""
				fi
			done
		fi
	done
}

main

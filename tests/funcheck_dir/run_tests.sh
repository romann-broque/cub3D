#!/bin/bash

bonus=0
if [ $# -eq 1 ]; then
    ARGUMENT="$1"
    if [ "${ARGUMENT}" = "bonus" ]; then
        echo "BONUS"
        bonus=1
    fi
else
    echo "No bonus"
fi

# CHECK PROTECTIONS

RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
NC="\033[0m"

BIN=./cub3d

TESTER_FOLDER=./tests/
FUNCHECK_FOLDER="${TESTER_FOLDER}"/funcheck_dir/funcheck/
FUNCHECK_BIN="${FUNCHECK_FOLDER}"/host/funcheck

LOG="log"

if [ $bonus -eq 0 ]; then
    GOOD_MAP_FOLDER=(
        assets/maps/mandatory/correct/
        ${TESTER_FOLDER}/assets/maps/correct/)
    WRONG_MAP_FOLDER=(
        assets/maps/mandatory/wrong/
        ${TESTER_FOLDER}/assets/maps/wrong/)
else
    GOOD_MAP_FOLDER=(
        assets/maps/bonus/correct/)
    WRONG_MAP_FOLDER=(
        assets/maps/bonus/wrong/)
fi

MAP_FOLDER=($GOOD_MAP_FOLDER $WRONG_MAP_FOLDER)

ret_val=0
exit_val=0

##################
#### GOOD_MAP ####
##################

echo -e "\n${BLUE}<------ GOOD MAPS ------>\n${NC}"

for folder in "${GOOD_MAP_FOLDER[@]}"; do
    for file in "$folder"/*; do
        # Check if the file exists and is a regular file
        if [ -f "$file" ]; then
            # Call your program with the file as an argument
			"${BIN}" "$file" &> "${LOG}"
            ret_val=$?
            if [ "${ret_val}" != "0" ]; then
                echo -e "\n${YELLOW}${file}\n${NC}"
                cat "${LOG}"
                exit_val=1
            else
                echo -e "\n${GREEN}${file}\n${NC}"
            fi
        fi
    done
done

###################
#### WRONG_MAP ####
###################

echo -e "\n${BLUE}<------ WRONG MAPS ------>\n${NC}"

for folder in "${WRONG_MAP_FOLDER[@]}"; do
    for file in "$folder"/*; do
        # Check if the file exists and is a regular file
        if [ -f "$file" ]; then
            # Call your program with the file as an argument
			"${BIN}" "$file" &> "${LOG}"
            ret_val=$?
            if [ "${ret_val}" != "1" ]; then
                cat "${LOG}"
                exit_val=1
            else
                echo -e "\n${GREEN}${file}\n${NC}"
            fi
        fi
    done
done

##################
#### FUNCHECK ####
##################

echo -e "\n${BLUE}<------ FUNCHECK ------>\n${NC}"

for folder in "${MAP_FOLDER[@]}"; do
    for file in "$folder"/*; do
        # Check if the file exists and is a regular file
        if [ -f "$file" ]; then
            # Check if the filename starts with "very_big_map"
            if [[ "$file" == *very_big_map* ]]; then
                continue  # Skip this file and move to the next one
            fi
            # Call the program with the file as an argument
			"${FUNCHECK_BIN}" "${BIN}" "$file" &> "${LOG}"
            ret_val=$?
            if [ "${ret_val}" != "0" ]; then
                cat "${LOG}"
                exit_val=1
            else
                echo -e "\n${GREEN}${file}\n${NC}"
            fi
        fi
    done
done

if [ "${exit_val}" == "0" ]; then
        echo -e "\n${GREEN}<------OK------>\n${NC}"
else
        echo -e "\n${RED}<------KO------>\n${NC}"
fi

rm "${LOG}"
exit ${exit_val}

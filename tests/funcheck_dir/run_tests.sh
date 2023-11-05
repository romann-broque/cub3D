#!/bin/bash

# CHECK PROTECTIONS

RED="\033[31m"
GREEN="\033[32m"
NC="\033[0m"

BIN=./cub3d

TESTER_FOLDER=./tests/
FUNCHECK_FOLDER="${TESTER_FOLDER}"/funcheck_dir/funcheck/
FUNCHECK_BIN="${FUNCHECK_FOLDER}"/host/funcheck

LOG="log"
MAP_FOLDER=(
    assets/maps/mandatory/correct/ assets/maps/mandatory/wrong/
    assets/maps/bonus/correct/ assets/maps/bonus/wrong/
    ${TESTER_FOLDER}/assets/maps/correct/ ${TESTER_FOLDER}/assets/maps/wrong/)

ret_val=0
exit_val=0

for folder in "${MAP_FOLDER[@]}"; do
    for file in "$folder"/*; do
        # Check if the file exists and is a regular file
        if [ -f "$file" ]; then
            # Call your program with the file as an argument
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

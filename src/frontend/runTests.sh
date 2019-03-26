#!/bin/bash          
# This shell script runs the frontend against the test files in the tests/ directory

# clean the build
make clean
./cleanTests.sh

# Build the project
make

# Start testing
fails=0
for file in ./tests/*
do 
    if [[ -d $file ]]; then
        #echo $file
        for testFolder in $file/*
        do
            if [[ -d $testFolder ]]; then 
                #echo $testFolder
                mkdir -p $testFolder/actualOutput
                for test in $testFolder/input/*
                do
                    echo "Running test" $(basename $testFolder)
                    # Run test file on frontend
                    ./frontend "files/userAccounts.txt" "files/availabletickets.txt" "files/dailyTransactionFile.txt" < $test > $testFolder"/actualOutput/"$(basename $testFolder)"-out.txt"
                    # Copy daily transaction file to output
                    cp "./files/dailyTransactionFile.txt" $testFolder"/actualOutput/"$(basename $testFolder)"-actualDTF.txt"

                    # Find differences in actual vs expected output
                    diff $testFolder"/actualOutput/"$(basename $testFolder)"-out.txt" $testFolder"/expectedOutput/"$(basename $testFolder)"-output.txt" 
                    diff $testFolder"/actualOutput/"$(basename $testFolder)"-actualDTF.txt" $testFolder"/expectedOutput/"$(basename $testFolder)"-expectedDTF.txt"

                    # Put differences in difference file
                    diff $testFolder"/actualOutput/"$(basename $testFolder)"-out.txt" $testFolder"/expectedOutput/"$(basename $testFolder)"-output.txt" > $testFolder"/actualOutput/"$(basename $testFolder)"-diff.txt"
                    diff $testFolder"/actualOutput/"$(basename $testFolder)"-actualDTF.txt" $testFolder"/expectedOutput/"$(basename $testFolder)"-expectedDTF.txt" > $testFolder"/actualOutput/"$(basename $testFolder)"-diffDTF.txt"

                    # Clean daily transaction file
                    rm "./files/dailyTransactionFile.txt"
                    touch "./files/dailyTransactionFile.txt"


                done
            fi
        done


    fi
done
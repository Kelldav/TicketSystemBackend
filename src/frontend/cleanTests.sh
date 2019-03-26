#!/bin/bash          

# This shell script cleans the tests files from the tests folder
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
                    echo "Cleaning test" $(basename $testFolder)
                    # remove actualOutput folder
                    rm -rf $testFolder"/actualOutput"
                done
            fi
        done


    fi
done
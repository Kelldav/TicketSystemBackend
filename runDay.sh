if [ $# == 1 ]; then 

		frontend="./src/frontEnd"
		backend="./src/backEnd"
		inputDir="./files/days/day0$1/input"
        outputDir="./files/days/day0$1/output"

		for inputFile in $inputDir/*;
		do
                echo $inputFile
                $frontend/frontend < $inputFile > $outputDir/"-output.txt"
		done

		cat "files/dailyTransactionFile.txt" > "files/mergedDailyTransactions.txt"

		cd $backend
        make run 

		cd $cwd

else
		echo "Error: Correct run syntax './runDay.sh <Day #>'"
fi


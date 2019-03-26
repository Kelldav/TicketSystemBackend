## Instructions

To run the frontend, you must first compile the frontend from the sources. A makefile is provided for convenience.

### Building from sources

1. Open your terminal/command prompt.
2. Change directories into the root of the project folder.
3. Run `make`

### Running the frontend

##### Linux/MacOS

1. Open your terminal/command prompt.
2. Change directories into the root of the project folder.
3. Run `./frontend`

### Cleaning the build folder

1. Open your terminal/command prompt.
2. Change directories into the root of the project folder.
3. Run `make clean`

### Running the test scripts

#### Linux/MacOS

1. Open your terminal/command prompt.
2. Change directories into the root of the project folder.
3. Run `chmod +x runTests.sh`
4. Run `./runTests.sh`

### Cleaning the test scripts folder

1. Open your terminal/command prompt.
2. Change directories into the root of the project folder.
3. Run `chmod +x cleanTests.sh`
4. Run `./cleanTests.sh`

### Folder structure

The test files in the `tests/` folder are located in subfolders by transaction type, then test name, and follow the structure listed below.

| Type | Folder |
| ------ | ------ |
| Inputs | .../inputs/ |
| Expected Output | .../expectedOutput|
| Actual Output | .../actualOutput |

The expected output folder contains:

| File | Description |
| ------ | ------ |
| <testname>-output.txt | The expected terminal output |
| <testname>-expectedDTF.txt | The expected daily transaction file output|

After running the testing script `runTests.sh` the actualOutput folder will contain:

| File | Description |
| ------ | ------ |
| <testname>-out.txt | The actual terminal output |
| <testname>-diff.txt | The difference between the actual and expected terminal output |
| <testname>-actualDTF.txt | The expected daily transaction file |
| <testname>-diffDTF.txt | The difference between the actual and expected daily transaction file output |

# Freezing Temperature of Seawater

## Overview
This project involves the development of a C++ program designed to calculate the freezing temperature of seawater based on its salinity. The program offers two key functionalities:
1. Calculation of the linear interpolation function between salinity and freezing temperature.
2. Calculation of the freezing temperature based on user input salinity using the developed model.

## Quick Start

```bash
g++ -std=c++17 main.cpp -o seawater_calc
./seawater_calc
```

The repository includes `seawater_data.txt`, a small sample dataset used in the README test cases. Example interaction:

```text
1
seawater_data.txt
2
seawater_data.txt
25
3
```

## Table of Contents
- [Overview](#overview)
- [Technical Details](#technical-details)
  - [Mathematical Model](#mathematical-model)
  - [Algorithm](#algorithm)
- [Test Cases](#test-cases)
- [Usage Instructions](#usage-instructions)

## Technical Details

### Mathematical Model
The relationship between salinity and freezing temperature is modeled by the linear equation:
\[ T = m \cdot S + b \]
where:
- \( T \) is the freezing point in Fahrenheit.
- \( S \) is the salinity.
- \( m \) and \( b \) are model parameters calculated using the data points.

Model parameters \( m \) and \( b \) are calculated using the following formulas:
\[ m = \frac{\sum (x \cdot y) - n \cdot \overline{x} \cdot \overline{y}}{\sum (x^2) - n \cdot (\overline{x})^2} \]
\[ b = \overline{y} - m \cdot \overline{x} \]
where:
- \( x \) and \( y \) are the data points for salinity and freezing temperature respectively.
- \( \overline{x} \) and \( \overline{y} \) are the means of \( x \) and \( y \).
- \( n \) is the number of data points.

### Algorithm
1. Initialize variables for summations and counts.
2. Display the menu and prompt the user for a choice.
3. For option 1 (Calculate Linear Interpolation Function):
   - Prompt for the data file name.
   - Open and read data points from the file.
   - Calculate summations required for the model parameters.
   - Compute the model parameters \( m \) and \( b \).
   - Display the linear interpolation function.
4. For option 2 (Find Freezing Point):
   - Prompt for the data file name.
   - Open and read data points from the file.
   - Calculate summations required for the model parameters.
   - Compute the model parameters \( m \) and \( b \).
   - Prompt for salinity input.
   - Calculate and display the corresponding freezing point.
5. For option 3 (Exit):
   - Exit the program.
6. Repeat until the user chooses to exit.

## Test Cases
The program has been tested with various scenarios to ensure robustness and accuracy. The test cases include:
1. **Calculation of the linear interpolation function with 6 data points**:
   - Salinity (x): 0, 5, 10, 15, 20, 25
   - Freezing point (℉) (y): 32.0, 31.6, 30.7, 30.1, 29.5, 28.9
   - Calculated function: \( T = -0.128 \cdot S + 32.06 \)

2. **Different cases of salinity inputs and their corresponding freezing points**:
   - Inputs: 10, 25, 50, 75, 90
   - Outputs: 30.78, 28.86, 25.66, 22.46, 20.54

3. **Invalid menu choice and invalid salinity input**:
   - Invalid menu choice: Input 4, Output: "Invalid choice! Please try again"
   - Invalid salinity input: Input -20, Output: "Enter a valid input"

4. **Error handling for incorrect filename**:
   - Input: incorrect filename
   - Output: "Error opening file"

5. **Exit program option**:
   - Input: 3
   - Output: Program exits successfully

## Usage Instructions
1. **Calculate Linear Interpolation Function**:
   - Enter the file name containing the data points.
   - The program reads the file, calculates the model parameters, and outputs the linear interpolation function.

2. **Find Freezing Point**:
   - Enter the file name containing the data points.
   - Enter the salinity value.
   - The program reads the file, calculates the model parameters, and outputs the corresponding freezing point.

3. **Exit**:
   - Select the exit option to terminate the program.

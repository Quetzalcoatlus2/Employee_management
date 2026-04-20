# Employee Management (Workplace Absenteeism Analysis)

## Overview
This project is a C application that analyzes a workplace absenteeism dataset with **740 records** and **17 fields**.
It reads employee data from an input file, supports interactive sorting, computes summary statistics, and writes conclusions to an output file.

## Features
- Loads and displays all employee records from the input dataset.
- Supports repeated ascending sorts by:
  - Monthly transportation cost
  - Years of service
  - Hours absent in the previous year
- Calculates and reports:
  - Absent employees per month
  - Employees with zero absence
  - Absence start counts by weekday
  - Derived metrics (averages, percentages, min/max, harmonic means)
- Generates a simple OpenGL bar chart for absenteeism by month.

## Input and Output Files
- **Input:** `input.txt`
- **Output:** `output.txt`

## Build
This project depends on OpenGL/GLUT and a C compiler.

Example build command:

```bash
gcc 1.c -o employee_management -lglut -lGL -lGLU
```

## Run
```bash
./employee_management
```

The program is interactive and prompts for sorting and analysis steps in the terminal.

## Data Source
The dataset used in this project is based on:
https://data.world/aaizemberg/absenteeismatwork/workspace/file?filename=Absenteeism_at_work.tsv
(17 selected columns out of 21)

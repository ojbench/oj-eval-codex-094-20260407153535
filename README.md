# Problem 094 - 马赛克侦探

**ACMOJ Problem ID**: 2379

## Table of Contents

- [Problem 094 - 马赛克侦探](#problem-094-马赛克侦探)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **2379. 马赛克侦探** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/094/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

小X和小F是班上的同桌，返回回家后小X发现忘记带课本便线上询问了小F，小F为了开玩笑，发来了打了轻微马赛克的照片，不幸的是因为小X没有及时回复，学霸小F等不及去写自己的概率论作业了。无奈的小X只能选择从这张马赛克照片里获取信息......

已知小F的图片处理会将原本的图片先划分为多个3×3部分，每个3×3部分会被平均值代替，压缩成为一个像素点。

小X准备通过简单的方法修复图片，先将压缩后的每一个像素点都化为3×3，在中心位置给予压缩像素点的灰度，其余部分各点灰度与相邻的中心点有关。
对于每个非中心点，将曼哈顿距离为1的中心点记为A类，为2者记为B类

1.不存在A类：灰度=B类灰度平均值

2.不存在B类：灰度=A类灰度平均值

3.同时存在A类B类：灰度=A类灰度均值×0.8+B类灰度均值×0.2

**结果向下取整，灰度区间0-100**

### Input Format

m+1行

第一行两个整数m,n表示处理后图片大小

后m行每行n个数字表示处理后图片像素灰度

### Output Format

共3m行，每行3n个数字

表示小X修复后的图片灰度情况

### Samples

#### 样例 1

**Input:**
```
4 5
79 26 3 61 30 
78 43 86 36 67 
73 16 83 72 85 
20 8 21 45 12
```

**Output:**
```
79 79 79 26 26 26 3 3 3 61 61 61 30 30 30 
79 79 68 36 26 21 7 3 14 49 61 54 36 30 30 
79 78 79 26 29 26 3 19 3 61 56 61 30 37 30 
78 78 78 43 39 43 86 69 86 36 41 36 67 59 67 
78 78 71 50 43 51 77 86 76 46 36 42 60 67 67 
78 77 78 43 37 43 86 85 86 36 43 36 67 70 67 
73 74 73 16 21 16 83 83 83 72 64 72 85 81 85 
73 73 61 27 16 29 69 83 80 74 72 74 82 85 85 
73 62 73 16 14 16 83 70 83 72 66 72 85 70 85 
20 30 20 8 9 8 21 33 21 45 50 45 12 26 12 
20 20 17 10 8 10 18 21 25 40 45 38 18 12 12 
20 20 20 8 8 8 21 21 21 45 45 45 12 12 12 
```

### Data Constraints

保证输入灰度合法，n,m均属于[1,40]

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 1000 ms
- **Memory Limit (per test case)**: 256 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/094/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.

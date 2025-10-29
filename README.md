# Small Language Model (slm)

## 1. Introduction

This program implements a simple **small language model (SLM)** in C++.
It learns from an input text file by analyzing character sequences of length *k* (called k-grams).
Based on the training data, it can generate new text by predicting the next character using probability.

This project is made for **Lab 5: Your Own Small Language Model**.

---

## 2. Files and Structure

```
slm/
├── Makefile
├── README.md
├── test.txt
├── src/
│   ├── main.cpp
│   ├── LanguageModel.h
│   ├── LanguageModel.cpp
│   ├── RandomGenerator.h
│   └── RandomGenerator.cpp
└── doc/
    └── lab_report.md
```

* `src/` : all source code
* `Makefile` : used for building the project
* `test.txt` : example input text file
* `doc/` : contains the written lab report

---

## 3. How to Compile

Make sure you have a C++ compiler (g++).
Then, in the project directory, run:

```bash
make
```

This will create an executable file named **slm**.
If you want to remove object files and the executable, run:

```bash
make clean
```

---

## 4. How to Run

Use the program with the following command:

```bash
./slm <k> <input-file> <output-length>
```

Example:

```bash
./slm 2 test.txt 20
```

Here:

* `k = 2` → use 2-character sequences (bigrams)
* `input-file = test.txt` → file used for training
* `output-length = 20` → generate 20 characters of text

---

## 5. Example

**Input (`test.txt`):**

```
ababac
```

**Possible Output:**

```
ababaacaba
```

Output may differ each run because it uses random selection.

---

## 6. Program Design

The program is divided into two main classes:

1. **LanguageModel**

   * Reads the training text.
   * Builds frequency tables for each k-gram.
   * Computes transition probabilities for the next character.
   * Generates text using random sampling.

2. **RandomGenerator**

   * Uses C++’s random library to select characters according to probabilities.

`main.cpp` handles program arguments and prints the generated text.

---

## 7. Author

Name: *Xiangyi Liu*
Date: *20251029*

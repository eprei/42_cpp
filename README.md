# 📚 C++ Modules (42 School)

This repository contains my solutions for the C++ modules (00-09) from 42 School's curriculum. The project is designed to teach Object-Oriented Programming principles using C++98.

## 🎯 Overview

The C++ modules are a series of exercises aimed at understanding fundamental concepts of C++ and Object-Oriented Programming. Each module focuses on specific aspects of the language, progressively building knowledge from basic syntax to complex OOP concepts.

## 📝 Module Contents

- **Module 00**: Basic C++ syntax, classes, member functions, stdio streams, and initialization lists
- **Module 01**: Memory allocation, pointers to members, references, switch statements
- **Module 02**: Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form
- **Module 03**: Inheritance
- **Module 04**: Subtype polymorphism, abstract classes, interfaces
- **Module 05**: Repetition and Exceptions
- **Module 06**: C++ casts
- **Module 07**: C++ templates
- **Module 08**: Templated containers, iterators, algorithms
- **Module 09**: STL containers

## 🛠️ Technical Requirements

- All code is compiled with `c++` and flags `-Wall -Wextra -Werror`
- Code must comply with C++98 standard
- No memory leaks allowed
- All classes must be in Orthodox Canonical Form (from Module 02 onwards)
- No use of STL until Module 08 (no Containers or Algorithms)

## 🎓 Learning Objectives

Through these modules, we learn:

1. **Object-Oriented Programming Fundamentals**
   - Classes and objects
   - Encapsulation
   - Inheritance
   - Polymorphism
   - Abstract classes and interfaces

2. **C++ Specific Features**
   - Memory management
   - Templates
   - Operator overloading
   - STL usage
   - Exception handling
   - Type casting

3. **Best Practices**
   - Orthodox Canonical Form
   - Memory leak prevention
   - Clean code principles
   - Header file organization

## 🚀 Compilation and Usage

Each exercise includes its own Makefile. To compile an exercise:

```bash
cd moduleXX/exYY
make
```

## 📦 Repository Structure

```
cpp_modules/
├── cpp00/
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
├── cpp01/
│   ├── ex00/
│   ├── ex01/
│   └── ...
└── ...
```

## 🔍 Key Concepts by Module

### Module 00
- Introduction to C++ syntax
- Classes and member functions
- IO streams
- Initial exposure to OOP concepts

### Module 01
- Memory allocation in C++
- Pointers vs References
- File handling
- Basic string manipulation

### Module 02
- Operator overloading
- Fixed-point numbers
- Orthodox Canonical Form implementation

### Module 03
- Inheritance basics
- Virtual functions
- Access specifiers

### Module 04
- Abstract classes
- Interfaces
- Polymorphism in depth

### Module 05
- Exception handling
- Try-catch blocks
- Custom exceptions

### Module 06
- Different types of casting
- Type conversion
- Static and dynamic casting

### Module 07
- Template programming
- Generic functions
- Template specialization

### Module 08
- STL containers introduction
- Iterators
- Algorithms

### Module 09
- Advanced STL usage
- Container comparisons
- Practical applications

## ⚠️ Important Notes

- All code must follow the C++98 standard
- External libraries are forbidden (except STL in Modules 08-09)
- The Orthodox Canonical Form is mandatory for classes from Module 02 onwards
- Memory leaks must be handled properly

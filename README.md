# Municipal Financial Management System (MFMS)

**Course:** PAP521S – Programming in Practice
**Project:** Project A – Foundation System
**Language:** ANSI C (C99) | **Tools:** VS Code, GCC, Git & GitHub

## Group members

| # | Name | Student number | Primary responsibility |
|---|------|----------------|------------------------|
| 1 | Veikko Ushona | 226038017 | Employee Management (`employees.c/.h`) |
| 2 | Naholo Helena| 226059502 | Budget Management (`budget.c/.h`) |
| 3 | Micheal Fillemon| 226142167 | Supplier Management (`suppliers.c/.h`) |
| 4 | Petrus Hailula | 226062856 | Asset Management (`assets.c/.h`) |
| 5 | George Vincent | 225142422 | Reports (`reports.c/.h`) |
| 6 | Asino David | 226019241 | Functions, integration and validation (`main.c`, `utils.c/.h`) |
| 7 | Otto Kapia | 223123382 | Testing, documentation and Git coordination |

## Project description

MFMS is a menu-driven C application that helps a municipality manage employees, departmental budgets, suppliers and assets, and generate summary reports. It validates user input and is organised into separate modules developed collaboratively by a group of seven students. It is the foundation version of a system that will be extended in Project B.

## System features

- Menu-driven navigation
- Employee management: add, display, search, salary calculation
- Budget management: departmental budgets, expenditure, remaining balance, over-budget detection
- Supplier management: add, display, search
- Asset register: add, display, search
- Reports: employee, budget, supplier, asset
- Input validation (empty names, negative values, invalid menu choices)

## Compilation instructions

With `make`:

```bash
make
```

Or directly with GCC:

```bash
gcc -std=c99 -Wall -Wextra -pedantic -o mfms main.c employees.c budget.c suppliers.c assets.c reports.c utils.c
```

## How to run

```bash
./mfms          # Linux / macOS
mfms.exe        # Windows
```

## Individual responsibilities

 each member lists the functions/modules they developed._

## Project structure

```
MFMS/
├── main.c
├── employees.c / employees.h
├── budget.c / budget.h
├── suppliers.c / suppliers.h
├── assets.c / assets.h
├── reports.c / reports.h
├── utils.c / utils.h      (shared input validation helpers)
├── Makefile
└── README.md
```

## Team workflow

- Each member works on their own branch (e.g. `feature/employees`) and opens a Pull Request into `main`.
- Commit small and often, with clear messages, from your own computer and GitHub account.
- Never commit build output or personal data files.

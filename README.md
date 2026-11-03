<div align="center">

# Graph Algorithms & Data Structures

### A C++20 implementation of classic graph algorithms and fundamental data structures

[![Language](https://img.shields.io/badge/Language-C%2B%2B20-00599C?logo=cplusplus&logoColor=white)](https://en.cppreference.com/w/cpp/20)
[![Algorithms](https://img.shields.io/badge/Algorithms-Prim%20%7C%20Kruskal-7B61FF)](#-minimum-spanning-tree)
[![Data Structures](https://img.shields.io/badge/Data%20Structures-Graph%20%7C%20DSU%20%7C%20Stack-0A7F5A)](#-data-structures)
[![CI](https://img.shields.io/badge/CI-GitHub%20Actions-2088FF?logo=githubactions&logoColor=white)](.github/workflows/ci.yml)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

**An educational C++ project focused on graph theory, minimum spanning trees, and classic data structures.**

[Overview](#-overview) · [Algorithms](#-minimum-spanning-tree) · [Architecture](#-project-structure) · [Build](#-getting-started) · [Example](#-example) · [License](#-license)

</div>

---

## Overview

This repository brings together implementations of fundamental algorithms and data structures in **C++20**. Its central component is a comparative implementation of two approaches to the **Minimum Spanning Tree (MST)** problem: Prim's algorithm and Kruskal's algorithm.

The project is organized into independent modules. Each algorithm has its own graph representation and implementation, while Kruskal's algorithm uses a dedicated Disjoint Set Union structure to efficiently maintain connected components.

The repository also contains a stack implementation and small applications demonstrating stack operations, bracket validation, and generation of a recursively defined sequence.

### Project highlights

- **Two MST algorithms:** Prim and Kruskal, implemented as separate modules.
- **Two graph representations:** adjacency lists for Prim and an edge list for Kruskal.
- **Disjoint Set Union:** path compression and union by rank.
- **Reusable stack:** a template-based `Stack<T>` backed by `std::deque`.
- **Practical examples:** bracket-sequence validation and recursive sequence storage.
- **Modular codebase:** declarations and implementations are separated into header and source files.
- **Automated builds:** GitHub Actions workflow configured to compile both laboratory modules.

> The repository is written in **C++**, using the C++20 language standard. It is not a C implementation.

---

## Minimum Spanning Tree

A **Minimum Spanning Tree** is a subset of edges of a connected, undirected, weighted graph that:

1. Includes every vertex.
2. Contains no cycles.
3. Contains exactly `V - 1` edges.
4. Has the minimum possible sum of edge weights.

Here, `V` is the number of vertices and `E` is the number of edges.

MST algorithms are useful in network design, infrastructure planning, clustering, and other problems where all points must be connected at minimum total cost.

This project implements two classical greedy algorithms for solving this problem.

### 1. Prim's algorithm

**Approach: grow one tree**

Prim's algorithm starts from a selected vertex and gradually expands a single connected tree.

At each iteration, it chooses the minimum-weight edge that connects a vertex already included in the tree to a vertex that has not yet been included.

#### How it works

1. Select the starting vertex (vertex `1` in this implementation).
2. Initialize the minimum connection cost (`key`) for every vertex to infinity. Set the starting vertex's cost to zero.
3. Find the not-yet-included vertex with the smallest current `key`.
4. Add that vertex to the MST.
5. Examine its adjacent edges and update the best known connection (`key`) and predecessor (`parent`) of each eligible neighbor.
6. Repeat until all reachable vertices have been processed.
7. Reconstruct the resulting tree from the `parent` array.

#### Data used by the implementation

| Structure | Purpose |
|---|---|
| `key[]` | Stores the cheapest currently known edge for connecting each vertex to the growing tree. |
| `parent[]` | Stores the predecessor vertex that provides that cheapest connection. |
| `inMST[]` | Marks vertices that have already been added to the MST. |
| Adjacency list | Provides the neighbors and edge weights of a vertex. |

#### Complexity

The implementation searches linearly for the next minimum-key vertex and uses adjacency lists to inspect neighbors.

- **Time:** `O(V² + E)`, commonly written as `O(V²)` for a connected simple graph.
- **Auxiliary space:** `O(V)` for the algorithm's working arrays, excluding the graph and resulting tree.

This implementation uses a linear minimum search rather than a binary heap or priority queue.

**Source files:**
- `laba_4/Primo/Graph_for_Primo.h`
- `laba_4/Primo/Graph_for_Primo.cpp`
- `laba_4/Primo/method_Prima.h`
- `laba_4/Primo/method_Prima.cpp`

---

### 2. Kruskal's algorithm

**Approach: build a forest and merge components**

Kruskal's algorithm considers graph edges in ascending order of weight. It adds an edge if doing so does not create a cycle.

To check whether two endpoints are already connected, the implementation uses a **Disjoint Set Union (DSU)** data structure, also known as Union-Find.

#### How it works

1. Copy the graph's edge list.
2. Sort all edges by non-decreasing weight.
3. Initialize DSU so that every vertex belongs to its own component.
4. Iterate over the sorted edges:
   - Find the representative of each endpoint's component.
   - If the representatives are different, merge the components.
   - Add the edge to the resulting spanning tree.
   - If the result contains `V - 1` edges, stop.
5. Return the resulting graph.

#### Disjoint Set Union (DSU)

The DSU implementation provides two core operations:

| Operation | Description |
|---|---|
| `find(x)` | Finds the representative of the component containing vertex `x`. |
| `unite(a, b)` | Merges the components containing `a` and `b`. Returns `false` if they are already connected. |

Two optimizations make these operations efficient:

- **Path compression:** during `find`, visited vertices are connected directly to the representative.
- **Union by rank:** the root of the shallower tree is attached to the root of the deeper tree.

Together, these optimizations provide an amortized complexity of `O(α(V))` per DSU operation, where `α` is the inverse Ackermann function.

#### Complexity

- **Time:** `O(E log E + E α(V))`, conventionally simplified to `O(E log E)`.
- **Auxiliary space:** `O(V + E)` for DSU, the copied edge list, and the resulting graph.

**Source files:**
- `laba_4/Kruskal/Graph_for_Kruskal.h`
- `laba_4/Kruskal/Graph_for_Kruskal.cpp`
- `laba_4/Kruskal/method_Kruskala.h`
- `laba_4/Kruskal/method_Kruskala.cpp`
- `laba_4/Kruskal/DSU.h`
- `laba_4/Kruskal/DSU.cpp`

---

### Prim vs. Kruskal

Both algorithms produce a minimum spanning tree, but they approach the problem differently.

| Characteristic | Prim | Kruskal |
|---|---|---|
| Main strategy | Grows one tree | Merges connected components |
| Starting point | A selected vertex | No starting vertex required |
| Main graph representation | Adjacency list | Edge list |
| Main supporting structures | `key`, `parent`, `inMST` | DSU / Union-Find |
| Edge selection | Cheapest edge leaving the current tree | Globally cheapest remaining edge |
| Time complexity in this project | `O(V² + E)` | `O(E log E)` |
| Typical use case | Often attractive for dense graphs | Often attractive for sparse graphs |

The algorithms may return different edge sets when multiple MSTs have the same minimum weight. Their **total MST weights**, however, must agree for the same connected graph.

---

## Data structures

### Graph representation for Prim

`Graph_for_Primo` stores vertices and their adjacency lists.

Each adjacency entry is represented by `AdjEdge`, which contains:
- `to` — the neighboring vertex;
- `weight` — the edge weight.

Adding an edge creates entries in both endpoint adjacency lists, so the graph is undirected.

The class also provides methods to access neighbors, count vertices and edges, print the graph, and calculate the total weight of its edges.

### Graph representation for Kruskal

`Graph_for_Kruskal` stores graph edges in a `std::vector<Edge>`.

Each `Edge` contains:
- `to_vertex` — the first endpoint;
- `end_vertex` — the second endpoint;
- `weight` — the edge weight.

This representation makes it straightforward to sort edges before running Kruskal's algorithm.

### Generic stack

The `Stack<T>` class is a template-based stack backed by `std::deque<T>`.

Its interface includes:

| Method | Description |
|---|---|
| `PUSH(value)` | Adds an element to the stack. |
| `POP()` | Removes and returns the top element through `Result_Pop<T>`. |
| `size()` | Returns the number of stored elements. |
| `to_stream()` | Prints the stack contents. |

`Result_Pop<T>` carries both the returned value and a status code indicating whether the operation succeeded.

Implementation files:
- `laba_3/Stack_FIFO/Stackcheck.h`
- `laba_3/Stack_FIFO/Stackcheck.tpp`

---

## Additional exercises

The repository includes two applications built around the stack data structure.

### Bracket sequence validation

The `check_for_3()` function checks whether a string contains correctly balanced round parentheses.

It scans the input from left to right:
- On `(`, it pushes an opening bracket onto the stack.
- On `)`, it checks whether an opening bracket is available and removes it.
- If a closing bracket appears when the stack is empty, the sequence is invalid.
- After processing the entire string, the sequence is valid only if the stack is empty.

The function checks round parentheses `(` and `)`; other characters are ignored.

### Recursive sequence and stack operations

The `Recursion_for_4` class stores values generated by the recursively defined function:

`f(n) = 2^(n + 1) / 3^(n - 1)`

The class supports:
- Initializing a stack with a specified number of sequence values.
- Adding the next value.
- Adding multiple subsequent values.
- Reading the current number of stored elements.
- Printing the stack and the defining function.

These exercises demonstrate how a reusable stack can support different application-level tasks.

---

## Project structure

```text
LABA_2/
│
├── .github/
│   └── workflows/
│       └── ci.yml                  # GitHub Actions build workflow
│
├── laba_3/
│   ├── main.cpp                    # Entry point for laboratory 3
│   │
│   ├── Stack_FIFO/
│   │   ├── Stackcheck.h            # Generic stack declaration
│   │   └── Stackcheck.tpp          # Template implementation
│   │
│   ├── item_3/
│   │   ├── function_for_3.h
│   │   └── function_for_3.cpp      # Bracket sequence validation
│   │
│   └── item_4/
│       ├── function_for_4.h
│       ├── function_for_4.cpp
│       ├── Recursion_for_4.h
│       └── Recursion_for_4.cpp     # Recursive sequence and stack
│
├── laba_4/
│   ├── main_for_4.cpp              # MST demonstration and comparison
│   │
│   ├── Primo/
│   │   ├── Graph_for_Primo.h
│   │   ├── Graph_for_Primo.cpp     # Adjacency-list graph
│   │   ├── method_Prima.h
│   │   └── method_Prima.cpp        # Prim's algorithm
│   │
│   └── Kruskal/
│       ├── Graph_for_Kruskal.h
│       ├── Graph_for_Kruskal.cpp   # Edge-list graph
│       ├── method_Kruskala.h
│       ├── method_Kruskala.cpp     # Kruskal's algorithm
│       ├── DSU.h
│       └── DSU.cpp                 # Disjoint Set Union
│
├── .gitignore
├── LICENSE
└── README.md
```

---

## Getting started

### Requirements

To build the project, you need:

- A C++ compiler with C++20 support (for example, GCC or MinGW-w64).
- Git.
- A terminal or an IDE configured for C++ development.

The repository includes a GitHub Actions workflow that builds the laboratory modules on Ubuntu.

### Clone the repository

```bash
git clone <YOUR_REPOSITORY_URL>
cd LABA_2
```

Replace `<YOUR_REPOSITORY_URL>` with the URL of your GitHub repository.

### Build laboratory 4 — Prim and Kruskal

From the repository root:

```bash
cd laba_4

g++ -std=c++20 -Wall -Wextra -I. -IPrimo -IKruskal \
    main_for_4.cpp \
    Primo/Graph_for_Primo.cpp \
    Primo/method_Prima.cpp \
    Kruskal/Graph_for_Kruskal.cpp \
    Kruskal/method_Kruskala.cpp \
    Kruskal/DSU.cpp \
    -o mst_demo
```

Run on Linux:

```bash
./mst_demo
```

Run on Windows:

```powershell
.\mst_demo.exe
```

For Windows, name the output file `mst_demo.exe` when compiling with MinGW-w64.

### Build laboratory 3 — stack exercises

From the repository root:

```bash
cd laba_3

g++ -std=c++20 -Wall -Wextra -I. \
    main.cpp \
    item_3/function_for_3.cpp \
    item_4/function_for_4.cpp \
    item_4/Recursion_for_4.cpp \
    -o stack_demo
```

Run on Linux:

```bash
./stack_demo
```

Run on Windows:

```powershell
.\stack_demo.exe
```

**Compiler note:** laboratory 3 includes `<format>`. Use a standard library implementation that supports C++20 `std::format` (for example, a sufficiently recent GCC/libstdc++ or MSVC toolchain).

---

## Example

The MST demonstration in `laba_4/main_for_4.cpp` creates an undirected weighted graph with **8 vertices and 12 edges**:

```text
(1, 2,  2)    (1, 5,  3)    (1, 6, 10)
(2, 3,  1)    (2, 7, 35)
(3, 4, 17)
(4, 7, 13)
(5, 6, 11)    (5, 8, 20)
(6, 7, 15)    (6, 8, 12)
(7, 8, 10)
```

The program:
1. Builds the graph for Prim's algorithm.
2. Calculates and prints the resulting spanning tree.
3. Builds the graph for Kruskal's algorithm.
4. Calculates and prints its selected edges.
5. Compares the total weights of both results.

For this input, both algorithms produce a minimum spanning tree with **7 edges** and a total weight of:

```text
Prim:    55
Kruskal: 55
```

The exact selected edges can differ in graphs with multiple minimum spanning trees; the total minimum weight remains the same.

---

## Continuous integration

The repository contains a GitHub Actions workflow at:

`.github/workflows/ci.yml`

The workflow is triggered on:
- `push`;
- `pull_request`.

It defines separate Ubuntu build jobs for:
- **Laboratory 4:** graph representations, Prim, Kruskal, and DSU.
- **Laboratory 3:** stack implementation and the two stack-based exercises (when the directory is present).

This provides an automated compilation check when changes are pushed or submitted through a pull request.

---

## Scope and assumptions

The current MST implementations are designed for **undirected weighted graphs with vertices numbered from `1` to `V`**.

A few implementation details are worth keeping in mind:

- The demonstration uses a connected graph with positive integer weights.
- Prim starts from vertex `1`.
- Kruskal sorts edges by weight and uses DSU to reject cycle-forming edges.
- If the input graph is disconnected, the algorithms cannot produce a spanning tree covering all vertices; the current functions do not expose a separate connectivity-status result.
- The graph classes expect valid vertex indices when edges are added.

These details describe the current implementation and help define the assumptions under which the examples should be used.

---

## License

This project is distributed under the **MIT License**. You are free to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the software, subject to the conditions of the license.

See [`LICENSE`](LICENSE) for the full text.

---

<div align="center">

**Built with C++20 · Algorithms · Data Structures · Graph Theory**

</div>

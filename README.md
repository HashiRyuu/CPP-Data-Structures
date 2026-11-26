# C++ Data Structures and Algorithms

A collection of C++ implementations exploring graph representations, tree operations, hash tables, stacks, and mathematical set operations.

## Repository structure

| File | Concepts |
| --- | --- |
| algorithms/01-graph-representation.cpp | Adjacency maps, adjacency matrices, and neighbor queries |
| algorithms/02-breadth-first-search.cpp | Queue-based breadth-first traversal |
| algorithms/03-bst-insertion-and-traversal.cpp | Iterative binary search tree insertion and inorder traversal using a stack |
| algorithms/04-bst-deletion.cpp | Binary search tree node removal |
| algorithms/05-hash-table.cpp | Open addressing, quadratic probing, insertion, search and deletion |
| algorithms/06-stack-operations.cpp | Iterative and recursive stack transfer, STL swap and assignment |
| set-operations/ | Template-based set wrapper, union, intersection, difference, symmetric difference, subset, power set and partition exercises |

## Build the set demonstration

From the repository root:

```sh
g++ -std=c++17 set-operations/main.cpp set-operations/setFunctions.cpp -o set_demo
./set_demo
```

The template implementation in set.cpp is included by the other translation units and does not need to be compiled separately.

The algorithm files are independent implementation excerpts, not a single executable. They depend on surrounding declarations, headers or driver code that were not included in the supplied files.

## Implementation status

The original algorithm logic is retained. These are learning implementations, not a validated production library. In particular, breadth-first traversal assumes reachable vertices; some graph lookups assume valid inputs; union with an empty set, power-set generation, partition validation and hash probing have edge cases requiring review. The binary search tree deletion excerpt depends on helper methods and class declarations not provided here. Full functional correctness has not been verified.

## Technical topics

C++ templates, STL containers, graph traversal, binary search trees, dynamic memory management, recursion, hashing, and discrete mathematics.

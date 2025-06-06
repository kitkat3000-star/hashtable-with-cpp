# 🧩 C++ Hash Table with Separate Chaining

This project implements a **hash table** data structure using **separate chaining** in C++.  
Separate chaining is a collision-handling technique where each bucket of the hash table contains a linked list (or vector) to store multiple values that hash to the same index.

---

## 🗃️ Features

- Insert key-value pairs
- Search for a key
- Print the hash table
- Delete a key
- Handle collisions using separate chaining

---

## 🛠️ How to Compile & Run

Make sure you have **g++** installed. Then open a terminal in the project directory and run:

```bash
g++ hashtable.cpp -o hashtable
./hashtable

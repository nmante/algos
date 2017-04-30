# <div id="intro">Algorithms and Data Structures</div>

This repo contains common algorithms and data structures. 

***Context:*** I started developing this library/code as a way to study for interviews.

## <div id="installation">Installation</div>

### <div id="unixInstall">OSX/Linux Installation</div>

	git clone https://github.com/nmante/algos
	cd algos
	make
	make install
	
Running `make` will generate a few things:

- Demo program `algos.out` 
- A library that you can use in your own programs `libalgos.a` 
- A set of tests `algos-tests.out`.

Running `make install` will move all the necessary headers & libraries to the `/usr/local/include/algos` and `/usr/local/lib`, respectively.

These compiled libraries/executable files will sit in the `bin` directory.

### <div id="unixUninstall">OSX/Linux Uninstall</div>

To uninstall, simply run:

	make uninstall
	
This will remove the headers and library from

### Usage

To see an example of how to use this library, go ahead and check out the `main.cpp` file.

## <div id="api">Library Contents</div>

This contains a list of data structures and algorithms in this library. This list will be updated as more stuff is added!

#### <div id="ds">Data Structures</div>

- Graphs
- Trees
	- AVL Trees
	- Red Black Trees
- Heaps
	- Min Heap
	- Max Heap

#### Algorithms

- Search
	- Binary
	- Interpolative
	- Kth Largest
- Sorting
	- MergeSort
	- Insertion Sort
	- Heap Sort
	- Quick Sort
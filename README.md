# <div id="intro">Algorithms and Data Structures</div>

This repo contains common algorithms and data structures. 

***Context:*** I started developing this library/code as a way to study for interviews.

## <div id="installation">Installation</div>

### <div id="unixInstall">OSX/Linux Installation</div>

To install the library, run these commands:

	git clone https://github.com/nmante/algos
	cd algos
	make
	make install
	
Running `make` will generate a few things:
 
- A library that you can use in your own programs `libalgos.a` 
- A set of tests `algos-tests.out`.

Running `make install` will move all the necessary headers & libraries to the `/usr/local/include/algos` and `/usr/local/lib`, respectively.

These compiled libraries/executable files will sit in the `bin` directory.

### Usage

To see a simple usage of this library, go ahead and run these commands:

	cd example
	make
	./algos.out
	
The source code for the example is in [example/main.cpp](example/main.cpp).

### <div id="unixUninstall">OSX/Linux Uninstall</div>

To uninstall, simply run:

	make uninstall

in the repo directory (i.e. in algos dir).
	

	
This will remove the header folder and library file from `/usr/local/include/algos` and `/usr/local/lib/libalgos.a`, respectively.

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
- Linked Lists
	- Singly
	- Doubly
	- Circular

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
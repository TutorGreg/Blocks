#  Blocks

## What am I doing here?

The block class was concieved of as my own way of being able to render and acess extremely large grids of data very quickly. It started as an idea for a way to make a grid-based map with generalized data in each cell. I immediately began working on a linked-grid class where each member would have references to its up, down, left, and right neighbors. I thought using these Blocks, there would be a way to make a Grid class that contained very specific information about the grid to expidite operations on the map and map objects. Maybe the Grid Class would contain only a pointer to the head Block? Maybe it would contain the head Block and a pointer? Does the Grid need to have a rigid size or can it be grown/shrunk at will? Does it even need to be a rectangular grid*?

* In another thought expirement, I decided that i would probably be best to always have a rectangular grid for consistency in access operations. However, special block types may be able to skip over empty blocks, saving us time and processing power.
	
	\-	0	1	2	3
	
	0	O	O	O	O
	
	1	O	O	O	O
		
	2	O	O	O	O
	
	3	O			O
	
For example, Block(1,3) could contain a pointer to Block(3,3) as its right variable and potentially an int to incidcate the number of Blocks being skipped.
	

I started with almost no requirements for the class. I realized how little I knew about memory access and storage. And I didn't want to get a masters or even doctorate in computer science to learn all the intricate nuances of C++ and memory access. I figured if I just started coding I would encounter all of them on my own. So here we go.

## What makes a good Block?
The best block will be one that provides us with the fastest access to data possible. I will perform rigorous tests on each of the Block classes creating Grids with thousands of squares and performing thousands of accesses on them. 

The tests should be initially be deesigned using C++ standard objects and then refitted for the custom Block classes.

## The Iterations

### Iteration 1: Block
Block was the first class I designed for this purpose. It has 5 attributes: four pointers for the Blocks left right up and down of the current Block and a positional id number. By positional, I mean that it identifies the position of the Block in the grid (in this case, from left to right then up to down - the way we read in English). For any linked class it seems pointless to have an id attribute unless it is positional. I don't imagine the ID variable to be effiecient and included in the final version of the class.

- id	: a POSITIONAL id number
- left	: a pointer to the block to the left of this one
- right : a pointer to the block to the right of this one
- up	: a pointer to the block up from this one
- down	: a pointer to the block down from this one

### Iteration 2: CoordinatedBlock
The CoordinatedBlock has 8 arguments: the four pointers for neighbor blocks, two more pointers for the previous and next blocks in the grid, and two integers to store the x and y coordinates of the Block. This is a bulky class that seemed like a good idea at the time, but I quickly realized it was way too bulky to be useful.

- left	: a pointer to the block to the left of this one
- right : a pointer to the block to the right of this one
- up	: a pointer to the block up from this one
- down	: a pointer to the block down from this one
- next	: a pointer to the next block in the grid
- prev	: a pointer to the previous block in the grid

### Iteration 3: SimpleBlock

Attributes:
- next 	: Block
- prev 	: Block
- x 	: position
- last_col : int

### Iteration 3.1: SimpleCoordinatedBlock

Attributes:
- Block next
- x position
- y position

### Future Iterations:
- ModularBlock
	- Many different kinds of Blocks to maximize memory and processing efficiency for different use cases
	- For example, EdgeBlocks won't have nullptrs for the edges
	- SkipBlocks can be used to skip "empty" blocks
	
- RecursiveBlock
	- Will be able to make priavte variables because each function will be called on the next block
	- I initially avoided recursive operations because of their potential efficiency drawbacks but could be useful. Although I cannot shake these efficiency fears. Traversing a 100 blocks would mean 100 function calls! But maybe we can use ModularBlocks and CoordinatedBlocks to speed things up?

## Grid Designs

### Grid Design Choice 1: Grid with a pointer to a head Block or as a subclass of Block

Major Differences
- head pointer 

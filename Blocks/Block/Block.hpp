/*
	 Block.hpp
	 Purpose: A block class to be a node in a linked-grid.
	 
	 @author Gregory Sakas
	 @date 7/25/24
	 @version 0.1
 */

#pragma once

#include <stdio.h>

class Block
{
public:
	int id;
	
	Block(int);
	Block(int, Block* left_block);
	Block(int, Block* left_block, Block* up_block);
	Block(int, Block* left_block, Block* right_block, Block* up_bock, Block* down_block);
	~Block();
	
	// next()
	Block* next();
	
	Block* left;
	Block* right;
	Block* up;
	Block* down;
};


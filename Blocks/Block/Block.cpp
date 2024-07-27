/*
	Block.cpp
	 
	@author Gregory Sakas
	@date 7/25/24
	@version 0.1
 */

#include "Block.hpp"

// Constructors
Block::Block(int block_id)
{
	id 		= block_id;
	left 	= nullptr;
	right 	= nullptr;
	up 		= nullptr;
	down 	= nullptr;
}

Block::Block(int block_id, Block* left_block)
{
	id 		= block_id;
	left 	= left_block;
	right 	= nullptr;
	up 		= nullptr;
	down 	= nullptr;
}

Block::Block(int block_id, Block* left_block, Block* up_block)
{
	id 		= block_id;
	left 	= left_block;
	right 	= nullptr;
	up 		= up_block;
	down 	= nullptr;
}

Block::Block(int block_id, Block* left_block, Block* right_block, Block* up_block, Block* down_block)
{
	id 		= block_id;
	left 	= left_block;
	right 	= right_block;
	up 		= up_block;
	down 	= down_block;
}

// Destructor
Block::~Block() { }

// next
Block* Block::next()
{
	if (right != nullptr)
	{
		return right;
	}
	else if (down != nullptr)
	{
		Block* temp = down;
		
		while(temp->left) temp = temp->left;
		
		return down;
	}
	
	else
	{
		return nullptr;
	}
}

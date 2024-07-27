/*
	BlockGrid.cpp

	@author Gregory Sakas
	@date 7/25/24
	@version 0.1
*/

#include "BlockGrid.hpp"

BlockGrid::BlockGrid(int size)
: Block::Block(0)
{
	create_grid(size, size);
}

BlockGrid::BlockGrid(int width, int height)
: Block::Block(0)
{
	create_grid(width, height);
}

BlockGrid::~BlockGrid() { }

// Getter
int BlockGrid::get_id() { return id; }

void BlockGrid::create_grid(int width, int height)
{
	int block_id;
	Block* temp { this };
	Block* new_block { nullptr };
	Block* previous_row { this };
	
	for(int y { 0 }; y < height; y++ )
	{
		for(int x { 0 }; x < width; x++)
		{
			block_id = x + (y * width);
			
			if (block_id == 0) continue;
			
			else
			{
				if(x != 0)
				{
					new_block = new Block(block_id, temp);
					temp->right = new_block;
				}
				
				if (y != 0)
				{
					new_block->up = previous_row;
					previous_row->down = new_block;
					
					previous_row = previous_row->next();
				}
			}
			
			temp = new_block;
		}
	}
	
}

void BlockGrid::print_block_list()
{
	Block* temp { this };
	
	while(temp)
	{
		std::cout << "Block: " << temp->id;
		
		if(temp->left) 	std::cout << "\tleft: " << temp->left->id;
		else 			std::cout << "\tleft: NULL";
		if(temp->right) std::cout << "\tright: " << temp->right->id;
		else 			std::cout << "\tright: NULL";
		if(temp->up) 	std::cout << "\tup: " << temp->up->id;
		else 			std::cout << "\tup: NULL";
		if(temp->down)	std::cout << "\tdown: " << temp->down->id;
		else 			std::cout << "\tdown: NULL";
		
		temp = temp->next();
	}
	
}

Block* BlockGrid::get_x_left(int x)
{
	// TODO: x must be positive
	Block* temp { this };
	while(x-- > 0 && temp != nullptr) temp = temp->left;
	
	return temp;
}

Block* BlockGrid::get_x_right(int x)
{
	// TODO: x must be positive
	Block* temp { this };
	while(x-- > 0 && temp != nullptr) temp = temp->right;
	
	return temp;
}

Block* BlockGrid::get_y_up(int y)
{
	// TODO: y must be positive
	Block* temp { this };
	
	while(y-- > 0 && temp != nullptr) temp = temp->up;
	
	return temp;
}

Block* BlockGrid::get_y_down(int y)
{
	// TODO: y must be positive
	Block* temp { this };
	
	while(y-- > 0 && temp != nullptr) temp = temp->down;
	
	return temp;
}

Block* BlockGrid::get_start_of_row()
{
	if (left == nullptr) return this;
	
	Block* temp { left };
	
	while(temp->left) temp = temp->left;
	
	return temp;
}

Block* BlockGrid::get_end_of_row()
{
	if (right == nullptr) return this;
	
	Block* temp { right };
	
	while(temp->right) temp = temp->right;
	
	return temp;
}

Block* BlockGrid::get_start_of_column()
{
	if (up == nullptr) return this;
	
	Block* temp { up };
	
	while(temp->up) temp = temp->up;
	
	return temp;
}

Block* BlockGrid::get_end_of_column()
{
	if (down == nullptr) return this;
	
	Block* temp { down };
	
	while(temp->down) temp = temp->down;
	
	return temp;
}

// Utilities Plus
// TODO: implement subgrids
/*
	@param starting block
	@param grid size
	@return a pointer to the head of a list of blocks in the subgrid
 */
Block* BlockGrid::get_subgrid(Block* head, int size)
{
	return get_subgrid(head, size, size);
}

Block* BlockGrid::get_subgrid(Block* head, int width, int height)
{
	return nullptr;
}

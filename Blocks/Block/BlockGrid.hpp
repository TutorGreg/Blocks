/*
	BlockGrid.hpp
	Purpose: An extension of the Block class that provides utility access functions.
 
	@author Gregory Sakas
	@date 7/25/24
	@version 0.1

 */

#pragma once

#include <stdio.h>
#include <iostream>
#include "Block.hpp"

class BlockGrid : public CoordinatedBlock
{
public:
	BlockGrid(int);
	BlockGrid(int, int);
	~BlockGrid();
	
	void create_grid(int, int);
	void print_block_list();
	
	// Getter
	int get_id();
	
	// Utilities
	Block* get_x_left(int);
	Block* get_x_right(int);
	Block* get_y_up(int);
	Block* get_y_down(int);
	Block* get_block_by_id(int);
	
	// TODO: these are useless right now
	Block* get_start_of_row();
	Block* get_end_of_row();
	Block* get_start_of_column();
	Block* get_end_of_column();
	
	// Utilities Plus
	Block* get_subgrid(Block*, int);
	Block* get_subgrid(Block*, int, int);
	Block* get_radial_grid(Block*, int);

private:
	int last_row;
	int last_column;
};

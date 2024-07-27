//
//  CoordinatedBlockGrid.hpp
//  Blocks
//
//  Created by Gregory Sakas on 7/26/24.
//

#pragma once

#include <stdio.h>
#include <iostream>
#include "Block.hpp"

class CoordinatedBlockGrid : public CoordinatedBlock
{
public:
	CoordinatedBlockGrid(int);
	CoordinatedBlockGrid(int, int);
	CoordinatedBlockGrid(int, int, int, int);
	~CoordinatedBlockGrid();
	
	void create_grid(int, int);
	void print_block_list();
	
	
	int get_id();
	
	int first_column, first_row, last_column, last_row;
};

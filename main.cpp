//
//  main.cpp
//  Blocks
//
//  Created by Gregory Sakas on 7/25/24.
//

#include <iostream>
#include "Block.hpp"
#include "BlockGrid.hpp"

/*
void block_test_1()
{
	Block* block_test = new Block(1);
	
	std::cout << "Block: " << block_test->get_id() << std::endl;
	
	return;
}
//*/

void block_plus_test_1()
{
	BlockGrid* grid_test = new BlockGrid(4);
	grid_test->print_block_list();
	
	std::cout << "BlockPlusTest:get_x_right(2): " << plus_test->get_x_right(2)->block_id << std::endl;
}

int main(int argc, const char * argv[]) {
	
	// \
	block_test_1();
	block_plus_test_1();
	
	return 0;
}

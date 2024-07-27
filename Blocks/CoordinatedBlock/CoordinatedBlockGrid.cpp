//
//  CoordinatedBlockGrid.cpp
//  Blocks
//
//  Created by Gregory Sakas on 7/26/24.
//

#include "CoordinatedBlockGrid.hpp"

CoordinatedBlockGrid::CoordinatedBlockGrid(int size)
{
	
}

CoordinatedBlockGrid::CoordinatedBlockGrid(int)
{
	
}

void CoordinatedBlockGrid::print_block_list()
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
		if(temp->prev)	std::cout << "\tprev: " << temp->down->id;
		else 			std::cout << "\tprev: NULL";
		if(temp->next)	std::cout << "\tnext: " << temp->down->id;
		else 			std::cout << "\tnext: NULL";
		
		temp = temp->next();
	}
	
	
}

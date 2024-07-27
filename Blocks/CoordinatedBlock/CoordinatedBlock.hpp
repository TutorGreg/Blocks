//
//  CoordinatedBlock.hpp
//  Blocks
//
//  Created by Gregory Sakas on 7/26/24.
//

#pragma once

#include <stdio.h>

class CoordinatedBlock
{
public:
	CoordinatedBlock* left;
	CoordinatedBlock* right;
	CoordinatedBlock* up;
	CoordinatedBlock* down;
	
	CoordinatedBlock* prev;
	CoordinatedBlock* next;
	
	int id;
	int x;
	int y;
	
	CoordinatedBlock(int, int, int);
	~CoordinatedBlock();
	
	//CoordinatedBlock* forward(int, int);
	//CoordinatedBlock* back(int, int);
};


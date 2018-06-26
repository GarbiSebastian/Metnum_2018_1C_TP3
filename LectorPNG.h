/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   LectorPNG.h
 * Author: panda
 *
 * Created on 15 de junio de 2018, 13:16
 */

#ifndef LECTORPNG_H
#define LECTORPNG_H

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <png.h>

class LectorPNG {
public:
	LectorPNG(const char* filename);
	LectorPNG(const LectorPNG& orig);
	virtual ~LectorPNG();
	int init();
	std::string mostramealgo();
	int pos(int i, int j);
private:
	char filemane[100];
	FILE* fileptr;
	png_structp png_ptr;
	png_infop info_ptr;
	int number_of_passes;
	png_bytep * row_pointers;
	int width, height;
	png_byte color_type;
	png_byte bit_depth;
};

#endif /* LECTORPNG_H */


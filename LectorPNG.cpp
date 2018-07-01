/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   LectorPNG.cpp
 * Author: panda
 *
 * Created on 15 de junio de 2018, 13:16
 */

#include <cstdio>



#include "LectorPNG.h"

LectorPNG::LectorPNG(const char* name) {
	strcpy(this->filemane, name);
}

LectorPNG::LectorPNG(const LectorPNG& orig) {
}

LectorPNG::~LectorPNG() {
}

int LectorPNG::init() {
	this->fileptr = fopen(this->filemane, "rb");
	if (this->fileptr == NULL) {
		return 1;
	}

	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) abort();

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr) abort();

	if (setjmp(png_jmpbuf(png_ptr))) abort();

	png_init_io(png_ptr, this->fileptr);

	png_read_info(png_ptr, info_ptr);

	width = png_get_image_width(png_ptr, info_ptr);
	height = png_get_image_height(png_ptr, info_ptr);
	color_type = png_get_color_type(png_ptr, info_ptr);
	bit_depth = png_get_bit_depth(png_ptr, info_ptr);

	// Read any color_type into 8bit depth, RGBA format.
	// See http://www.libpng.org/pub/png_ptr/libpng-manual.txt

	if (bit_depth == 16)
		png_set_strip_16(png_ptr);

	if (color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_palette_to_rgb(png_ptr);

	// PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
	if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
		png_set_expand_gray_1_2_4_to_8(png_ptr);

	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))
		png_set_tRNS_to_alpha(png_ptr);

	// These color_type don't have an alpha channel then fill it with 0xff.
	if (color_type == PNG_COLOR_TYPE_RGB ||
			color_type == PNG_COLOR_TYPE_GRAY ||
			color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_filler(png_ptr, 0xFF, PNG_FILLER_AFTER);

	if (color_type == PNG_COLOR_TYPE_GRAY ||
			color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
		png_set_gray_to_rgb(png_ptr);

	png_read_update_info(png_ptr, info_ptr);

	row_pointers = (png_bytep*) malloc(sizeof (png_bytep) * height);
	for (int y = 0; y < height; y++) {
		row_pointers[y] = (png_byte*) malloc(png_get_rowbytes(png_ptr, info_ptr));
	}

	png_read_image(png_ptr, row_pointers);

	fclose(this->fileptr);

	return 0;
}

std::string LectorPNG::mostramealgo() {
	char datos[100];
	int i = 1, j = 1;
	sprintf(datos, "tam: %d - pos(%i,%i): %i", height, i, j, pos(i, j));
	return datos;
}

int LectorPNG::pos(int i, int j) {
	png_bytep fila = row_pointers[i];
	return fila[j];
}

#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__


struct Texture {
	unsigned int texture_id;
	int warp_r;
	int warp_s;
	int warp_t;
	int min_filter;
	int mag_filter;
	int type;
};

#endif
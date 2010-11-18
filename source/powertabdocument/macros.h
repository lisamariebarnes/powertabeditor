#ifndef __MACROS_H__
#define __MACROS_H__

#include <cassert>
#include <stdint.h>
#include <algorithm> // std::transform
#include <string>
using std::string;
#include <iostream>

// Little-endian based LONG/WORD/BYTE macros
#ifndef MAKEWORD
#define MAKEWORD(a, b)      ((uint16_t)(((uint8_t)((uint32_t)(a) & 0xff)) | ((uint16_t)((uint8_t)((uint32_t)(b) & 0xff))) << 8))
#endif

#ifndef MAKELONG
#define MAKELONG(a, b)      ((uint32_t)(((uint16_t)((uint32_t)(a) & 0xffff)) | ((uint32_t)((uint16_t)((uint32_t)(b) & 0xffff))) << 16))
#endif

#ifndef LOWORD
#define LOWORD(l)           ((uint16_t)((uint32_t)(l) & 0xffff))
#endif

#ifndef HIWORD
#define HIWORD(l)           ((uint16_t)((uint32_t)(l) >> 16))
#endif

#ifndef LOBYTE
#define LOBYTE(w)           ((uint8_t)((uint32_t)(w) & 0xff))
#endif

#ifndef HIBYTE
#define HIBYTE(w)           ((uint8_t)((uint32_t)(w) >> 8))
#endif

// min/max macros - TODO - remove these in favour of std::min and std::max
/*
#ifndef NOMINMAX
#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)  (((a) < (b)) ? (a) : (b))
#endif
#endif*/

#ifndef CHECK_THAT
#define CHECK_THAT(cond, rc) 	\
	if ( cond ) {}			\
	else {					\
		std::cerr << "Error at: " << std::endl << __FILE__ << std::endl << "Line: " <<  __LINE__ << std::endl; \
		return rc;							\
	}

#endif

extern string ArabicToRoman(uint32_t number, bool upperCase);

#endif
/////////////////////////////////////////////////////////////////////////////
// Name:            powertaboutputstream.h
// Purpose:         Output stream used to serialize MFC based Power Tab data
// Author:          Brad Larsen
// Modified by:     
// Created:         Dec 20, 2004
// RCS-ID:          
// Copyright:       (c) Brad Larsen
// License:         wxWindows license
/////////////////////////////////////////////////////////////////////////////

#ifndef __POWERTABOUTPUTSTREAM_H__
#define __POWERTABOUTPUTSTREAM_H__

#include <stdint.h>
#include <fstream>
using std::ofstream;

#ifdef __GNUC__
#include <unordered_map>
#define hash_map std::unordered_map
//using std::hash_map;
#else
#include <hash_map>
using stdext::hash_map;
#endif

#include <string>
using std::string;
#include <vector>
using std::vector;

#include "powertabstream.h"
#include "rect.h"
#include "colour.h"
#include "powertabobject.h"
#include "macros.h"

class PowerTabObject;

/// Output stream used to serialize MFC based Power Tab data
class PowerTabOutputStream    
{
	// Member Variables
protected:
	bool						m_mapsInitialized;                  ///< Determines whether or not the maps have been initialized
	hash_map<string, uint32_t>	m_classInfoHashMap;                 ///< Map of class Ids to object index
	hash_map<PowerTabObject *, uint32_t>	m_objectHashMap;                    ///< Map of object pointers to object index
	uint32_t					m_mapCount;                         ///< Internal count of mapped objects
	PowerTabStreamError			m_lastPowerTabError;                ///< Last Power Tab specific error
	ofstream m_stream;

	// Constructor/Destructor
public:
	PowerTabOutputStream(const string& filename);
	~PowerTabOutputStream();

	// Write Functions
	bool WriteCount(uint32_t count);
	bool WriteAnsiText(const string& text);
	bool WriteMFCString(const string& string);
	bool WriteWin32ColorRef(Colour color);
	bool WriteMFCRect(const Rect& rect);
	bool WriteObject(PowerTabObject* object);

protected:
	bool WriteClassInformation(const PowerTabObject* object);
	bool WriteMFCStringLength(uint32_t length, bool unicode);

	// Error Checking Functions
public:
	/// Checks the current state of the stream
	/// @return True if the stream is OK, false if an error has occurred
	bool CheckState()                                           
	{return (!fail() && (m_lastPowerTabError == POWERTABSTREAM_NO_ERROR));}
	string GetLastErrorMessage();

protected:
	bool CheckCount();

	// Operations
	bool MapObject(const PowerTabObject* object);

public:
	/// Gets the current stream position, in bytes
	/// @return The current stream position, in bytes
	long TellO()
	{
		return (long)m_stream.tellp();
	}

	bool fail()
	{
		return m_stream.fail();
	}

	template <class T>
	bool WriteVector(vector<T*>& vect)
	{
		uint32_t count = vect.size();
		WriteCount(count);
		CHECK_THAT(CheckState(), false);
		for (uint32_t i = 0; i < count; i++)
		{
			WriteObject(vect[i]);
			CHECK_THAT(CheckState(), false);
		}
		return true;
	}

	template<class T>
	PowerTabOutputStream& operator<<(const T& data)
	{
		m_stream.write((char *)&data, sizeof(data));
		return *this;
	}

	void close()
	{
		m_stream.close();
	}

};

#endif
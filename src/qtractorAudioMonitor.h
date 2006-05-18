// qtractorAudioMonitor.h
//
/****************************************************************************
   Copyright (C) 2006, rncbc aka Rui Nuno Capela. All rights reserved.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

*****************************************************************************/

#ifndef __qtractorAudioMonitor_h
#define __qtractorAudioMonitor_h

#include "qtractorMonitor.h"


//----------------------------------------------------------------------------
// qtractorAudioMonitor -- Audio monitor bridge value processor.

class qtractorAudioMonitor : public qtractorMonitor
{
public:

	// Constructor.
	qtractorAudioMonitor(unsigned short iChannels,
		float fGain = 1.0f, float fPanning = 0.0f);

	// Destructor.
	~qtractorAudioMonitor();

	// Channel property accessors.
	void setChannels(unsigned short iChannels);
	unsigned short channels() const;

	// Value holder accessors.
	void setValue(unsigned short iChannel, float fValue);
	float value(unsigned short iChannel) const;

	// Batch processor.
	void process(float **ppFrames, unsigned int iFrames);

protected:

	// Rebuild the whole panning-gain array...
	void reset();

private:

	// Instance variables.
	unsigned short m_iChannels;
	float         *m_pfValues;
	float         *m_pfGains;
};


#endif  // __qtractorAudioMonitor_h

// end of qtractorAudioMonitor.h

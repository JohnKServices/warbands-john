/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2009 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */
#ifndef HKBASE_LINE_NUMBER_STREAMREADER_H
#define HKBASE_LINE_NUMBER_STREAMREADER_H

#include <Common/Base/System/Io/Reader/hkStreamReader.h>

/// Counts line numbers from another stream.
class hkLineNumberStreamReader : public hkStreamReader
{
	public:

			/// Create a buffered stream from stream 's'.
			/// Adds a reference to 's'.
		hkLineNumberStreamReader(hkStreamReader* s);

			/// Removes reference to the reader in the constructor.
		~hkLineNumberStreamReader();

			/// Get the current line number.
		int getLineNumber() const { return m_lineNumber; }

			/* inherited */

		virtual int read(void* buf, int nbytes);

		virtual hkBool isOk() const;

		virtual hkBool markSupported() const;

		virtual hkResult setMark(int markLimit);

		virtual hkResult rewindToMark();

	protected:

		hkStreamReader* m_stream; // child stream or HK_NULL for inplace

		int m_lineNumber;
		int m_lineNumberAtMark;
};

#endif //HKBASE_LINE_NUMBER_STREAMREADER_H

/*
* Havok SDK - NO SOURCE PC DOWNLOAD, BUILD(#20090704)
* 
* Confidential Information of Havok.  (C) Copyright 1999-2009
* Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
* Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
* rights, and intellectual property rights in the Havok software remain in
* Havok and/or its suppliers.
* 
* Use of this software for evaluation purposes is subject to and indicates
* acceptance of the End User licence Agreement for this product. A copy of
* the license is included with this software and is also available at www.havok.com/tryhavok.
* 
*/

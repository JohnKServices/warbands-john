/* 
 * 
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Level 2 and Level 3 source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2009 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 * 
 */

#ifndef INC_TRIANGLE_SELECTION_CHANNEL_H
#define INC_TRIANGLE_SELECTION_CHANNEL_H

/// Meta information
extern const class hkClass hkxTriangleSelectionChannelClass;


	/// Stores a selection of triangle indices
class hkxTriangleSelectionChannel
{
	public:

		HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR( HK_MEMORY_CLASS_SCENE_DATA, hkxTriangleSelectionChannel );
		HK_DECLARE_REFLECTION();


		//
		// Members
		//
	public:

		hkInt32* m_selectedTriangles;
		hkInt32 m_numSelectedTriangles;

};


#endif // INC_TRIANGLE_SELECTION_CHANNEL_H


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

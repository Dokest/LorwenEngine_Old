#pragma once


#define CHUNK_HEADER_SIZE (sizeof(unsigned char*))

class MemoryManager
{
	unsigned char** m_ppRawMemoryArray;
	unsigned char* m_pHead;
	unsigned int m_ChunkSize, m_NumChunks;

	unsigned int m_memArraySize = 0;
	bool m_bAllowResize = false;

public:
	MemoryManager();
	~MemoryManager();

	bool Init(unsigned int chunkSize, unsigned int numChunks);
	void Destroy();

	// Allocation Functions
	void* Alloc();
	void Free(void* pMem);
	unsigned int GetChunkSize() const { return m_ChunkSize; }

	// Settings
	inline void SetAllowResize(bool bAllowResize)
	{
		m_bAllowResize = bAllowResize;
	}


private:
	void Reset();

	bool GrowMemoryArray();
	unsigned char* AllocateNewMemoryBlock();

	// Internal linked list management
	unsigned char* GetNext(unsigned char* pBlock);
	void SetNext(unsigned char* pBlockToChange, unsigned char* pNewNext);

};


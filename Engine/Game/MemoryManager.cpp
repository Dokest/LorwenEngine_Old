#include "MemoryManager.h"

#include <stdlib.h>

MemoryManager::MemoryManager()
{

}

MemoryManager::~MemoryManager()
{

}

bool MemoryManager::Init(unsigned int chunkSize, unsigned int numChunks)
{
	m_ChunkSize = chunkSize;
	m_NumChunks = numChunks;





	return GrowMemoryArray();
}

void MemoryManager::Destroy()
{

}

void* MemoryManager::Alloc()
{
	// If we're out of memory chunks, grow the pool. This is very expensive.
	if (!m_pHead)
	{
		// if we don't allow resizes, return NULL
		if (!m_bAllowResize)
			return NULL;
		// attempt to grow the pool
		if (!GrowMemoryArray())
			return NULL; // couldn't allocate anymore memory
	}

	// grab the first chunk from the list and move to the next chunks
	unsigned char* pRet = m_pHead;

	m_pHead = GetNext(m_pHead);

	return (pRet + CHUNK_HEADER_SIZE); // make sure we return a pointer to the data section only
}

void MemoryManager::Free(void* pMem)
{
	// Calling Free() on a NULL pointer is perfectly valid C++ so
	// we have to check for it.
	if (pMem != NULL)
	{
		// The pointer we get back is just to the data section of
		// the chunk. This gets us the full chunk.
		unsigned char* pBlock =
			((unsigned char*)pMem) - CHUNK_HEADER_SIZE;
		// push the chunk to the front of the list
		SetNext(pBlock, m_pHead);
		m_pHead = pBlock;
	}
}

void MemoryManager::Reset()
{

}

bool MemoryManager::GrowMemoryArray()
{
	// Allocate new array
	size_t allocationSize = sizeof(unsigned char*) * (m_memArraySize + 1);
	unsigned char** ppNewMemoryArray = (unsigned char**)malloc(allocationSize);

	// Make sure the allocation succeeded
	if (!ppNewMemoryArray)
		return false;

	// Copy existing pointers over
	for (unsigned int i = 0; i < m_memArraySize; i++)
	{
		ppNewMemoryArray[i] = m_ppRawMemoryArray[i];
	}

	// Allocate a new block of memory
	ppNewMemoryArray[m_memArraySize] = AllocateNewMemoryBlock();

	// Attach the block to the end of the current memory list
	if (m_pHead)
	{
		unsigned char* pCurr = m_pHead;
		unsigned char* pNext = GetNext(m_pHead);

		while (pNext)
		{
			pCurr = pNext;
			pNext = GetNext(pNext);
		}

		SetNext(pCurr, ppNewMemoryArray[m_memArraySize]);
	}
	else
	{
		m_pHead = ppNewMemoryArray[m_memArraySize];
	}

	// Destroy old memory array
	if (m_ppRawMemoryArray)
		free(m_ppRawMemoryArray);

	// Assign the new memory array & increase the size count
	m_ppRawMemoryArray = ppNewMemoryArray;
	m_memArraySize++;

	return true;
}

unsigned char* MemoryManager::AllocateNewMemoryBlock()
{
	// Calculate size of each block
	size_t blockSize = m_ChunkSize + CHUNK_HEADER_SIZE; // Chunk + Linked list header

	// Overhead
	size_t trueSize = blockSize * m_NumChunks;
	
	// Allocate memory
	unsigned char* pNewMem = (unsigned char*)malloc(trueSize);

	if (pNewMem)
		return NULL;

	// Turn the memory into a linked list of chunks
	unsigned char* pEnd = pNewMem + trueSize;
	unsigned char* pCurr = pNewMem;

	while (pCurr < pEnd)
	{
		// Calculate the next pointer position
		unsigned char* pNext = pCurr + blockSize;

		// Set the next pointer
		unsigned char** ppChunkHeader = (unsigned char**)pCurr;
		ppChunkHeader[0] = (pNext < pEnd ? pNext : NULL);

		// Move to the next block
		pCurr += blockSize;

	}

	return pNewMem;
}

unsigned char* MemoryManager::GetNext(unsigned char* pBlock)
{
	for (unsigned int i = 0; i < m_memArraySize; i++)
	{
		if (m_ppRawMemoryArray[i] == pBlock)
			return m_ppRawMemoryArray[i + 1];
	}


}

void MemoryManager::SetNext(unsigned char* pBlockToChange, unsigned char* pNewNext)
{
	for (unsigned int i = 0; i < m_memArraySize; i++)
	{
		if (m_ppRawMemoryArray[i] == pBlockToChange)
			m_ppRawMemoryArray[i + 1] = pNewNext;

	}
}


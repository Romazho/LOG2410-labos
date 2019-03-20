///////////////////////////////////////////////////////////
//  InvertTransform.cpp
//  Implementation of the Class InvertTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////
#include "InvertTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

// Methode pour appliquer une transformation d'inversion à un Chunk
void InvertTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{ 
	Chunk_iterator tempIterator(c);
	size_t size = c->size();
	for (int i = 0, j = size-1; i < size; i++, j-- )
		tempIterator->get()[i] = c->get()[j]; // Inversement

	outFile.addChunk(tempIterator);
}

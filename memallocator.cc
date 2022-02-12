#include "memallocator.h"
#include <stdio.h>
#include <stdlib.h>

struct descriptor
{
	struct descriptor* next;
	struct descriptor* prev;
	int size;
	char is_free;
};
typedef struct descriptor descriptor_t;

descriptor_t* head = NULL;
int fullSize = 0;

int meminit(void* s, int size) 
{
	if (head != NULL || size < sizeof(descriptor_t) || s == NULL) 
	{
		return 1;
	}

	head = (descriptor_t*)s;

	head->size = size - sizeof(descriptor_t);
	head->next = NULL;
	head->prev = NULL;
	head->is_free = 1;

	fullSize = size;

	return 0;
}


void memdone()
{
	head = NULL;
	int size = 0;

	if (head == NULL)
	{
		return;
	}

	descriptor_t* block = head;

	while (block != NULL) {
		if (block->is_free == 1)
		{
			size += block->size;
		}

		block = block->next;
	}

	size += sizeof(descriptor_t);

	if (size < fullSize)
	{
		fprintf(stderr, "Memory leak was detected");
	}
}


void* memalloc(int size) 
{
	descriptor_t* block = head;

	while (block != NULL)
	{
		if (block->is_free == 1 && block->size >= size) 
		{
			if (block->size > sizeof(descriptor_t) + size)
			{
				descriptor_t* new_block = (descriptor_t*)(((char*)block) + sizeof(descriptor_t) + size);
				new_block->size = block->size - size - sizeof(descriptor_t);
				new_block->next = block->next;
				new_block->prev = block;
				if (new_block->next != NULL)
				{
					new_block->next->prev = new_block;
				}
				new_block->is_free = 1;
				block->size = size;
				block->next = new_block;
			}

			block->is_free = 0;

			return (void*)(((char*)block) + sizeof(descriptor_t));
		}
		block = block->next;
	}
	return NULL;
}


void memfree(void* p)
{
	if (p == NULL)
	{
		return;
	}

	descriptor_t* free_block = (descriptor_t*)((char*)p - sizeof(descriptor_t));

	if (free_block == NULL || free_block->is_free == 1)
	{
		return;
	}

	descriptor_t* buffer_block = free_block;
	buffer_block->is_free = 1;

	if (free_block->prev != NULL) 
	{
		if (free_block->prev->is_free == 1)
		{
			int new_size = 0;

			if (free_block->next != NULL)
			{
				new_size = (char*)free_block->next - (char*)(free_block->prev + 1);
			}
			else
			{
				new_size = (char*)(head + 1) + fullSize - (char*)(free_block->prev + 1);
			}

			free_block->prev->next = free_block->next;


			if (free_block->next != NULL)
			{
				free_block->next->prev = free_block->prev;
			}

			free_block->prev->size = new_size;
			buffer_block = free_block->prev;
		}
	}

	if (buffer_block->next != NULL) 
	{
		if (buffer_block->next->is_free == 1) 
		{
			int new_size = 0;

			if (buffer_block->next->next != NULL)
			{
				new_size = (char*)buffer_block->next->next - (char*)(buffer_block + 1);
			}
			else
			{
				new_size = (char*)(head + 1) + fullSize - (char*)(buffer_block + 1);
			}

			if (buffer_block->next->next != NULL)
			{
				buffer_block->next->next->prev = buffer_block;
			}

			buffer_block->next = buffer_block->next->next;
			buffer_block->size = new_size;
		}
	}

	if (buffer_block->next != NULL)
	{
		if (((char*)(buffer_block + 1) + buffer_block->size) != (char*)buffer_block->next) 
		{
			void* leaked_ptr = (void*)((char*)(buffer_block + 1) + buffer_block->size);
			int size = (char*)buffer_block->next - (char*)leaked_ptr;

			buffer_block->size += size;
		}
	}
	else
	{
		if (((char*)head + fullSize) != ((char*)(buffer_block + 1) + buffer_block->size))
		{
			void* leaked_ptr = (void*)((char*)(buffer_block + 1) + buffer_block->size);
			int size = (char*)head + fullSize - (char*)leaked_ptr;

			buffer_block->size += size;
		}
	}
}


int memgetminimumsize() 
{
	return sizeof(descriptor_t);
}


int memgetblocksize() 
{
	return sizeof(descriptor_t);
}


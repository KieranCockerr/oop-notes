#include <iostream>

class MemoryBlock
{
public:
	// Simple constructor that initialises the resource.
	MemoryBlock(int t_length = 1)
		: m_length(t_length)
		, m_buffer(new int[t_length])
	{
		for (int i = 0; i < m_length; i++)
		{
			m_buffer[i] = i;
		}
	}

	// Copy constructor
	MemoryBlock(MemoryBlock const& t_copy)
	{
		// Step 1: Allocate new heap resource for the lhs object (left hand side)
		m_buffer = new int[t_copy.m_length]; // getting length of rhs so that lhs matches	

		// Step 2: Using the more efficient memcpy
		memcpy(m_buffer, t_copy.m_buffer, sizeof(int) * t_copy.m_length); // Destination, Reading from, Size

		// Assign m_length
		m_length = t_copy.m_length;
	}

	// Destructor to delete the memory resource.
	~MemoryBlock() 
	{
		delete[] m_buffer;
	}

	// Inside the memory block class, implementation of the assignment operator
	// Needed as this class has a pointer as a member variable
	// Attempt 1
	// t_rhs means right hand side
	void operator=(MemoryBlock const& t_rhs)
	{
		// Check for self assignment (exact copy)
		// // Make sure both lhs and rhs are different
		// "this" is a pointer (lhs)
		if (this != &t_rhs)
		{
			// We want to make a "Deep copy" of the rhs object
			// Both objects should have their own heap resource (array)
			// Check both array lengths are not the same
			if (m_length != t_rhs.m_length)
			{
				// Step 1: delete the existing array for this object
				delete[] m_buffer;

				// Step 2: Allocate new heap resource for the lhs object (left hand side)
				m_buffer = new int[t_rhs.m_length]; // getting length of rhs so that lhs matches
			}
		}

		// Step 3: Copy the array values from rhs to lhs
		/*for (int i = 0; 1 < t_rhs.m_length; i++)
		{
			m_buffer[i] = t_rhs.m_buffer[i];
		}*/

		// Step 3: Using the more efficient memcpy
		// Size is not the number of cells, but the number of bytes*
		memcpy(m_buffer, t_rhs.m_buffer, sizeof(int) * t_rhs.m_length); // Destination, Reading from, Size

		// Assign m_length
		m_length = t_rhs.m_length;
	}

private:
	int* m_buffer; // Raw pointer to memory resource
	int m_length; // The length of the memory resource
};

// pass by reference to pass the variable to the function instead of passing a copy (Important for project)
void assignBlock(MemoryBlock& t_block)
{
	MemoryBlock block2(10);
	block2 = t_block;
}

int main()
{
	MemoryBlock block1(10); // array size is 1
	MemoryBlock block2 = block1; // this is a problem as it shares a memory address with block 2, makes another shallow copy
	assignBlock(block1);

	//block2 = block1; // *shallow copy, don't do this as it causes memory leak and sharing of the same resource
}



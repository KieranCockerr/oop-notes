#include <iostream>

class Enemy
{
public:

	Enemy(int t_health) : m_health(t_health)
	{
		std::cout << "Enemy constructed \n";
	}

	~Enemy()
	{
		std::cout << "~Enemy called \n";
	}
	int m_health;
};


std::shared_ptr<Enemy> createEnemy()
{
	// You can create shared pointers to classes as well (Must pass consstructor arguments, a value)
	std::shared_ptr<Enemy> eptr = std::make_shared<Enemy>(10);

	return eptr;
}

int main()
{
	// NEVER MIX A RAW POINTER AND A SHARED POINTER
	// Auto reduces compile time
	auto sp = createEnemy();

	// increase the reference count by 1
	// Another pointer to the same resource
	// Makes a second strong reference in the heap, they all point to the same resource
	std::shared_ptr<Enemy> sp2 = sp;

	// Use this to delete pointers, removes the strong references (Brings the reference count back to 0) by calling the deconstructor
	sp2 = nullptr;
	sp = nullptr;

	// creation of a shared pointer
	// This is a safe way to create a pointer while avoiding memory leaks
	// You don't need to use new when making a shared pointer
	// Use this to manage the created int on the heap
	std::shared_ptr<int> sptr2 = std::make_shared<int>(100);
	std::cout << *sptr2 << "\n"; // print value
	// Print the reference count for the heap resource
	// Prints how many times it has been used
	std::cout << sptr2.use_count();

	// Shared pointers automatically count down to 0 when out of scope
	// This makes memory leaks much less likely as there is no chance of jumping out of a function before using delete on some memory

	
}
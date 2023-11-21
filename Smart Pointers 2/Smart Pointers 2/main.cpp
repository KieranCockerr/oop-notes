#include <iostream>

class EnemyBot
{
public:
	EnemyBot(std::string t_name) : m_name(t_name)
	{

	}

	~EnemyBot()
	{
		std::cout << "Deleting : " << m_name << "\n";
	}

	void setPartner(std::shared_ptr<EnemyBot> t_partner)
	{
		m_partner = t_partner;
	}

	std::string getName()
	{
		return m_name;
	}

	std::weak_ptr<EnemyBot> getPartner()
	{
		return m_partner;
	}

private:
	// Modify m_partner to type std::weak_ptr
	std::weak_ptr<EnemyBot> m_partner;
	std::string m_name;
};

void spawnBots()
{
	std::shared_ptr<EnemyBot> bigBot =
		std::make_shared<EnemyBot>("Bigbot");
	std::shared_ptr<EnemyBot> smallBot =
		std::make_shared<EnemyBot>("Smallbot");

	// Set a referance from bigbot to smallbot
	bigBot->setPartner(smallBot);
	int smallCount = smallBot.use_count();
	// Set a referance from smallbot to bigbot
	smallBot->setPartner(bigBot);
	int bigCount = bigBot.use_count();
	// Get a shared_ptr from a weak_ptr referance
	std::shared_ptr<EnemyBot> temp = smallBot->getPartner().lock();
	// Print the name of bigbot from the smallbot object
	std::cout << temp->getName();
}

int main()
{
	spawnBots();
}
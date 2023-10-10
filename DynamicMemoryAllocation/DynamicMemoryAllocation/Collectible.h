#pragma once

class Collectible
{
public:
    enum class Type
    {
        HealthPack, GoldCoin, SilverCoin, BronzeCoin
    };
    // Default construction possible
    Collectible(Type t_type = Type::HealthPack, int t_value = 0);
    //Destructor
    ~Collectible();
    
    int value() const;

    void setType(Type t_type);

    void setValue(int t_value);

    Collectible* generateCollectibles(int t_howMany); 
    
private:
    Type m_type;
    int m_value;
};


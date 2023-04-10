#include <vector>
#include "bfilter.h"
#include <math.h>

// (a)

class FirstHashFun: public HashFun
{
      unsigned int operator()(const std::string& key) {
        unsigned int sum=0;
       for (int i = 0; i < key.size(); i++)
        {
        sum = static_cast<int>(key[i]); 
        sum = (key.length() - i) * pow(31,i) + sum;
        }
        return sum;
    }
};

class SecondHashFun : public HashFun
{
    unsigned int operator()(const std::string& key)
    {
        unsigned int sum;
        int count = 1;
        for (int i = 0; i < key.length(); i++)
        {
            sum = static_cast<int>(key[i]);
            sum = (i * 33 - (i+33));
        }
        return sum;
          
    }
};

class ThirdHashFun : public HashFun
{
    unsigned int operator()(const std::string& key)
    {
        unsigned int sum;
        for (int i = 0; i < key.size(); i++)
        {
            sum = static_cast<int>(key[i]);
            sum = (sum * 7 + i);
        }
        return sum;
    }
};

    


void BloomFilter::add_hash_funs() {

    FirstHashFun *h1 = new FirstHashFun();
    SecondHashFun *h2 = new SecondHashFun();
    ThirdHashFun *h3= new ThirdHashFun();
    this->hash_funs.push_back(h1);
    this->hash_funs.push_back(h2);
    this->hash_funs.push_back(h3);

}

void BloomFilter::insert(const std::string& key) {

    for (int i = 0; i < hash_funs.size(); i++)
    {
        unsigned int hash_result = this->call_hash(i,key) % 330;
        (this->filter)[hash_result] = 1;
    }
}

bool BloomFilter::member(const std::string& key) {
    bool maybe = true;
    for (int i = 0; i < hash_funs.size(); i++)
    {
        int hash_check = this->call_hash(i,key) % 330;
        if ((this->filter)[hash_check] == 0)
        {
            maybe = false;
        }

    }
    return maybe; 
}

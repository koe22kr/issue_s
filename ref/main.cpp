#include <iostream>

class PlayerCharactor
{
private:
	enum {
		CharactorType = 5, InvSize = 30
	};
	bool Action(int type = CharactorType) {};
	int* inv[InvSize];
};



class Reftest
{
public:
	int value;
public:
	Reftest();
	Reftest( int a) 
	{
		value = a;
		std::cout << "create by int" << std::endl; 
	};
	
	Reftest(const Reftest& obj) 
	{
		value = obj.value;
		std::cout << "copy" << std::endl;
	}



	Reftest(Reftest&& obj) noexcept
	{ 
		value = obj.value;
		std::cout << "move" << std::endl; 
	};
	
	Reftest& operator =(const Reftest& obj)
	{
		this->value = obj.value;
		std::cout << "=" << std::endl;
		return *this;

	}

	~Reftest();

private:

};

Reftest::Reftest()
{
	value = 999;
	std::cout << "create default" << std::endl;
}

Reftest func(int i)
{
	
	return Reftest(i);
}

Reftest::~Reftest()
{
	std::cout << "remove" << std::endl;
}

int main()
{
	Reftest A, B;
	Reftest C=Reftest(10);
	Reftest x2 = std::forward<Reftest>(A);
	Reftest x = Reftest(func(10));
	x = A;
	return 0;
}
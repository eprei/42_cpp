#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << "The type of j is : " << j->getType() << std::endl;
	std::cout << "The type of i is : " << i->getType() << std::endl;
	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "makeSound() of the base class 'Animal' called through the derived pointer to class 'Dog'" << std::endl;
	j->Animal::makeSound();
	std::cout << std::endl;

	delete i;
	delete j;
	delete meta;

//	wrong animal example
	std::cout << std::endl;

	const WrongAnimal* metaWrong = new WrongAnimal();
	const WrongAnimal* wrongFelix = new WrongCat();

	std::cout << std::endl;
	std::cout << "The type of wrongFelix is : " << wrongFelix->getType() << " " << std::endl;

	std::cout << std::endl;
	wrongFelix->makeSound();
	wrongFelix->WrongAnimal::makeSound();
	metaWrong->makeSound();
	std::cout << std::endl;

	delete wrongFelix;
	delete metaWrong;

	return 0;
}

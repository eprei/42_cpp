#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	// This would NOT be ok because Animal is abstract
	// Animal test;

	int nOfAnimals = 6;
	Animal *group[nOfAnimals];

	NEW_LINE;
	for (int i = 0 ; i < nOfAnimals ; i++)
	{
		if (i % 2 == 0)
			group[i] = new Cat;
		else
			group[i] = new Dog;
	}
	NEW_LINE;
	for (int i = 0 ; i < nOfAnimals ; i++)
		group[i]->makeSound();
	NEW_LINE;
	for (int i = 0  ; i < nOfAnimals ; i++)
		delete group[i];

	NEW_LINE;
	std::cout << "=====> DOG BASIC CREATION"<< std::endl;
	NEW_LINE;

	Dog		basic;

	NEW_LINE;
	std::cout << "________________________\tDOG BASIC IDEAS\t	_____________________" << std::endl;
	NEW_LINE;
	for (int i = 0; i < 5 ; i++)
	{
		basic.getBrain()->setIdeas(i, "I hate that cat");
		std::cout << "Idea " << i << " of basic : " << basic.getBrain()->getIdeas(i) << "\t address of the idea : " << basic.getBrain()->getIdeasAddress(i) << std::endl;
	}
		NEW_LINE;
		std::cout << "=====> DOG CLONE CREATION" << std::endl;
		NEW_LINE;
	{
		Dog clone = basic;
		NEW_LINE;
		std::cout << "________________________\tDOG CLONE IDEAS\t	_____________________" << std::endl;
		NEW_LINE;
		for (int i = 0; i < 5 ; i++)
		{
			clone.getBrain()->getIdeas(i);
			std::cout << "Idea " << i << " of clone : " << clone.getBrain()->getIdeas(i) << "\t address of the idea : " << clone.getBrain()->getIdeasAddress(i) << std::endl;
		}
		NEW_LINE;
		std::cout << "_____________________\tDOG CLONE CHANGES ITS MIND\t_______________________" << std::endl;
		NEW_LINE;
		for (int i = 0; i < 5 ; i++)
		{
			clone.getBrain()->setIdeas(i, "Actually I think I love it");
			std::cout << "Idea " << i << " of clone : " << clone.getBrain()->getIdeas(i) << "\t address of the idea : " << clone.getBrain()->getIdeasAddress(i) << std::endl;
		}
	}
	NEW_LINE;
	std::cout << "________________________\tDOG BASIC IDEAS\t	_____________________" << std::endl;
	NEW_LINE;
	for (int i = 0; i < 5 ; i++)
		std::cout << "Idea " << i << " of basic : " << basic.getBrain()->getIdeas(i) << "\t address of the idea : " << basic.getBrain()->getIdeasAddress(i) << std::endl;
	NEW_LINE;

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:26:08 by darakely          #+#    #+#             */
/*   Updated: 2023/01/24 13:00:44 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "./Animal.hpp"
#include "./Cat.hpp"
#include "./Dog.hpp"

int main()
{
	std::cout << "____________ START ANIMAL ____________" << std::endl << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;
	
	std::cout << "____________ END ANIMAL ____________" << std::endl << std::endl;

	std::cout << "____________ START WRONGANIMAL ____________" << std::endl;

	const WrongAnimal* meta_1 = new WrongAnimal();
	const WrongAnimal* i_1 = new WrongCat();
	std::cout << i_1->getType() << " " << std::endl;
	i_1->makeSound();
	meta_1->makeSound();

	delete meta_1;
	delete i_1;
	
	std::cout << "____________ END WRONGANIMAL ____________" << std::endl;
	
	return 0;
}
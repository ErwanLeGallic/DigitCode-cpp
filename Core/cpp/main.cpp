/*
 * main_cpp.cpp
 *
 *  Created on: Oct 16, 2024
 *      Author: mathi
 */
#include <main.hpp>
#include <main.h>
#include <stdio.h>
#include "stm32l1xx_it.h"
#include "stm32l1xx_hal.h"
#include <string.h>


char new_psw, actual_psw;



void main_cpp(void){
	// User C++ code


	//code_bon(300);
	std::cout << "Entrez votre nouveau mot de passe : " <<std::endl;
	std::cin >> new_psw;
	if (sizeof(new_psw)==4){
		std::cout << "Code bien enregistre " <<std::endl;
		std::cout << "Entrez le mot de passe : " <<std::endl;
		std::cin >> actual_psw;
		if (actual_psw==new_psw){
			code_bon(500);
		}
}

	while(1) {
		//aff_message("non", 300);
	}
}



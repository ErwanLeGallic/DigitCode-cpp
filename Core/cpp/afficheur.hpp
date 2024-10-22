/*
 * afficheur.hpp
 *
 *  Created on: Oct 21, 2024
 *      Author: Acer Nitro RTX
 */

#ifndef CPP_AFFICHEUR_HPP_
#define CPP_AFFICHEUR_HPP_
#ifdef __cplusplus
#include <stdint.h>

class Afficheur{
	public:

	// attributs
	uint32_t MyDelay;



	// constructor
    Afficheur(uint32_t MyDelay);

    //destructeur
    ~Afficheur();


	// methodes
	void code_bon(uint32_t MyDelay);
	void ask_code(uint32_t MyDelay);
	void code_faux(uint32_t MyDelay);
};


#endif



#endif /* CPP_AFFICHEUR_HPP_ */

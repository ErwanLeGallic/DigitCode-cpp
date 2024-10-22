/*
 * afficheur.hpp
 *
 *  Created on: Oct 21, 2024
 *      Author: Acer Nitro RTX
 */

#ifndef CPP_AFFICHEUR_HPP_
#define CPP_AFFICHEUR_HPP_
#ifdef __cplusplus

class Afficheur{
	public:

	// attributs
	int MyDelay;


	// constructor
    Afficheur(int MyDelay);

    //destructeur
    ~Afficheur();



	// methodes
	void code_bon(int MyDelay);
	void ask_code(int MyDelay);
	void code_faux(int MyDelay);
};


#endif



#endif /* CPP_AFFICHEUR_HPP_ */

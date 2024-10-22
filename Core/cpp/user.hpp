/*
 * user.hpp
 *
 *  Created on: Oct 21, 2024
 *      Author: Acer Nitro RTX
 */

#ifndef CPP_USER_HPP_
#define CPP_USER_HPP_

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l1xx_hal.h"

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

class User {
public:
    // Attributs
    int root_code[4];
    int user_code[4];
    char final_code[5];
    int pos = 0;
    //int flag_btn;
    //int btn_trig;

    // Constructeur
    User(const int user_code[4]);

    // Destructeur
    ~User();
    // Méthodes
    char* code();
private:
    //void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
    void affiche_1(int pos);
    void affiche_2(int pos);
    void affiche_3(int pos);
    void affiche_4(int pos);
};

#endif

#endif /* CPP_USER_HPP_ */

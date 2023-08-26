/*
 * Macros.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Group D
				Mahmoud Sayed Mahmoud Helmy (1285)
				Seif Eldine Atef Shebl (894)
				Mohamed Mahmoud Masoud (200)
 */

/* =============================================================
 * 							File Guard
 * =============================================================*/
#ifndef MACROS_H_
#define MACROS_H_

/* =============================================================
 * 				 Function Like Macros
 * =============================================================*/

#define SET_BIT(REG,BIT)    (((REG)|= (1 << BIT)))
#define CLEAR_BIT(REG,BIT)  (((REG)&= ~(1 << BIT)))
#define TOGGLE_BIT(REG,BIT) (((REG) ^= (1 << BIT)))
#define GET_BIT(REG,BIT)    ((((REG & (1<<BIT)) >> BIT)))

#endif /* MACROS_H_ */

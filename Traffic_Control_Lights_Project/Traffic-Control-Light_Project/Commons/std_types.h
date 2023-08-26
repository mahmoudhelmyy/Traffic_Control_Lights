/*
 * std_types.h
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
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*
 * Boolean datatype
 */
typedef unsigned char boolean;
/*
 * Boolean Values
 */
#ifndef FALSE
#define FALSE 			 (0u)
#endif
#ifndef TRUE
#define TRUE 			 (1u)
#endif
/* =============================================================
 * 							Definitions
 * =============================================================*/
#define LOGIC_HIGH       (1u)
#define LOGIC_LOW        (0u)

#define NULL_PTR            ((void*)0)
typedef unsigned char         uint8;         
typedef signed char           sint8;         
typedef unsigned short        uint16;        
typedef signed short          sint16;        
typedef unsigned long         uint32;        
typedef signed long           sint32;        
typedef unsigned long long    uint64;        
typedef signed long long      sint64;        
typedef float                 float32;
typedef double                float64;

#endif /* STD_TYPES_H_ */

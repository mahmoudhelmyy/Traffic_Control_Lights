# Traffic Control Lights Project

This project implements a traffic control system using LEDs, buttons, and an LCD display. It simulates the interaction between pedestrian and car traffic signals.


## Table of Contents
- [Project Overview](#project-overview)
- [Setup Instructions](#setup-instructions)
- [Usage](#usage)
- [System Architecture](#system-architecture)
- [User Stories](#user-stories)
- [Folder Structure](#folder-structure)
- [Contributing](#contributing)![image](https://github.com/mahmoudhelmyy/Traffic_Control_Lights/assets/52659572/9c575043-cb2f-4b80-afaa-d745c58ca00d)
- [License](#license)

## Project Overview

The Traffic Control Lights Project is designed to control the traffic signals for cars and pedestrians, providing a safe way for pedestrians to cross the street. The project involves LED drivers, button drivers, and LCD display drivers.

## MISRA Compliance

This project adheres to the MISRA coding rules to ensure code safety, readability, and maintainability.

## Usage

When the system is powered on, it alternates between cars and pedestrian traffic signals. Pressing the pedestrian button during the appropriate time will activate the pedestrian signal and allow safe crossing.

## System Architecture

The project follows a layered architecture:
![image](https://github.com/mahmoudhelmyy/Traffic_Control_Lights/assets/52659572/f17224ae-2c58-4ab3-810a-4f9d2ed6a7a0)

## User Stories

### User Story 1
As a pedestrian, when I press the Pedestrian button while the cars' green light is on and the LCD says "Cars," I will wait for the yellow light to blink for five seconds. Then the cars' red light will be on, the pedestrian Blue light will be on for five seconds, and the LCD will say "Pedestrian," allowing me to cross the street.

### User Story 2
As a pedestrian, when I press the Pedestrian button while the cars' yellow light is blinking and the LCD says "Cars," I will wait for the yellow LED to blink for five seconds. Then the cars' red light will be on, the pedestrian Blue light will be on for five seconds, and the LCD will say "Pedestrian," allowing me to cross the street.

### User Story 3
As a pedestrian, if I press the Pedestrian button while the cars' red light is on and the pedestrian Blue light is on, nothing is expected to happen.

### User Story 4
As a pedestrian, when I press the Pedestrian button while the cars' red light is on and the LCD says "Cars," I will wait for the Blue LED to be on for five seconds. Then the LCD will say "Pedestrian," allowing me to cross the street.

## Folder Structure
![image](https://github.com/mahmoudhelmyy/Traffic_Control_Lights/assets/52659572/a5cc0aba-e377-48ef-b224-f08c27166bd0)



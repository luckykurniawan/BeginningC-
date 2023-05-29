#pragma once

#include <iostream>
#include <random>
#include <chrono>
#include <thread>

enum Difficulty { Easy = 1, Normal, Hard };

class Chapter2
{
public:
	Chapter2();
	void startExercise1();
	void startExercise3();

	void startGuessMyNumber();
};


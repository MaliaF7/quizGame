/*
    Malia Fairbanks
    CPSC 1020, 9:05 Class
    Prof. Dan Wooster
    March 9, 2023
    A program that shuffles questions
    and gives you your final score
*/

// all of my includes
#include "Quiz.h"
#include "printResult.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

std:: string printResult (int questions, int correct, int incorrect);

// main function
int main (int argc, char *argv[]) {
    // declare some variables
    std::string inputAnswer;
    int numOfQuestions =0;
    int correctCounter =0;
    int incorrectCounter =0;

    // create quiz vector, input file
    std::vector <Quiz> quizVector;
    std::ifstream inputFile(argv[1]);

    // if the file doesn't open, throw an error (basically if someone forgets to put it)
    if (!inputFile) {
        std::cout << "Error: could not open input file\n";
        return 1;
    }

    // go through the input file and find question and answers
    std::string line, question, answer;
    while (std::getline(inputFile, line)) {
        if (line[0] == 'Q') {
            question = line.substr(3);
        } else if (line[0] == 'A') {
            answer = line.substr(3);
            quizVector.emplace_back(question, answer);
            question.clear();
            answer.clear();
        }
    }

    // setting up random seed and shuffling quizVector
    srand(unsigned(time(0)));
    std::random_shuffle(quizVector.begin(), quizVector.end());

    // loop through questions and scan in answers
    for (const auto &quiz : quizVector){
        std::cout << quiz.getQuestion() << std::endl;
        std::cout << "Type in your answer: ";
        std::getline(std::cin, inputAnswer);

        // if answer is correct, give a point, increase correct number
        if (inputAnswer == quiz.getAnswer()) {
            std::cout << "Correct!" << std::endl;
            Quiz::updateScore(1);
            std::cout <<"Current score: "<< Quiz::getScore()<< std::endl <<std::endl;
            correctCounter++;
        }

        // if answer is incorrect, deduct a point, increase wrong number
        else {
            std::cout << "Wrong! Correct answer: " << quiz.getAnswer() << std::endl;
            Quiz::updateScore(-1);
            std::cout <<"Current score: "<< Quiz::getScore()<< std::endl << std::endl;
            incorrectCounter++;
        }

        // increase counter for number of questions
        numOfQuestions++;

    }
    
    // send numbers to print results, have it output them
    std::cout << printResult(numOfQuestions, correctCounter, incorrectCounter);
    return 0;

}


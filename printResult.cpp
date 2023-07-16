#include "printResult.h"
#include "Quiz.h"

std::string printResult(int q, int c, int w){
    int score = Quiz::getScore();
    std::stringstream finalResult;
    finalResult << "Number of questions: " << q << std::endl
                << "Number correct answers: "<< c << std::endl
                << "Number wrong answers: "<< w << std::endl
                << "Final score: " << score << std::endl;
    return finalResult.str();
}
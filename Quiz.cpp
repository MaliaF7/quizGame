#include "Quiz.h"

// all of my member functions 
int Quiz::score{0};

std::string Quiz::getQuestion() const{
    return question;
}

std::string Quiz::getAnswer() const{
    return answer;
}

int Quiz::getScore(){
    return score;
}

void Quiz::updateScore(int val){
    score += val; // add score, whether positive or negative
    // cannot get a negative score
    if (score < 0) {
        score = 0;
    }
}
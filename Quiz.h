#ifndef QUIZ_H
#define QUIZ_H
#include <string>
#include <iostream>

// my quiz class
class Quiz {
    private:
        std::string question = "";
        std::string answer = "";
        static int score;
    public:
        Quiz () {};
        Quiz (std::string q, std::string a ) : question(q), answer(a) {};
        std::string getQuestion() const;
        std::string getAnswer() const;
        static int getScore();
        static void updateScore(int val);
        friend std::string printResult(int question, int correct, int wrong); // make it friendly :)

};


#endif
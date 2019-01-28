#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Players { //this class creates the players
    private:
        string playerName;
        int playerScore;
        
    public:
        Players() {
            playerName;
            playerScore = 0;
        }
      
        Players(string name, int score) {
            playerName = name;
            playerScore = score;
        }
      
        friend ostream& operator<<(ostream &output, const Players &p ) {
            // Finish me thrid by adding proper output << statement
	        output << "   " << p.playerName << endl;
	        output << "   " << p.playerScore << endl;
	
	        return output;
        }
        
        string getName()  {
            return playerName;
        }
      
        int getPlayerScore()  {
            return playerScore;
        }
      
        void setPlayerName(string name) {
            playerName = name;
        }
      
        void setPlayerScore(int score) {
            playerScore = score;
        }
    
};

class Question  { //this class creates questions one at a time
    
    private:
        string question;
        string answer1;
        string answer2;
        string answer3;
        string answer4;
        int correctAnswer;
        int dollarAmount;
        int usage; //check if question has been used
        
    public:
        Question()  {
            question;
            answer1;
            answer2;
            answer3;
            answer4;
            correctAnswer = 0;
            dollarAmount = 0;
            usage = 0;
        }
      
        Question(string q1, string ans1, string ans2, string ans3, string ans4, int correctAns, int amountDollar, int usageq) {
            question = q1;
            answer1 = ans1;
            answer2 = ans2;
            answer3 = ans3;
            answer4 = ans4;
            correctAnswer = correctAns;
            dollarAmount = amountDollar;
            usage = usageq;
        }
      
        friend ostream& operator<<(ostream &output, const Question &q ) {
            cout << "\n   ----------------------------------------------\n";
            output << "       For $" << q.dollarAmount << " ..." << endl;
	        output << "           " << q.question << endl;
	        output << "               " << q.answer1 << endl;
	        output << "               " << q.answer2 << endl;
	        output << "               " << q.answer3 << endl;
	        output << "               " << q.answer4 << endl;
	        cout << "   ----------------------------------------------\n";
	        //output << "   " << q.dollarAmount << endl;
	        //output << "   " << q.correctAnswer << endl;
	        cout << endl;
	  
	        return output;
        }
      
        string getQuestion()  {
            return question;
        }
      
        string getAnswer1()  {
            return answer1;
        }
      
        string getAnswer2()  {
            return answer2;
        }
      
        string getAnswer3()  {
            return answer3;
        }
      
        string getAnswer4()  {
            return answer4;
        }
      
        int getCorrectAnswer()  {
            return correctAnswer;
        }
      
        int getDollarAmount()  {
            return dollarAmount;
        }
        
        int getUsage()  {
            return usage;
        }
      
        void setQuestion(string q1) {
            question = q1;
        }
      
        void setAnswer1(string ans1) {
            answer1 = ans1;
        }
      
        void setAnswer2(string ans2) {
            answer2 = ans2;
        }
      
        void setAnswer3(string ans3) {
            answer3 = ans3;
        }
      
        void setAnswer4(string ans4) {
            answer4 = ans4;
        }
      
        void setCorrectAnswer(int correctAns) {
            correctAnswer = correctAns;
        } 
      
        void setDollarAmount(int amountDollar)  {
            dollarAmount = amountDollar;
        }
        
        void setUsage(int usageq) {
            usage = usageq;
        }
};

class PlayGame {
    
    private:
        Players Player1;
        Players Player2;
        Players Player3;
        Players Player4;
        
    public: 
        PlayGame()  {
            
            Player1.setPlayerScore(0);
            Player2.setPlayerScore(0);
            Player3.setPlayerScore(0);
            Player4.setPlayerScore(0);
        }
        
        PlayGame(Question q1, Players p1, Players p2, Players p3, Players p4) {
            
            Player1.setPlayerScore(p1.getPlayerScore()); 
            Player2.setPlayerScore(p2.getPlayerScore()); 
            Player3.setPlayerScore(p3.getPlayerScore()); 
            Player4.setPlayerScore(p4.getPlayerScore());
        }
      
        Players getPlayer1()  {
          
            return Player1;
        }
      
        Players getPlayer2()  {
          
             return Player2;
        }
      
        Players getPlayer3()  {
          
            return Player3;
        }
              
        Players getPlayer4()  {
          
            return Player4;
        }
      
      
        //***************************************************************************************************************************************************************************************
        void Instructions()  { //this function displays the instructions for the game
          
            cout << R"(
            __          __    _                                  _                 _                                      _         _ 
            \ \        / /   | |                                | |               | |                                    | |       | |
             \ \  /\  / /___ | |  ___  ___   _ __ ___    ___    | |_  ___         | |  ___   ___   _ __    __ _  _ __  __| | _   _ | |
              \ \/  \/ // _ \| | / __|/ _ \ | '_ ` _ \  / _ \   | __|/ _ \    _   | | / _ \ / _ \ | '_ \  / _` || '__|/ _` || | | || |
               \  /\  /|  __/| || (__| (_) || | | | | ||  __/   | |_| (_) |  | |__| ||  __/| (_) || |_) || (_| || |  | (_| || |_| ||_|
                \/  \/  \___||_| \___|\___/ |_| |_| |_| \___|    \__|\___/    \____/  \___| \___/ | .__/  \__,_||_|   \__,_| \__, |(_)
                                                                                                  | |                         __/ |   
                                                                                                  |_|                        |___/    )" << endl << endl;
            cout << "Thanks for playing! This game is meant to be played with multiple people, but if you dont have a partner don't worry, you will have the option of \n"
                  "an AI player if you so desire. The rules are simple: pick a catogory, pick a dollar amount, and answer it. Everyonr starts off with zero dollars, \n" 
                  "and if you get the question right, the dollar questionAmount will be added to your score. However, if you get the question wrong, you will have the dollar \n"
                  "amount subtracted from your score. To get started, pick the number of players. You can choose up to 4 players. It is advised you play the game in full screen.\n\n"
                  "*******************************************************************************************************************************************************"<< endl << endl;
            cout << "Follow the onscreen instructions to get started ...  \n\n";
                  
            return;
        }

        //****************************************************************************************************************************************************************************************
        int numberPlayers()  { // this functions tells the user to choose the number of platers playing
          
            int numPlayers; // this is the number of players in the game. The game supports (1-4) player
          
            cout << "    1. To set the number of players, enter the number of players (1-4): ";
            cin >> numPlayers; // user inputs the number of players
            //cout << endl;
          
            do  {
                if ((numPlayers > 4 ) || (numPlayers < 1))  { // checks if the number of players is between (1-4)
                    cout << "    ERROR: Number not in range! \n";
                    cout << "    Enter the number of players again (1-4): ";
                    cin >> numPlayers; // user inputs the number of players
                    cout << endl;
                }
            } while ((numPlayers < 1) || (numPlayers > 4)); // if it is not between (1-4) it has the user enter the number of players again
          
          
            if (numPlayers == 1) { // if there is only one human playing, he/she will play against the computer
                cout << "---> PLEASE NOTE: The Computer will take the place of player 2!! <---" << endl << endl; 
            }
          
            return numPlayers;
        }
        
        //*****************************************************************************************************************************************************************************************
        string FileUploader(int c) { // this is called when the user wants to upload thier own files
          
            string fileName;
            int txtIsMissing;
            bool check = false;

            do  {
                if (c == 1) {
                    cout << endl << "           1. Enter the name of the question file to upload (include .txt): ";
                }else {
                    cout << "           2. Enter the name of the answer file to upload (include .txt): ";

                }
                cin >> fileName;
                cout << endl;
                txtIsMissing = fileName.find("txt");
                
                // checks if user included ".txt"
                if (txtIsMissing == string::npos)  {
                    check = false;
                    cout << "           ERROR: You forgot to add the file extension (.txt)!" << endl;
                }else  {
                    check = true;
                }
            } while (check == false);
            
            return fileName;
        }
        
        //*****************************************************************************************************************************************************************************************
        int ChooseCategory(int numPlayers, int n, int categoryNumb) { // this function has the user choose a category
            
            if ((numPlayers == 1) && (n == 2)) { // When it's the computers turn, it randomly chooses a category
                //cout << "   It's the computers turn ... \n";
                //cout << "       The computer chose category: ";
                categoryNumb = rand() % 5 + 1;
                //cout << categoryNumb << endl;
                
            } else { // When it's a human's turn
                cout << "   To pick a question ... \n";
                do {
                    cout << "       Enter the number associated with the category (1-5): ";
                    cin >> categoryNumb;
                    
                    if ((categoryNumb > 5 ) || (categoryNumb < 0))  { // if the human players answer is not in range
                        cout << "       ERROR: Number not in range! Try again!" << endl << endl;
                    }
                    
                } while ((categoryNumb < 1) || (categoryNumb > 5));
            }
            return categoryNumb;
        }
        
        //*****************************************************************************************************************************************************************************************
        int ChooseQuestion(int questionAmount, int itt, int check, int numPlayers, int n) { // This function has the user choose a question
            
            int amount1[5];
            amount1[0] = 200;
            amount1[1] = 400;
            amount1[2] = 600;
            amount1[3] = 800;
            amount1[4] = 1000;
            if ((numPlayers == 1) && (n == 2)) { // When it's the computers turn, it randomly chooses a question
                //cout << "       The computer chose question: ";
                srand(time(NULL));
                itt = rand() % 5;
                
                questionAmount = amount1[itt];
                //cout << questionAmount << endl;  
                
            } else { // When its a humans turn
                do {
                    cout << "       Enter the dollar questionAmount (200 - 1000): ";
                    cin >> questionAmount;
                    cout << endl;
            
                    if ((questionAmount == 200) || (questionAmount == 400) || (questionAmount == 600) || (questionAmount == 800) || (questionAmount == 1000)) {
                        check = 1;
            
                    } else {
                        cout << "       ERROR: Number not in range! Try again!" << endl;
                        check = 0;
                    }
                    
                } while (!(check == 1));
            }
            
            return questionAmount;
        }
        
        //*****************************************************************************************************************************************************************************************
        int ChooseAnswer(int numPlayers, int n, int playerAnswer) { // this function has the user choose an answer
            
            if ((numPlayers == 1) && (n == 2)) { // When it's the computer's turn. a random answer is generated                      
                //cout << "   Player2's answer: ";
                playerAnswer = rand() % 4 + 1;
                //cout << playerAnswer << endl;
                
            } else { // When it's a human's turn, the user inputs their answer
            
                do { // do until the humans answer is in range (1-4)
                    cout << "   Enter Answer (1-4): ";
                    cin >> playerAnswer;
                
                    if ((playerAnswer > 4 ) || (playerAnswer < 0))  { // if the human players answer is not in range
                        cout << "   ERROR: Number not in range! Try again!" << endl << endl;
                    }
                    
                } while ((playerAnswer < 1) || (playerAnswer > 4));
            }
            return playerAnswer;
        }
        
        //*****************************************************************************************************************************************************************************************
        void scoreCalculator(int numPlayers1, int updateScore, int currentPlayer) { //This function updates the players score
          
            if (currentPlayer == 1)  { // update player1's score
                Player1.setPlayerScore(Player1.getPlayerScore() + updateScore);
              
            } else if (currentPlayer == 2)  { // update player2's score
                Player2.setPlayerScore(Player2.getPlayerScore() + updateScore);

            } else if (currentPlayer == 3)  { // update player2's score
                Player3.setPlayerScore(Player3.getPlayerScore() + updateScore);

            } else if (currentPlayer == 4)  { // update player2's score
                Player4.setPlayerScore(Player4.getPlayerScore() + updateScore);

            } else { } //if their is no points to add to the score, the score does not change
          
            cout << "   ------------------------------------------------------------------------\n";
          
            if ((numPlayers1 == 2) || (numPlayers1 == 1)) { // If there is only two players in the game only their score will be updated
                cout << "      Current Player's Score: " << endl;
                cout << "          Player1: $" << Player1.getPlayerScore() << endl;
                cout << "          Player2: $" << Player2.getPlayerScore() << endl << endl;
              
            }else if (numPlayers1 == 3) { // if there is three players in the game only their score will be updated
                cout << "    Current Player's Score: " << endl;
                cout << "        Player1: $" << Player1.getPlayerScore() << endl;
                cout << "        Player2: $" << Player2.getPlayerScore() << endl;
                cout << "        Player3: $" << Player3.getPlayerScore() << endl << endl;
                
            } else if (numPlayers1 == 4) { // if there is four players in the game only their score will be updated
                cout << "    Current Player's Score: " << endl;
                cout << "        Player1: $" << Player1.getPlayerScore() << endl;
                cout << "        Player2: $" << Player2.getPlayerScore() << endl;
                cout << "        Player3: $" << Player3.getPlayerScore() << endl;
                cout << "        Player4: $" << Player4.getPlayerScore() << endl << endl;
            }
          
            return;             
        }
      
        //****************************************************************************************************************************************************************************************
        bool checkAnswer(int actualAnswer, int playerAnswer)  {  // This function checks if the answer the user gave was right or wrong
      
            if (playerAnswer == actualAnswer)  { // if the answer is right return true
                cout << "   You answered the question correctly!" << endl << endl;
                return true;
                    
            } else { // if the answer is wrong return false
                cout << "   You answered the question incorrectly!!" << endl << endl;
                return false;
            }
        }
      
        // ******************************************************************************************************************************************************************************************
        void grid(int qNmber, int categoryNumb, vector <string> dollarValuesCat1, vector <string> dollarValuesCat2, vector <string> dollarValuesCat3, vector <string> dollarValuesCat4, vector <string> dollarValuesCat5 )  { // this function updates te the question board
          
            cout << "     Questions left to choose from: \n";
            cout << "     _______________________________________________________ \n";
            cout << "     |category1  category2  category3  category4  category5|\n";
          
            for (int i = 0; i < dollarValuesCat1.size(); i++)  {
              
                if (i < 4) {
                    cout << "     |  " << dollarValuesCat1[i] << "        " << dollarValuesCat2[i] << "        " << dollarValuesCat3[i] << "        " << dollarValuesCat4[i] << "        " << dollarValuesCat5[i] << "    |" <<endl;
              
                } else {
                    cout << "     | " << dollarValuesCat1[i] << "       " << dollarValuesCat2[i] << "       " << dollarValuesCat3[i] << "       " << dollarValuesCat4[i] << "       " << dollarValuesCat5[i] << "    |" << endl;
                }
            }
            cout << "     |_____________________________________________________| \n\n";

        }
      
        // ******************************************************************************************************************************************************************************************
        void playGame()  { // this is where everthing is called from
            
            Question AllQuestions25[25]; // 25 questions
            
            Instructions(); // calls the function to output the instructions
    
            int numPlayers = numberPlayers(); // calls the function to prompt the number of players
            
            int choice;
            
            cout << "    2. To play preloaded game (enter 1) ...\n        to upload set of questions (enter 2): ";
            cin >> choice;
            
            do  {
                if ((choice > 2 ) || (choice < 1))  { // checks if the number of players is between (1-4)
                    cout << "    ERROR: Number not in range! \n";
                    cout << "    Enter the number again (1-2): ";
                    cin >> choice; // user inputs the number of players
                    cout << endl;
                }
            } while ((choice < 1) || (choice > 2)); // if it is not between (1-4) it has the user enter the number of players again
            
            string fileName = "questions.txt";
            string fileAnswer = "answers.txt";
            
            if (choice == 2) {
                cout << "   ------------------------------------------------------------------------\n";
                cout << "\n       You have entered game the game file uploader ...";
                fileName = FileUploader(1); // asks the user to choose if they want to use preloaded question or if they want to upload their own
                fileAnswer = FileUploader(2);
            }
          
          
          
          
            // FOR QUESTIONS FILE
            // CHECKS IF THE USER ENTERED FILE OPENS
            ifstream inputFile(fileName);
            if (!inputFile) {
                cout << "  ERROR: File failed to open. You misspelled the file name or file does not exist." << endl << "  The program will quit and you will have to try again!";
                return;
                //return;

            }else  {
                cout << "            CONGRATS: File is open!" << endl;
            }
        
            // MAKES EACH LINE OF THE FILE INTO A STRING
            vector <string> questionsANDAns; //creates a vector of strings to encrypt
            string lines;
          
            while (getline(inputFile, lines)) {
                questionsANDAns.push_back(lines);
            }
          
            //outputs the strings read in the file
            cout << "            Strings Read in the file " << fileName << ": " << questionsANDAns.size() << endl << endl;
            
            
            // FOR QUESTIONS FILE
            // CHECKS IF THE USER ENTERED FILE OPENS
            ifstream inputFile2(fileAnswer);
            if (!inputFile2) {
                cout << "  ERROR: File failed to open. You misspelled the file name or file does not exist." << endl << "  The program will quit. Please try again!";
                return;
            }else  {
                cout << "            CONGRATS: File is open!" << endl;
            }
        
            // MAKES EACH LINE OF THE FILE INTO A STRING
            vector <int> Ans; //creates a vector of strings to encrypt
            int lines2;
          
            while (inputFile2 >> lines2) {
                Ans.push_back(lines2);
            }
          
            //outputs the strings read in the file
            cout << "            Strings Read in the file " << fileAnswer << ": " << Ans.size() << endl << endl;
            
            int s = 0;
            int dollaramountCount = 200;
            
            for (int i = 0; i < 25; i++){  // assigns the question, answers, and score to each oject 
                AllQuestions25[i].setCorrectAnswer(Ans[i]);
                AllQuestions25[i].setDollarAmount(dollaramountCount);
                AllQuestions25[i].setQuestion(questionsANDAns[s]);
                AllQuestions25[i].setAnswer1(questionsANDAns[s+1]);
                AllQuestions25[i].setAnswer2(questionsANDAns[s+2]);
                AllQuestions25[i].setAnswer3(questionsANDAns[s+3]);
                AllQuestions25[i].setAnswer4(questionsANDAns[s+4]);
                
                dollaramountCount = dollaramountCount + 200;
                if (dollaramountCount == 1200) { //resets the dollar questionAmount to 200 if it exceeds 1000
                    dollaramountCount = 200;
                }
                s = s + 4;
               
               // cout << AllQuestions25[i];
                s++;
            }
          
            scoreCalculator(numPlayers, 0, 0); // calls the function to display the score
            //vectors for the question board: assigns category with quesstions
            vector <string> dValuesCat1 = {"200", "400", "600", "800", "1000"};
            vector <string> dValuesCat2 = {"200", "400", "600", "800", "1000"};
            vector <string> dValuesCat3 = {"200", "400", "600", "800", "1000"};
            vector <string> dValuesCat4 = {"200", "400", "600", "800", "1000"};
            vector <string> dValuesCat5 = {"200", "400", "600", "800", "1000"};
          
            grid(0,0,dValuesCat1, dValuesCat2, dValuesCat3, dValuesCat4, dValuesCat5); // calls the function to display the question grid
            cout << "\nSetup complete!\n";
            cout << "*******************************************************************************************************************************************************\n\n";
          
            int questionAmount = 0;
            int categoryNumb = 0;
            int correctAnswer;
            int currentPlayer = 0;
            int questionPoints = 0;
            int playerAnswer = 0; // the user's inputed answer
            int check = 0;
            int n = 1; // updates the player number
            int counter2;
            
            // goes question by questionturn by turn
            for (int i = 0; i < 25; i++)  { 
            
                cout << "PLAYER " << n << "'S TURN: \n\n";  //displays whoes turn it is
                currentPlayer = n;
                
                int itt;
                int counter = 0; 
                
                do {
                    categoryNumb = ChooseCategory(numPlayers, n, categoryNumb); // asks the user to pick a category
                    questionAmount = ChooseQuestion(questionAmount, itt, check, numPlayers, n); // asks the user to pick a question
                

                
                    if (questionAmount == 200)  {
                        counter = 0;//counter for question object
                        counter2 = 0; //counter for question board
                    } else if (questionAmount == 400)  {
                        counter = 1;
                        counter2 = 1;
                    } else if (questionAmount == 600)  {
                        counter = 2;
                        counter2 = 2;
                    } else if (questionAmount == 800)  {
                        counter = 3;
                        counter2 = 3;
                    } else if (questionAmount == 1000)  {
                        counter = 4;
                        counter2 = 4;
                    }
                    if (categoryNumb == 2) {
                        counter = counter + 5;
                    } else if (categoryNumb == 3) {
                        counter = counter + 10;
                    } else if (categoryNumb == 4) {
                        counter = counter + 15;
                    } else if (categoryNumb == 5) {
                        counter = counter + 20;
                    }
                    
                    if ((numPlayers == 1) && (n == 2)) { // When it's the computer's turn. a random answer is generated      
                    } else {
                        cout << AllQuestions25[counter]; //outputs the questions per turn
                        if (((AllQuestions25[counter].getUsage()) == 1)) {
                            cout << "   ERROR: Question has been picked, choose another question...\n";
                        }
                    }
                    
                    correctAnswer = AllQuestions25[counter].getCorrectAnswer();// sets correctAnswer to the actual answer so it can be checked in a later function
                    questionPoints = AllQuestions25[counter].getDollarAmount();// sets questionPoints to the question currenty in use 
                    

                    
                }while ((AllQuestions25[counter].getUsage()) == 1); //prevent the same question from being answered
                
                if ((numPlayers == 1) && (n == 2)) { // When it's the computer's turn. a random answer is generated
                    cout << "   It's the computers turn ... \n";
                    cout << "       The computer chose category: ";
                    cout << categoryNumb << endl;
                    cout << "       The computer chose question: ";
                    cout << questionAmount << endl;  
                    cout << AllQuestions25[counter];
                    cout << "   Player2's answer: ";
                    cout << playerAnswer << endl;
                    
                }

                
                AllQuestions25[counter].setUsage(1);

                playerAnswer = ChooseAnswer(numPlayers, n, playerAnswer); // asks the user to pick an answer
                
                if (checkAnswer(correctAnswer, playerAnswer) == false)  { // if the user answer is wrong, the points are subtracted from the current playes score
                    scoreCalculator(numPlayers, -questionPoints, currentPlayer);
                    
                } else if (checkAnswer(correctAnswer, playerAnswer) == true) { // if the points are correct, the points are added to the current players score
                    scoreCalculator(numPlayers, questionPoints, currentPlayer);
                    
                }
                
                if (categoryNumb == 1){
                    if (questionAmount == 1000) {
                        dValuesCat1[counter2] = "----"; // updates the question board (grid)
                    } else {
                        dValuesCat1[counter2] = "---"; // updates the question board (grid)
                    }
                }else if (categoryNumb == 2){
                    if (questionAmount == 1000) {
                        dValuesCat2[counter2] = "----"; // updates the question board (grid)
                    } else {
                        dValuesCat2[counter2] = "---"; // updates the question board (grid)
                    }
                } else if (categoryNumb == 3){
                    if (questionAmount == 1000) {
                        dValuesCat3[counter2] = "----"; // updates the question board (grid)
                    } else {
                        dValuesCat3[counter2] = "---"; // updates the question board (grid)
                    }
                } else if (categoryNumb == 4){
                    if (questionAmount == 1000) {
                        dValuesCat4[counter2] = "----"; // updates the question board (grid)
                    } else {
                        dValuesCat4[counter2] = "---"; // updates the question board (grid)
                    }
                } else if (categoryNumb == 5){
                    if (questionAmount == 1000) {
                        dValuesCat5[counter2] = "----"; // updates the question board (grid)
                    } else {
                        dValuesCat5[counter2] = "---"; // updates the question board (grid)
                    }
                }
                
                //calls the question board
                grid(questionAmount, categoryNumb, dValuesCat1, dValuesCat2, dValuesCat3, dValuesCat4, dValuesCat5); //shows the question board after each turn
                cout << "*******************************************************************************************************************************************************\n\n";
                
                //switch between players 
                n = n + 1;
                if (numPlayers == 1) {
                    if (n == (numPlayers + 2)) {
                        n = 1;
                    }
                } else {
                    if (n == (numPlayers + 1)) {
                        n = 1;
                    }
                }
            }
            // assigns the player score to varables so it will be easier to access later on
            int player1Final = Player1.getPlayerScore();
            int player2Final = Player2.getPlayerScore();
            int player3Final = Player3.getPlayerScore();
            int player4Final = Player4.getPlayerScore();
            
            // chooses a winner
            if ((player1Final > player2Final) && (player1Final > player3Final) && (player1Final > player4Final)) {
                cout << "CONGRATULATIONS!! PLAYER1 IS THE WINNER!!!";
            }else if ((player2Final > player1Final) && (player2Final > player3Final) && (player2Final > player4Final)) {
                cout << "CONGRATULATIONS!! PLAYER2 IS THE WINNER!!!";
            }else if ((player3Final > player1Final) && (player3Final > player2Final) && (player3Final > player4Final)) {
                cout << "CONGRATULATIONS!! PLAYER3 IS THE WINNER!!!";
            }else if ((player4Final > player1Final) && (player4Final > player2Final) && (player4Final > player3Final)) {
                cout << "CONGRATULATIONS!! Player4 IS THE WINNER!!!";
            }
        }
};


int main() {
    cout << endl;
    PlayGame Start;
    
    Start.playGame();
    
    return 0;
}
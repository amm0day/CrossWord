// CPP code to fill the crossword puzzle 
#include <bits/stdc++.h> 
using namespace std; 
  
// ways are to calculate the number of 
// possible ways to fill the grid 
int ways = 0; 
  
// this function is used to print 
// the resultant matrix 
void printMatrix(vector<string>& matrix, int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << matrix[i] << endl; 
} 
  
// this function checks for the current word 
// if it can be placed horizontally or not 
// x -> it represent index of row 
// y -> it represent index of column 
// currentWord -> it represent the 
// current word in word array 
vector<string> checkHorizontal(int x, int y, 
                               vector<string> matrix, 
                               string currentWord) 
{ 
    int n = currentWord.length(); 
  
    for (int i = 0; i < n; i++) { 
        if (matrix[x][y + i] == '#' ||  
            matrix[x][y + i] == currentWord[i]) { 
            matrix[x][y + i] = currentWord[i]; 
        } 
        else { 
  
            // this shows that word cannot  
            // be placed horizontally 
            matrix[0][0] = '@'; 
            return matrix; 
        } 
    } 
  
    return matrix; 
} 
  
// this function checks for the current word 
// if it can be placed vertically or not 
// x -> it represent index of row 
// y -> it represent index of column 
// currentWord -> it represent the 
// current word in word array 
vector<string> checkVertical(int x, int y, 
                             vector<string> matrix, 
                             string currentWord) 
{ 
    int n = currentWord.length(); 
  
    for (int i = 0; i < n; i++) { 
        if (matrix[x + i][y] == '#' ||  
            matrix[x + i][y] == currentWord[i]) { 
            matrix[x + i][y] = currentWord[i]; 
        } 
        else { 
  
            // this shows that word 
            // cannot be placed vertically 
            matrix[0][0] = '@'; 
            return matrix; 
        } 
    } 
    return matrix; 
} 
  
// this function recursively checks for every 
// word that can align vertically in one loop 
// and in another loop it checks for those words 
// that can align horizontally words -> it 
// contains all the words to fill in a crossword 
// puzzle matrix -> it contain the current 
// state of crossword index -> it represent 
// the index of current word n -> it represent 
// the length of row or column of the square matrix 
void solvePuzzle(vector<string>& words, 
                 vector<string> matrix, 
                 int index, int n) 
{ 
    if (index < words.size()) { 
        string currentWord = words[index]; 
        int maxLen = n - currentWord.length(); 
  
        // loop to check the words that can align vertically. 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j <= maxLen; j++) { 
                vector<string> temp = checkVertical(j, i, 
                                        matrix, currentWord); 
  
                if (temp[0][0] != '@') { 
                    solvePuzzle(words, temp, index + 1, n); 
                } 
            } 
        } 
  
        // loop to check the words that can align horizontally. 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j <= maxLen; j++) { 
                vector<string> temp = checkHorizontal(i, j, 
                                      matrix, currentWord); 
  
                if (temp[0][0] != '@') { 
                    solvePuzzle(words, temp, index + 1, n); 
                } 
            } 
        } 
    } 
    else { 
        // calling of print function to 
        // print the crossword puzzle 
        cout << (ways + 1) << " way to solve the puzzle "
             << endl; 
        printMatrix(matrix, n); 
        cout << endl; 
  
        // increase the ways 
        ways++; 
        return; 
    } 
} 
  
// Driver Code 
int main() 
{ 
    // length of grid 
    int n1 = 36;
  
    // matrix to hold the grid of puzzle 
    vector<string> matrix; 
  
    // take input of puzzle in matrix 
    // input of grid of size n1 x n1 
matrix.push_back("********************#***************");
matrix.push_back("*******************######***********");
matrix.push_back("*****************#**#***************");
matrix.push_back("*****************#**#***************");
matrix.push_back("*****************######*************");
matrix.push_back("*****************#**#***************");
matrix.push_back("*****************#**#***************");
matrix.push_back("***************#########*****#******");
matrix.push_back("******************#****#***####*****");
matrix.push_back("******#***#****##########*#**#******");
matrix.push_back("******#***#*******#****#*########***");
matrix.push_back("******#*#*#*******#*******#*********");
matrix.push_back("*****######**##########***#*********");
matrix.push_back("******#*#*********#*******########**");
matrix.push_back("****#***#*******###########*********");
matrix.push_back("****#***#*#*****#*#*******#*********");
matrix.push_back("****#*#*#*#***###*#*****#########***");
matrix.push_back("**#*#########***#*#*******#***#**#*#");
matrix.push_back("#####*#*#*#***####********#**#######");
matrix.push_back("**#*#*#*#*#*****#***********#*#**#*#");
matrix.push_back("****#*#***#*#***#********######**#*#");
matrix.push_back("******#*###########*********#*#**#*#");
matrix.push_back("******#***#*#***#*******#######**#*#");
matrix.push_back("******#***#*#***#***#******#**#*****");
matrix.push_back("************#########******#********");
matrix.push_back("*****************#**#******#********");
matrix.push_back("**************#######******#********");
matrix.push_back("*****************#**#***************");
matrix.push_back("***********#######*######***********");
matrix.push_back("*****************#**#*#*************");
matrix.push_back("**************#####***#*************");
matrix.push_back("**************#*****####************");
matrix.push_back("**************#*******#*************");
matrix.push_back("**************#*********************");
matrix.push_back("************************************");
matrix.push_back("************************************");
matrix.push_back("************************************");

  
    vector<string> words; 
  
    // the words matrix will hold all 
    // the words need to be filled in the grid 
words.push_back("worry");
words.push_back("puzzling");
words.push_back("attach");
words.push_back("test");
words.push_back("possess");
words.push_back("enjoy");
words.push_back("industrious");
words.push_back("jelly");
words.push_back("gleaming");
words.push_back("quizzical");
words.push_back("amusing");
words.push_back("encouraging");
words.push_back("yellow");
words.push_back("intelligent");
words.push_back("stimulating");
words.push_back("hose");
words.push_back("passenger");
words.push_back("recess");
words.push_back("rat");
words.push_back("wild");
words.push_back("rainstorm");
words.push_back("chop");
words.push_back("plane");
words.push_back("separate");
words.push_back("unfasten");
words.push_back("squeamish");
words.push_back("room");
words.push_back("clumsy");
words.push_back("whistle");
words.push_back("imaginary");
words.push_back("zonked");
words.push_back("rest");
words.push_back("thunder");
words.push_back("swing");
words.push_back("position");
words.push_back("vacuous");
words.push_back("furniture");
words.push_back("system");
words.push_back("applaud");
words.push_back("humor");
words.push_back("chivalrous");
words.push_back("offbeat");
words.push_back("gray");
words.push_back("bushes");
words.push_back("boot");
words.push_back("bad");
words.push_back("cloistered");
words.push_back("motionless");
words.push_back("sneeze");
words.push_back("seashore");
  
    // initialize the number of ways 
    // to solve the puzzle to zero 
    ways = 0; 
  
    // recursive function to solve the puzzle 
    // Here 0 is the initial index of words array 
    // n1 is length of grid 
    solvePuzzle(words, matrix, 0, n1); 
    cout << "Number of ways to fill the grid is "
         << ways << endl; 
  
    return 0; 
} 
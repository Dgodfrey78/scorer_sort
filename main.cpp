
//This program sorts through the scores of any number of people and display the results in
//order of greatest to smallest. The user is prompted to input the name of
//the participant and their score. Once all scores have been collected the
//the scores are sorted and displayed

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct highscore //Struct named highscore with one int varible for score and one char array for names of scores.
{
    int score;
    char name[24];
};
int indexOfSmallest(const highscore scores[], int startingIndex, int size);//Function prototypes
void sortData(highscore scores[], int size);
void intializeData(highscore scores[], int size);
void displayData(const highscore scores[], int size);
int main()
{
    int size;
    cout << "How many players: "<< endl;
    cin>> size;
    highscore scores[size]; // Created an array of instances of highscore called scores
    intializeData(scores,size);//Set how many scorers, their names, and their scores
    sortData(scores,size);//Sorts data into descending order
    displayData(scores,size);//Displays data
    return 0;
    
}





void intializeData(highscore scores[], int size){
    int c;
    for (c=0; c<size;c++){
        cout << "Enter the name for the scorer #"<<c+1<<": ";//Gathers name and saves it in scores.name
        cin>> scores[c].name;
        cout << "Enter the score for scorer #"<<c+1<<": ";//Gather score and saves it in score.score
        cin >> scores[c].score;
    }
}





void displayData(const highscore scores[], int size){
    cout << "Top Scorers:"<<endl;
    int c;
    for(c=size;c>0;c--)
        cout << scores[c-1].name<<" : "<<scores[c-1].score<<endl;
}




void sortData(highscore scores[], int size)// Using selection sorting to sort scores
{
    for (int count = 0; count < size - 1; count++){
        swap(scores[indexOfSmallest(scores, count, size)],
             scores[count]);
    }
    
}


int indexOfSmallest(const highscore scores[], int startingIndex, int size)
{
    int targetIndex = startingIndex;
    
    for (int count = startingIndex + 1; count < size; count++){
        if (scores[count].score < scores[targetIndex].score){
            targetIndex = count;
        }
    }
    
    return targetIndex;
}

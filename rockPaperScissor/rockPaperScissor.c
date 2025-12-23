#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to return the result of the game
int game (char you, char computer) {
    //when both choose same thing
    if (you == computer) {
        return -1;
    }

    //when you choose stone and computer choose paper
    if (you == 's' && computer == 'p') 
        return 0;
        else if ( you == 'p' && computer == 's') return 1;

    //when you choose paper and computer choose scissor
    if (you == 's' && computer == 'z')
        return 1;

    //when you choose scissor and computer choose stone
    else if ( you == 'z' && computer == 's')
        return 0;
    
    //when you choose paper and computer choose stone
    if (you == 'p' && computer == 'z')
        return 0;

    //when you choose scissor and computer choose paper
    else if (you == 'z' && computer == 'p')
        return 1;
}

//Main function
int main() {
    //variables
    int n;
    char you, computer, result;
    //Generating random number between 0 to 99
    srand(time(NULL));
    //make randow number less than 100, divided it by 100
    n = rand() % 100;

    
    if (n < 33 ) 
        computer = 's';
    else if (n > 33 && n < 66)
        computer = 'p';
    else 
        computer = 'z';

    printf("\n\n\n\n\t\t\t\tEnter s for STONE, p for PAPER and z for SCISSOR\n\t\t\t\t\t\t\t");

    scanf(" %c", &you);

    result = game(you, computer);

    if ( result == -1) {
        printf("\n\n\n\t\t\t\t\t\t\tGame Draw!\n\n");
    }
    else if ( result == 1) {
        printf("\n\n\t\t\t\tWow! You have won the game!\n");
    }
    else {
        printf("\n\n\t\t\t\tOh! You have lost the game!\n");
    }

        printf("\t\t\t\tYou choose : %c and Computer choose : %c\n",you, computer);

    return 0;
}
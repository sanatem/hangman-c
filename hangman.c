/*
'+---------------------------------------+
'|  _____        HangMan V1.0       |
'|  I   |                                |
'|  I   O        by Sanatem         |
'|  I  /|\      January 29th, 2016       |
'|  I   |                                |
'|  I  /^\   Please enjoy it  !     |
'| _I_____   If you like it: fork it!    |
'+---------------------------------------+

*/

#include <stdio.h>
#include <unistd.h>


int level(int lifes){
	printf("%s\n","=============================");
	printf("%s\n","|  _____ ");
	printf("%s\n","|  I   | " );

	switch(lifes){
		case 7:
			printf("%s\n","|  I   O ");
			printf("%s\n","|  I  /|\\ ");
			printf("%s\n","|  I   |  " );
			printf("%s\n","|  I  /^\\ " );
			printf("%s\n","| _I_____" );
			break;
		case 6:
			printf("%s\n","|  I   O ");
			printf("%s\n","|  I  /|\\ ");
			printf("%s\n","|  I   |  " );
			printf("%s\n","|  I  /^ " );
			printf("%s\n","| _I_____" );
			break;
		case 5:
			printf("%s\n","|  I   O ");
			printf("%s\n","|  I  /|\\ ");
			printf("%s\n","|  I   |  " );
			printf("%s\n","|  I   ^ " );
			printf("%s\n","| _I_____" );
			break;
		case 4:
			printf("%s\n","|  I   O ");
			printf("%s\n","|  I  /|\\ ");
			printf("%s\n","|  I      " );
			printf("%s\n","|  I      " );
			printf("%s\n","| _I_____" );
			break;
		case 3:
			printf("%s\n","|  I   O ");
			printf("%s\n","|  I  /|  ");
			printf("%s\n","|  I      " );
			printf("%s\n","|  I      " );
			printf("%s\n","| _I_____" );
			break;
		case 2:
			printf("%s\n","|  I   O ");
			printf("%s\n","|  I   |  ");
			printf("%s\n","|  I      " );
			printf("%s\n","|  I      " );
			printf("%s\n","| _I_____" );
			break;
		case 1:
			printf("%s\n","|  I   O ");
			printf("%s\n","|  I     ");
			printf("%s\n","|  I      " );
			printf("%s\n","|  I      " );
			printf("%s\n","| _I_____" );
			break;						
		default:
			printf("GAME OVER!!!\n");
	}

	printf("%s\n","=============================");
}


int check_input(int word_size,char word[] ,char challenge[], int *lifes){
    
    //Read input from keyboard
    char c;
    scanf(" %c", &c);
    
    int i;
    int acierto = 0;
    for (i = 0; i < word_size; ++i)
    {	
    	if(word[i] == c){
    		printf("You guessed a letter !!!\n");
    		challenge[i] = c;
    		acierto++;
    	}	
    }

    if(acierto == 0){
    	*lifes = *lifes-1;
    	printf("Wrong!\n");
    	printf("\n");
    }
    else{
    	printf("Great ! You had %d success characters \n",acierto );
    	printf("\n");
    }


    return 0;
}


int left(char challenge[],int word_size){
	int i;
	int count=0;
	char c = '_';
	for ( i = 0; i < word_size; i++)
	{
		if (challenge[i] == '_')
		{
			count = count+1;
		}
	}
	return count;	
}



int clear(){
	int count=40;
	int i;
	for (i = 0; i < count; ++i)
	{
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{

	int lifes = 7;
	int word_size=0;

	char word[30];

	printf("%s\n","=============================");
	printf("%s\n","Welcome to Hangman v1.0 :)" );
	printf("%s\n","Developed by Sanatem" );
	printf("%s\n","=============================");

	printf("%s\n","Administrator - Please insert word to play (Max: 30 characters):");
	
	int i=0;
	char ch;
	while(ch!='\n')    // terminates if user hit enter
    {
        ch=getchar();
        word[i]=ch;
        i++;
        if(i>30){
        	printf("%s\n","You shall not pass! Please insert a word with at least 30 chars! " );
        	return 1;
        }
    }

    word_size=i-1;
    word[i]='\0';// inserting null character at end

	int j;
	char challenge[word_size];
	for (j = 0; j < word_size; ++j)
	{
		challenge[j] = (char)'_';	
	}



	while(lifes>0 && left(challenge,word_size)> 0 ){
		clear();
		printf("Remember you have %d lifes\n",lifes);
    	printf("The word has: %d  letters \n",word_size);
    	
    	level(lifes);
    	printf("Word to guess: %s \n", challenge );

    	printf("Please enter the letter to guess:\n");

    	check_input(word_size,word,challenge,&lifes);


	}

	if(left(challenge,word_size) == 0 && lifes>0){
		printf("============================\n");
		printf("YOU WON !!!!");
		printf("CONGRATULATIONS!!!\n");
		printf("The answer: %s",word);
		printf("============================\n" );
	}
	else{
		printf("============================\n");
		printf("GAME OVER !! !!! \n");
		printf("The correct word was: %s",word);
		printf("Please try again =D \n");
		printf("============================\n");
	}

	return 0;
}

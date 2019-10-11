#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  int command = 0; //the player's last input.  gets reset after each input to prevent unintended behaviour.
  int opened = 0, door = 0; //to keep track of things in the room
  int number = 42;
  int counter = 1;
  int guesscount = 0;
  int section = 0; //to keep track of the player's progression
  int deathcount = 0;

  printf("You wake up in an abandoned house.  In front of you, you see a box on the table.\n");
  printf("What do you do?\n");
  fflush(stdout); //flush the output buffer, aka put the text on the console
  //Section 0: opening the box and learning controls
  while(section == 0) {
    printf("Enter 1 to open the box.\n");
    fflush(stdout);
    scanf("%d", &command);
    //this decides if you want to open the box
    if(command == 1) {
      printf("There are 3 keys in the box. You pick them up.\n\n");
      section++; //leave this section
    }
    else  printf("I gave you 1 option. How did you fuck this up?\n");
    command = 0;

  }

  //Transition from section 0 to 1 ...
  printf("You look around the room. The decaying room is small with little in it but a door, a window, and a cupboard.\n");
  printf("What do you do?\n");
  fflush(stdout);

  //Section 1: searching the room
  while(section == 1) {
    printf("Enter 1 to try the door.\nEnter 2 to investigate the cupboard.\nEnter 3 to break out of the window and escape.");
    fflush(stdout);
    scanf("%d", &command);

    if(command == 1) { //try the door
      if(door == 0){ //door was closed
        printf("The door opens. You can now exit the room.\n\n");
        door = 1;
      }
      else if (opened == 0){ //door was open, but the cupboard wasn't checked
        printf("The door is open, but maybe there's something else here...\n\n");
      }
      else { //door was open AND cupboard was checked.
        printf("You exit the room.\n\n");
        section++; //leave this section
      }
    }
    else if(command == 2) { //check the cupboard
      if(opened == 0) {
        printf("In the cupboard you find a piece of paper with the number %d on it; you put it in your pocket for later.\n", number);
        printf("Now that the room is empty, the only real option is to go outside.\n\n");
        opened++;
      }

      else printf("The cupboard is empty.\n\n");
    }
    else if (command == 3){ // sassy remark about how breaking the window was a dick move
      printf("You break open the window. \n");
      //let's have some different text for if the door is open or not....
      if(door == 0) printf("After brushing the shards of glass off the windowsill, you test the door and realize - the door was unlocked the whole time.\n");
      else printf("You already opened the door, you know that?\n");

      //this will happen regardless of the door being opened or closed
      printf("You just ruined a perfectly good window, you asshole. \n");
      printf("Whatever.  You climb through the window, careful to avoid the broken glass, and leave the room.\n\n");
      section++;
    }
    else printf("There are only 3 buttons, were you dropped as a baby?\n");

    fflush(stdout);
    command = 0;
  }


  //Transition from section 1 to 2...
  printf("Note: your lines were cut off so I made some shit up.\n");
  printf("You head to the door and go outside. Clouds cover the sky, and it looks like a storm is brewing.\n");
  printf("You see a path heading into the nearby woods - maybe it will lead to a village?\n");
  printf("You decide to head down the path, and soon you come across another house.\n");
  printf("You hear crows cawing in the distance. As you enter the house, the door slam shut behind you.\n");
  printf("You try to open it but it appears to be locked.  Luckily, you have keys in your pocket.\n\n");
  fflush(stdout);

  //Section 2: gtfo this room
  while(section == 2) {
    printf("\nWhich key do you want to try on the door?\n");
    printf("Enter 1, 2, or 3.\n");
    fflush(stdout);

    scanf("%d", &command);

    if(command == 1) printf("This key is too big...\n\n");
    else if(command == 2) printf("This key is too small...\n\n");
    else if(command == 3) {
      printf("This key is just right!\n\n");
      section++;
    }
    else printf("Invalid command.\n");

    fflush(stdout);
    command = 0;
  }

  printf("When you open the door, you realize that it took you back onto the forest path you just came from.\n");
  printf("The sun has set.\n");
  printf("As you walk down this path at night, glancing around in fear, you are suddenly blinded by a flash of light.\n");
  printf("A horrendous demon appears before you, with the horns of a goat and eyes as black as death itself.\n");
  printf("You are frozen with fear, and the demon's thunderous voice calls out to you:\n");

  printf("\"The key to your life was left in a house full of mice.\n");  //the \" is an escaped quotation mark
  printf("Your life I will spare if you can lay my secrets bare. Guess a number between 100 and 1 - guess wrong thrice, and your life will be done!\"\n");
  fflush(stdout);

  //this is technically section 3 based on the number we're at
  //i don't personally use do...while loops, but i figured i should leave *some* of your work...with some modifications ;)
  do {
    guesscount++;
    printf("\nGuess a number.  Attempt: %d \n", guesscount);
    if(guesscount == 3) printf("This is your last chance! Was there any clue somewhere?\n"); //hint on the final guess
    fflush(stdout);

    scanf("%d", &counter);


    if(counter == number)  {
      printf("You guessed correctly!\n\n");
      break;
    }
    else if(counter > number) {
      printf("Your guess is too high.\n");
    }
    else {
      printf("Your guess is too low.\n");
    }

    fflush(stdout);

  } while(guesscount < 3);

  if(counter == number) {
    printf("You survive with your life and the demon disappears into the night.  For now....\n");
    printf("Total Attempts: %d \n", guesscount);
    section++; //advance if you survive
  }

  else {
    deathcount++;
    printf("The demon laughs at your failure.  You feel nothing but pain as you watch the demon slash at your abdomen.\n");
    printf("As the world fades away, your thoughts are only filled with horror, as the demon wears your entrails as a crown.\n");
    printf("He begins to dance, his laugh echoing through your skull, until you hear nothing at all.\n");
    printf("You died.... again: %d \n", deathcount);
  }

  while(section == 4){
    printf("Now that you escaped the demon what do you want to do?\n");
    printf("Press 1 to investigate the house or press 2 to try and find another path.\n");
    fflush(stdout);

    scanf("%d", &command);

    if(command == 1){//investigate old house what do we want in the house
      printf("You open the door to the house you were just trapped in and look around\n");
      printf("As you you gaze around the old decrepit building you notice\n");
    }
    else if(command == 2){// find a new path
      printf("As you walk down the dark path you hear howling off in the distance but after the things you've seen tonight a wolf is the least of your worries\n");
      printf("After what seems to be ages you make it back to the house where you woke up in but you notice the path forks off onto another direction that you swear wasn't there before\n");
      printf("Do you wish to head down the path? Or head back into the house? \n");
      printf("Press 1 to head down the new path, press 2 to go back into the house. \n");
      fflush(stdout);
    }
    if(command == 1) {
      printf("you head down the path leaving the old house behind you \n");
      section++; //heading on to section 5
    }
    else if (command == 2){
      printf("you head to the old house where you woke up but I dont know what you were expecting its still empty dumbass \n");
    }
  }

}
1

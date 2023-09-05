import java.util.Scanner;
import java.util.ArrayList;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    //intro
    System.out.println("Welcome To Duck Fight! (created by David Han)\nFirst, lets create your Duck!");
    //name
    System.out.println("Enter your Ducks name:");
    String name = sc.nextLine();
    System.out.println("What type of Duck is " + name + "? \nType [m] for mallard, [p] for pintail, or [r] for rubber:");
    String typeLetter = sc.nextLine();
    //Initialize Variables
    duckType type = duckType.Mallard;
    int power = 0;
    int level = 1;
    int health = 100;
    int maxhealth = 100;
    int xp = 0;
    
    //duck type
     while(!typeLetter.equals("m") && !typeLetter.equals("p") && !typeLetter.equals("r"))
    {
      System.out.println("Invalid Response! Try Again!");
      typeLetter = sc.nextLine();
    }
    if (typeLetter.equals("m")) //Mallard Duck
    {
      type = duckType.Mallard;
      power = 4;
      maxhealth = 100;
    }    
    else if (typeLetter.equals("p")) //Pintail Duck
    {
      type = duckType.Pintail;
      power = 3;
      health = 125;
      maxhealth = 125;
    }
    else if (typeLetter.equals("r")) //Rubber Duck
    {
      type = duckType.Rubber;
      power = 5;
      health = 75;
      maxhealth = 75;
    }
   
    //create duck object
    Duck userDuck = new Duck(name,type,level,power,health,maxhealth,xp);
    System.out.println(userDuck);
    userDuck.createAttacks(); //create array of attacks
    //create ai duck
    aiDuck ai = new aiDuck();
    ai.setHealth(); //sets health of AI based on its generated type
    System.out.println(ai); 
    //Attack Sequence

    while (userDuck.health > 0 && ai.health > 0)
    {
      //Level Checkers
      if (userDuck.xp >= 5 && userDuck.xp != 0)
      {
        userDuck.levelUp();
        System.out.println(name + " is now level " + userDuck.level + "!\n---------------\n");
        userDuck.xp = 0;
      }
      if (ai.xp >= 5 && ai.xp != 0)
      {
        ai.levelUp();
        System.out.println("AI is now level " + ai.level + "!\n---------------");
        ai.xp = 0;
      }
      //Attack Checkers
      userDuck.newAttacks();
      System.out.println("Which Attack Would You Like To Use?");
      userDuck.printAttacks();
      System.out.println("\n---------------\n");
      userDuck.attack();
      //checks if waddle is used/successful
      if (userDuck.userAttack.equals("Waddle") && userDuck.success)
      {
        ai.subtractHealth(ai.power,userDuck.poison); //ai is confused and attacks itself
        ai.attack();
      }
      else
      {
      ai.subtractHealth(userDuck.power,userDuck.poison);
      ai.attack();
      userDuck.subtractHealth(ai.power);
      //checks if bubble blast is successful
        if (userDuck.userAttack.equals("Bubble Blast") && userDuck.success == false) //if bubble blast fails, AI attacks twice
        {
          userDuck.subtractHealth(ai.power);
        }
      }
      //print out respective hitpoints of ducks
      System.out.println("AI Health: " + ai.health + "/" + ai.maxhealth);
      System.out.println(name + "'s Health: " + userDuck.health + "/" + userDuck.maxhealth); //prevents health from going over maxhealth
    }
    // End Screen
    System.out.println("Game Over!");
    if (ai.health <= 0)
    {
      System.out.println("You Win!");
    }
    else
    {
      System.out.println("Take the L!");
    }
  }
}



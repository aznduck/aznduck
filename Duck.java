import java.util.Scanner;
import java.util.ArrayList;

public class Duck
{
   Scanner sc = new Scanner(System.in);
  //PIV's
  protected String name; //duck name
  protected duckType type; //duck type
  protected int poison; //poison damage
  protected boolean success; //checks if attacks are successful
  protected int level; //level of duck
  public int health;
  public int maxhealth; //maximum/starting health
  protected int power; //amount of damage done
  ArrayList<String> rAttacks = new ArrayList<String>();
  ArrayList<String> mAttacks = new ArrayList<String>();
  ArrayList<String> pAttacks = new ArrayList<String>();
  protected String userAttack; //checks which attack user used
  protected int xp; //allows duck to level up
  protected int defense; //adds HP to duck
  

  //Constructor
  public Duck(String name, duckType type, int level, int power, int health, int maxhealth, int xp)
  {
    this.name = name;
    this.type = type;
    this.level = level;
    this.power = power;
    this.health = health;
    this.maxhealth = maxhealth;
  }

  //Methods
  public String toString()
  {
    return name + " is a " + type + " Duck with " + health + " health and is currently level " + level;
  }
  //prints an array of attacks based off the type of duck that the user chooses
  public void printAttacks()
  {
    if (type == duckType.Mallard)
      {
        for (int i = 0; i < mAttacks.size(); i++)
        {
          System.out.print("[" + i + "] " + mAttacks.get(i) + " ");
        }
        System.out.println("");
        userAttack = mAttacks.get(sc.nextInt());
      }
    else if (type == duckType.Pintail)
      {
        for (int j = 0; j < pAttacks.size(); j++)
        {
          System.out.print("[" + j + "] " + pAttacks.get(j) + " ");
        }
        System.out.println("");
        userAttack = pAttacks.get(sc.nextInt());
      }
    else if (type == duckType.Rubber)
      {
        for (int k = 0; k < rAttacks.size(); k++)
        {
          System.out.print("[" + k + "] " + rAttacks.get(k) + " ");
        }
        System.out.println("");
        userAttack = rAttacks.get(sc.nextInt());
      }
  }
  //adds attacks to the attack array based off the duck's type
  public void createAttacks()
  {
    if (type == duckType.Mallard)
      {
        mAttacks.add("Peck");
        mAttacks.add("Flutter");
        
      }
    else if (type == duckType.Pintail)
      {
        pAttacks.add("Beak Jab");
        pAttacks.add("Flutter");
        
      }
    else if (type == duckType.Rubber)
      {
        rAttacks.add("Squirt");
        rAttacks.add("Squeak");
      }
  }
  //Creates new attacks when the xp of the duck is sufficient to level up to level 3
  public void newAttacks()
  {
    if (type == duckType.Mallard && level == 3 && mAttacks.size() == 2)
    {
      mAttacks.add("Feather Fury");
    }
    else if (type == duckType.Pintail && level == 3 && pAttacks.size() == 2)
    {
      pAttacks.add("Waddle");
    }
    else if (type == duckType.Rubber && level == 3 && rAttacks.size() == 2)
    {
      rAttacks.add("Bubble Blast");
    }
  }
  //Carries out an attack based off user input
  public void attack()
  {
    if (userAttack.equals("Peck") || userAttack.equals("Beak Jab"))
    {
      this.power = 5 * level; //5
      if (userAttack.equals("Peck"))
      {
        System.out.println(name + " used Peck!");
      }
      else if (userAttack.equals("Beak Jab"))
      {
        System.out.println(name + " used Beak Jab!");
      }
      xp++; //duck gains xp
    }
    else if (userAttack.equals("Squirt"))
    {
      this.power = 7 * level; //7
      System.out.println(name + " used Squirt!");
      xp++;
    }
    else if (userAttack.equals("Flutter"))
    {
      this.power = 0;
      if (defense < 3) //prevents duck from gaining too much health
      {
      this.defense += 1;
      }
      if ((this.health + (defense * level)) > maxhealth) //prevents duck from going over its starting health
      {
        this.health = maxhealth;
      }
      else
      {
      this.health += defense * level;
      }
      
      System.out.println(name + " used Flutter!");
      xp += 2; //increased xp for using defensive moves
    }
    else if (userAttack.equals("Squeak"))
    {
      this.power = 0;
      if (defense < 3)
      {
      this.defense += 1;
      }
      if ((this.health + (int)(defense * level * 0.5)) > maxhealth) //similar to Flutter, but less defense because of the rubber duck's aggresive nature
      {
        this.health = maxhealth;
      }
      else
      {
      this.health += (int)defense * level * 0.5;
      }
      System.out.println(name + " used Squeak!");
      xp += 2;
      }
    else if (userAttack.equals("Feather Fury"))
    {
      this.power = 2 * level;
      if (Math.random() < 0.5) //1/2 chance of poisoning the opponent when this move is used
      {
        poison = level; //adds poison damage to the opponent
        System.out.println(name + " used Feather Fury!\nThe AI was poisoned!");
      }
      else
      {
      System.out.println(name + " used Feather Fury!");
      }
      xp += 3;
    }
    else if (userAttack.equals("Waddle"))
    {
      this.power = 0;
      if (Math.random() < 0.7) //7/10 chance of confusing the AI
      {
        System.out.println(name + " used Waddle!\nThe AI is confused!");
        success = true;
      }
      else
      {
        System.out.println(name + " used Waddle, but it failed!");
        success = false;
      }
      xp += 3;
    }
    else if (userAttack.equals("Bubble Blast"))
    {
      this.power = 10 * level;
      if (Math.random() < 0.5) //1/2 chance of attack working, does massive damage if successful
      {
        System.out.println(name + "used Bubble Blast!\nThe AI Attacked Twice!");
        success = true;
      }
      else
      {
        System.out.println(name + " used Bubble Blast, but it failed!\nThe AI Attacked Twice!");
        this.power = 0;
        success = false;
      }
      xp += 4;
    }
  }
  
  //subtracts health 
  public void subtractHealth(int health)
  {
    this.health -= health;
  }
  //levels up when xp is sufficient
  public void levelUp()
  {
    level++;
  }
}
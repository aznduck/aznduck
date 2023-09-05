  public class aiDuck extends Duck
{
  //Random Constructor
  public aiDuck()
  {
    super("AI",duckType.values()[(int)(Math.random() * 3)], 1, (int)(Math.random()*3+3), 100, 100, 0);
  }
  
  //methods
  @Override
  public String toString()
  {
    return "The computer has a " + type + " Duck with " + health + " health and is currently level " + level;
  }

  
  public void subtractHealth(int health, int poison)
  {
    this.health = this.health - health - poison;
  }

  public void setPower(int power)
  {
    this.power = power;
  }
  //sets health of AI based on the randomly generated duck type
  public void setHealth()
  {
    if (type == duckType.Mallard)
    {
      this.health = 100;
      this.maxhealth = 100;
    }
    else if (type == duckType.Pintail)
    {
      this.health = 125;
      this.maxhealth = 125;
    }
    else 
    {
      this.health = 75;
      this.maxhealth = 75;
    }
  }
  @Override
  //randomly generates attacks based off its type
  public void attack()
  {
    
    if (type == duckType.Mallard)
    {
      if ((Math.random() * 2) > 0.25 )
      {
        this.power = 5 * level;
        System.out.println("AI used Peck!");
        xp++;
      }
      else
      {
        this.power = 0;
        if (defense < 3)
        {
        this.defense += 1;
        }
        if ((this.health + (defense * level)) > maxhealth)
      {
        this.health = maxhealth;
      }
      else
      {
      this.health += defense * level;
      }
        System.out.println("AI Used Flutter!");
        xp += 2;
        }

    }
    else if (type == duckType.Pintail)
    {
      if ((Math.random() * 2) > 0.25)
      {
        this.power = 5 * level;
        System.out.println("AI used Beak Jab!");
        xp++;
      }
      else
      {
        this.power = 0;
        if (defense < 3)
        {
        this.defense += 1;
        }
        if ((this.health + (defense * level)) > maxhealth)
      {
        this.health = maxhealth;
      }
      else
      {
      this.health += defense * level;
      }
        System.out.println("AI Used Flutter!");
        xp += 2;
        
      }

    }
    else if (type == duckType.Rubber)
    {
      if ((Math.random() * 2) > 0.25)
      {
        this.power = 7 * level;
        System.out.println("AI used Squirt!");
        xp++;
      }
      else
      {
        this.power = 0;
        if (defense < 3)
        {
        this.defense += 1;
        }
        if ((this.health + (int)(defense * level * 0.5)) > maxhealth)
      {
        this.health = maxhealth;
      }
      else
      {
      this.health += (defense * level * 0.5);
      }
        System.out.println("AI used Squeak!");
        xp += 2;
        
        
      }

    }
    
    
    
    
  }
  




}
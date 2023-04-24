################################
# Jon Scales
# Program 04
# CMPS2143

# This program will define 2 classes for a single die and multiple dice.  Methods in each class will allow the construction of rolls of the die/dice, writing out to the console a presentation of the die/dice rolls, determining sum of all die values with multiple rolss of the die or dice.  When multiple dice are used, the maximum face value obtained with each set of dice can be reported, also the minimum value or the average values can be reported. 
##################################

#################################
#large portions of this code were provided by Dr. Terry Griffin
#################################


from dice import Die
from dice import Dice
from rich import print



def dieRoller(die, numRolls=10, testType="sum"):
  """
  This method actually calls the proper roll method depending on the associated parameters of 
  the roll call.  Params are number of rolls, if the object is a single die or mulciple dice, & 
  what type of roll output information is desired ( max value, min value or avg value). 
  """
  
  if isinstance(die, Die):  # die is an instance of the Die class
    print(f"Testing {die.sides} sided die for {numRolls} rolls:")
    print("    [ ", end="")
    for i in range(numRolls):
      print(die.roll(), end=", ")
    print("]\n")
  elif testType != "sum":  # in this case die is an instance of the Dice class
    print(f"Rolling {len(die.dice)} {die.sides} sided die {numRolls} times to get the {testType} 
    individual die value for each roll:")
    #print("end="")
    for i in range(numRolls):
      if testType == "avg":
        print(die.avg(), end="\n")
      elif testType == "min":
        print(die.min(), end="\n")
      elif testType == "max" :
        print(die.max(), end="\n")
    print("\n")
  else:
    print(f"Rolling {len(die.dice)} {die.sides} sided die {numRolls} times to get the {testType} 
    of all die values for each roll:")
    #print("    [ ", end="")
    for i in range(numRolls):
       print(die.sum(), end="\n")
    print("\n")




if __name__ == '__main__':


  print(f"This program will simulate multiple dice rolls as might be used in RPGs\n")
  
  print(f"This is an example of the output this program will be able to generate\n")

   #  test examples 
  d1 = Die()
  d2 = Die(20)
  d3 = Dice(10, 5)
  d4 = Dice(6, 2)

  dieRoller(d1, 10)
  dieRoller(d2, 20)
  dieRoller(d3, 10, "max")
  dieRoller(d3, 10, "min")
  dieRoller(d3, 10, "avg")
  dieRoller(d4,2)
 
  # get imput from user to roll dice
  
  print(f"Choose a type of dice (number of sides), number of dice to roll, and number of rolls 
   you would like to test\n")
  num_sides = int(input("How many sides do the dice have? "))
  num_dice = int(input("\nHow many dice do you want to roll? "))
  num_rolls = int(input("\nHow many rolls do you want to make? "))
  
  print("What do you want to know about the rolls?\n")
  print("Enter 'sum' for the sum of the dice values\n")
  print("Enter 'max' for the max die value\n")
  print("Enter 'min' for the min die value\n")
  print("Enter 'avg' for the average of the dice values\n")
  
  roll_type = input("\nEnter your choice: ")
  
  userdice = Dice(num_sides, num_dice)
  
  dieRoller(userdice, num_rolls, roll_type)

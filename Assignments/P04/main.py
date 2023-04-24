from dice import Die
from dice import Dice
from rich import print


def dieTester(die, numRolls=10, testType="sum"):
  if isinstance(die, Die):
    print(f"Testing {die.sides} sided die for {numRolls} rolls:")
    print("    [ ", end="")
    for i in range(numRolls):
      print(die.roll(), end=" ")
    print("]")
  else:
    print(
      f"Rolling {len(die.dice)} {die.sides} sided die {numRolls} times to get the {testType} value:"
    )
    print("    [ ", end="")
    for i in range(numRolls):
      if testType == "avg":
        print(die.avg(), end=" ")
      elif testType == "min":
        print(die.min(), end=" ")
      elif testType == "max":
        print(die.max(), end=" ")
      else:
        print(die.sum(), end=" ")
    print("]")


if __name__ == '__main__':


  print(f"This program will simulate multiple dice rolls as might be used in RPGs")
  print(" ")
  print(f"This is an example of the output this program will be able to generate")

   #  examples 
  d1 = Die()
  d2 = Die(20)
  d3 = Dice(10, 5)

  dieTester(d1, 10)
  dieTester(d2, 20)
  dieTester(d3, 10, "max")
  dieTester(d3, 10, "min")
  dieTester(d3, 10, "avg")
  # get imput from user to roll dice
  
  print(f"Choose a type of dice, number of sides and number of rolls you would like to test")
  num_dice = int(input("How many dice do you want to roll? "))
  num_sides = int(input("How many sides do the dice have? "))
  num_rolls = int(input("How many rolls do you want to make? "))
  
  print("What do you want to know about the rolls?")
  print("Enter 'sum' for the sum of the dice values")
  print("Enter 'max' for the max die value")
  print("Enter 'min' for the min die value")
  print("Enter 'avg' for the average of the dice values")
  
  roll_type = input("Enter your choice: ")
  
  userdice = Dice(num_sides, num_dice)
  
  dieTester(userdice, num_rolls, roll_type)

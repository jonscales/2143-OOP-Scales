from rich import print
import random
import sys


class Die(object):

  def __init__(self, sides=None):
    if not sides:
      self.sides = 6
    else:
      if not isinstance(sides, int):
        print("error: sides is not an integer!")
        sys.exit()
      self.sides = sides

  def roll(self):
    values = [x for x in range(self.sides)]

    random.shuffle(values)

    return values[0] + 1

  def __str__(self):
    return f"[sides: {self.sides}]"


class Dice:

  def __init__(self, sides=None, num_dice=1):
    if not sides:
      print("Need to pass in sides!!!")
      sys.exit()

    self.sides = sides

    # create a container
    self.dice = []

    for die in range(num_dice):
      self.dice.append(Die(sides))


  # def roll(self):
  #   values = [x for x in range(self.sides)]
  #   random.shuffle(values)
  #   return values[0] + 1

  def sum(self):
    total = 0
    for die in self.dice:
      total += die.roll()

    return total

  def max(self):
    """
    rolls n, s sided dice and appends largest face value obtained onto a list of faceValues
    """
    
    faceVals = []
    for d in self.dice:
      #faceValue = d.roll()
      # self.faceVals.append(faceValue)

      faceVals.append(d.roll())
    return max(faceVals)

  def min(self):
    rollSum = 0

    faceVals = []
    for d in self.dice:

      rollSum += d.roll()
      faceVals.append(d.roll())

    return min(faceVals)

  def avg(self):
    faceVals = []
    for d in self.dice:
      x = d.roll()
      # print(type(x))
      faceVals.append(x)

    return sum(faceVals) / len(faceVals)

  def roll(self, rollType=None):

    if rollType == 'max':
      return self.max()
    elif rollType == 'min':
      return self.min()
    elif rollType == 'avg':
      return self.avg()
    else:
      return self.sum()

  def __str__(self):
    s = "Dice:[\n    "
    for d in self.dice:
      s = s + str(d)
    s = s + "\n]\n"
    return s


def dieTester(die, numRolls=10, testType="sum"):
  if isinstance(die, Die):  # die is an instance of the Die class
    print(f"Testing {die.sides} sided die for {numRolls} rolls:")
    print("    [ ", end="")
    for i in range(numRolls):
      print(die.roll(), end=" ")
    print("]")
  else:  # in this case die is an instance of the Dice class
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
  d1 = Die()
  d2 = Die(20)
  d3 = Dice(10, 5)

  dieTester(d1, 10)
  dieTester(d2, 20)
  dieTester(d3, 60, "max")
  dieTester(d3, 10, "min")
  dieTester(d3, 10, "avg")

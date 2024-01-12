import turtle
import time
import math

color = ['black']
t = turtle.Turtle()
def drawRectangle(myTurtle, width, length):
  t.color('black')
  t.begin_fill()
  myTurtle.forward(width) #side 1
  myTurtle.right(90)
  myTurtle.forward(length) #side 2
  myTurtle.right(90)
  myTurtle.forward(width) #side 3
  myTurtle.right(90)
  myTurtle.forward(length) #side 4
  myTurtle.right(90)
  myTurtle.forward(width)
  t.end_fill()

def twoBigLines(myTurtle):
 drawRectangle(t,2,115)
 moveOver(t,2)
 drawRectangle(t,2,115)

def middleTwoLines(myTurtle):
 moveOver(t,2)
 drawRectangle(t,2,115)
 moveOver(t,2)
 drawRectangle(t,2,115)
 moveOver(t,2)

def moveOver(myTurtle, length):
  myTurtle.penup()
  myTurtle.forward(length)
  myTurtle.pendown() 
t.speed(10000000)


def l0(myTurtle):
  moveOver(t,6)
  drawRectangle(t,4,100)
  moveOver(t,2)
  drawRectangle(t,2,100)

def l1(myTurtle):
  moveOver(t,4)
  drawRectangle(t,4,100)
  moveOver(t,4)
  drawRectangle(t,2,100)

def l2(myTurtle):
  moveOver(t,4)
  drawRectangle(t,2,100)
  moveOver(t,4)
  drawRectangle(t,4,100)

def l3(myTurtle):
  moveOver(t,2)
  drawRectangle(t,8,100)
  moveOver(t,2)
  drawRectangle(t,2,100)

def l4(myTurtle):
  moveOver(t,2)
  drawRectangle(t,2,100)
  moveOver(t,6)
  drawRectangle(t,4,100)

def l5(myTurtle):
  moveOver(t,2)
  drawRectangle(t,4,100)
  moveOver(t,6)
  drawRectangle(t,2,100)

def l6(myTurtle):
  moveOver(t,2)
  drawRectangle(t,2,100)
  moveOver(t,2)
  drawRectangle(t,8,100)

def l7(myTurtle):
  moveOver(t,2)
  drawRectangle(t,6,100)
  moveOver(t,2)
  drawRectangle(t,4,100)

def l8(myTurtle):
  moveOver(t,2)
  drawRectangle(t,4,100)
  moveOver(t,2)
  drawRectangle(t,6,100)

def l9(myTurtle):
  moveOver(t,6)
  drawRectangle(t,2,100)
  moveOver(t,2)
  drawRectangle(t,4,100)

def r0(myTurtle):
  drawRectangle(t,6,100)
  moveOver(t,4)
  drawRectangle(t,2,100)
  moveOver(t,2)

def r1(myTurtle):
  drawRectangle(t,4,100)
  moveOver(t,4)
  drawRectangle(t,4,100)
  moveOver(t,2)

def r2(myTurtle):
  drawRectangle(t,4,100)
  moveOver(t,2)
  drawRectangle(t,4,100)
  moveOver(t,4)

def r3(myTurtle):
  drawRectangle(t,2,100)
  moveOver(t,8)
  drawRectangle(t,2,100)
  moveOver(t,2)

def r4(myTurtle):
  drawRectangle(t,2,100)
  moveOver(t,2)
  drawRectangle(t,6,100)
  moveOver(t,4)

def r5(myTurtle):
  drawRectangle(t,2,100)
  moveOver(t,4)
  drawRectangle(t,6,100)
  moveOver(t,2)

def r6(myTurtle):
  drawRectangle(t,2,100)
  moveOver(t,2)
  drawRectangle(t,2,100)
  moveOver(t,8)

def r7(myTurtle):
  drawRectangle(t,2,100)
  moveOver(t,6)
  drawRectangle(t,2,100)
  moveOver(t,4)

def r8(myTurtle):
  drawRectangle(t,2,100)
  moveOver(t,4)
  drawRectangle(t,2,100)
  moveOver(t,6)

def r9(myTurtle):
  drawRectangle(t,6,100)
  moveOver(t,2)
  drawRectangle(t,2,100)
  moveOver(t,4)

Nums = "3600029145"

twoBigLines(t)
i = 0
while i < 4:
  if Nums[i] == "0":
    l0(t)
  elif Nums[i] == "1":
    l1(t)
  elif Nums[i] == "2":
    l2(t)
  elif Nums[i] == "3":
    l3(t)
  elif Nums[i] == "4":
    l4(t)
  elif Nums[i] == "5":
    l5(t)
  elif Nums[i] == "6":
    l6(t)
  elif Nums[i] == "7":
    l7(t)
  elif Nums[i] == "8":
    l8(t)
  elif Nums[i] == "9":
    l9(t)
  i+=1

middleTwoLines(t)

i = 5
while i < 9:
  if Nums[i] == "0":
    r0(t)
  elif Nums[i] == "1":
    l1(t)
  elif Nums[i] == "2":
    l2(t)
  elif Nums[i] == "3":
    l3(t)
  elif Nums[i] == "4":
    l4(t)
  elif Nums[i] == "5":
    l5(t)
  elif Nums[i] == "6":
    l6(t)
  elif Nums[i] == "7":
    l7(t)
  elif Nums[i] == "8":
    l8(t)
  elif Nums[i] == "9":
    l9(t)
  i+=1

twoBigLines(t)












twoBigLines(t)
l3(t)
l6(t)
l0(t)
l0(t)
l0(t)
middleTwoLines(t)
r2(t)
r9(t)
r1(t)
r4(t)
r5(t)
twoBigLines(t)




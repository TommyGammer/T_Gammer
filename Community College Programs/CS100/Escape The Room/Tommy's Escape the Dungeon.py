from Room import Room
######################################################
# creates the rooms
def createRooms():
# r1 through r4 are the four rooms in the mansion
# currentRoom is the room the player is currently in (which
# can be one of r1 through r4)
# since it needs to be changed in the main part of the
# program, it must be global
    global currentRoom
    # create the rooms and give them meaningful names
    r1 = Room("Room 1")
    r2 = Room("Room 2")
    r3 = Room("Room 3")
    r4 = Room("Room 4")
    win = Room("Exit")
    # add exits to room 1
    r1.addExit("east", r2)
    # add grabbables to room 1
    r1.addGrabbable("key")
    # add grabbables to room 3
    r3.addGrabbable("doorknob")
    # add grabbables to room 4
    r4.addGrabbable("gold")
    # add items to room 1
    r1.addItem("chair", "It is made of wicker and no one is sitting on it.")
    r1.addItem("table", "It is made of oak. A golden key rests on it.")
    # add items to room 3
    r3.addItem("board", "It is a board attached to the wall.")
    r3.addItem("bookshelf", "It is a bookshelf made of oak, there is a doorknob inside one of the books.")
    # add Item to room 4
    r4.addItem("mirror", "You look in the mirror and see something disgusting, surely this mirror is broken.")
    r4.addItem("safe", "There appears to be an open safe with gold inside.")
    # add exits to room 2
    r2.addExit("west", r1)
    r2.addExit("east", r3)
    r2.addExit("north", r4)
    r2.addExit("south", win)
    # add exits to room 3
    r3.addExit("west", r2)
    # add exits to room 4
    r4.addExit("south", r2)
    # add items to room 2
    r2.addItem("rug", "It is nice and Indian. It also needs to be vacuumed.")
    r2.addItem("fireplace", "It is full of ashes.")
    r2.addItem("goblin", "Oh my it is a goblin! He seems to be guarding the south door. Maybe he would let you pass if you gave him some gold.")
    # set room 1 as the current room at the beginning
    # of the game
    currentRoom = r1

######################################################
# START THE GAME!!!
inventory = [] # nothing in inventory...yet
createRooms() # add the rooms to the game

# play forever (well, at least until the player dies or asks to
#  quit)
input("Press enter to start: ")
while (True):
    # set the status so the player has situational awareness
    # the status has room and inventory information
    status = "{}\nYou are carrying: {}\n".format(currentRoom, inventory)
    

    # display the status
    print("=========================================")
    if (currentRoom.name == "Exit"):
        break
    else:
        print(status)
 
    # prompt for player input
    # the game supports a simple language of <verb> <noun>
    # valid verbs are go, look, and take
    # valid nouns depend on the verb
    action = input("What to do? ")

    # set the user's input to lowercase to make it easier to
    #  compare the verb and noun to known values
    action = action.lower()

    # exit the game if the player wants to leave (supports
    #  quit, exit, and bye)
    if (action == "quit" or action == "exit" or action == "bye"):
        break
    

    # set a default response
    response = "I don't understand. Try verb noun. Valid verbs are go, look, and take"
    # split the user input into words (words are separated by
    #  spaces)
    words = action.split()

    # the game only understands two word inputs
    if (len(words) == 2):
        # isolate the verb and noun
        verb = words[0]
        noun = words[1]

        # the verb is: go
        if (verb == "go"):
            # set a default response
            response = "Invalid exit."

            # check for valid exits in the current room
            for i in range(len(currentRoom.exits)):
                # a valid exit is found
                if (noun == currentRoom.exits[i]):
                    # change the current room to the one
                    #  that is associated with the specified
                    #  exit
                    if currentRoom.name == "Room 2" and noun == "east" and "key" in inventory:
                        currentRoom = currentRoom.exitLocations[i]
                        response = "You unlock the door and go into room 3."
                    elif currentRoom.name == "Room 2" and noun == "east" and "key" not in inventory:
                        response = "This room is locked."
                    elif currentRoom.name == "Room 2" and noun == "north" and "doorknob" in inventory:
                        currentRoom = currentRoom.exitLocations[i]
                        inventory.remove("doorknob")
                        response = "You attach the doorknob to the door and go into room 4."
                    elif currentRoom.name == "Room 2" and noun == "north" and "doorknob" not in inventory:
                        response = "This room is missing a doorknob."
                    elif currentRoom.name == "Room 2" and noun == "south" and "gold" in inventory:
                        currentRoom = currentRoom.exitLocations[i]
                        response = "You have escaped, you win!"
                    elif currentRoom.name == "Room 2" and noun == "south" and "gold" not in inventory:
                        response = "The goblin will not let you pass."
                    elif currentRoom.name == "Room 2" and noun == "south" and "gold" in inventory:
                        response = "You have successfully bribed the goblin and he let you out."
                        currentRoom = currentRoom.exitLocations[i]
                    else:
                        currentRoom = currentRoom.exitLocations[i]
                        response = "Room changed"
                        

                    # no need to check any more exits
                    break
        # the verb is: look
        elif (verb == "look"):
            # set a default response
            response = "I don't see that item."

            # check for valid items in the current room
            for i in range(len(currentRoom.items)):
                # a valid item is found
                if (noun == currentRoom.items[i]):
                    # set the response to the item's
                    #  description
                    response = currentRoom.itemDescriptions[i]

                    # no need to check any more items
                    break
        # the verb is: take
        elif (verb == "take"):
            # set a default response
            response = "I don't see that item."

            # check for valid grabbable items in the current
            #  room
            for grabbable in currentRoom.grabbables:
                # a valid grabbable item is found
                if (noun == grabbable):
                    # add the grabbable item to the player's
                    #  inventory
                    inventory.append(grabbable)

                    # remove the grabbable item from the
                    #  room
                    currentRoom.delGrabbable(grabbable)

                    # set the response (success)
                    response = "Item grabbed."

                    # no need to check any more grabbable
                    #  items
                    break

    # display the response
    print("\n{}".format(response))

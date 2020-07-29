Type in rock, paper, or scissors. Then my program will randomly choose rock, paper, or scissors and tell you if you won, lost, or drew. 
If either the player or computer creates a 3 point lead, the game will end.

from random import*
def main():

#declaration of variables
    random = 0
    computeroutput = 0
    playerscore = 0
    computerscore = 3
    drawcounter= 0
    userinput = 0
    output = 0

    while True:
        print ("please type rock, paper, or scissors")
        userinput = input()
        if playerscore == 3 + computerscore: # case where player is in a 3 point lead
            print("game over you win")
            userinput = ""
        if computerscore == 3 + playerscore:  # case where computer is in a 3 point lead
            print("game over you lose")
            userinput = ""
        
        while userinput != "":
            random = randint(0,2) # randomly chooses 0 (rock), 1(paper), or 2(scissors)
            if random == 0:
                output = "rock"
                print(output) # notifies player that the computer chose rock
                if userinput == "paper": # in the case the player chooses paper
                    print ("you win") # notifies player the results of the match
                    playerscore += 1 #updates a counter 
                    break
                if userinput == "rock":
                    print ("it's a draw")
                    drawcounter +=1
                    break
                if userinput == "scissors":
                    print ("you lose")
                    computerscore += 1
                    break
                
            if random == 1:
                output = "paper"
                print(output)
                if userinput == "rock":
                    print ("you lose")
                    computerscore += 1
                    break
                if userinput == "scissors":
                    print ("you win")
                    playerscore += 1
                    break
                if userinput == "paper":
                    print ("it's a draw")
                    drawcounter +=1
                    break
                
            if random == 2:
                output = "scissors" 
                print(output)
                if userinput == "paper":
                    print ("you lose")
                    computerscore += 1
                    break
                if userinput == "rock":
                    print ("you win")
                    playerscore += 1
                    break
                if userinput == "scissors":
                    print ("it's a draw")
                    drawcounter +=1
                    break
    
        #tally up points and declare winner
        if userinput == "":
            print ("You got", playerscore, "points.")
            print ("The computer got", computerscore, "points.")
            print ("You drew", drawcounter, "times.")
            break            
            
main()


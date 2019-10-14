import random 

possible_words = ['wizard', 'dragon', 'cursed', 'unicorn', 'spell', 'curse', 'enchanted', 'fairy', 'unicorn']
in_word = []
tries = 0

def choosing_word(possible_words):
    chosen_word = random.randint(0,len(possible_words)-1)
    to_uncover = list(possible_words[chosen_word])
    return(to_uncover)

current_word = choosing_word(possible_words)

def v2():
    global current_word
    global tries
    print(current_word)
    current = input('Enter a letter:\t')
    if current in current_word:
        current_word.remove(current)
    else:
        tries +=1

def checkingv2():
    global current_word
    global tries
    if len(current_word) == 0:
        print("Congratulations\nYou've guessed it!")
        return False
    elif tries == 8:
        print("You're out of tries!\nPlay again soon")
        return False
    else:
        return True

def game():
    playing  = True
    while playing == True:
        v2()
        playing = checkingv2()
game()
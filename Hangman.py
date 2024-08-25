import random
def get_hangman_stage(remaining_attempts):
    max_attempts = 6
    stages = [
        """
        +----+
        |    |
        |
        |
        |
        --
        """,
        """
        +----+
        |    |
        |    O
        |
        |
        --
        """,
        """
        +----+
        |    |
        |    O
        |    |
        |
        --
        """,
        """
        +----+
        |    |
        |    O
        |   /|
        |
        --
        """,
        """
        +----+
        |    |
        |    O
        |   /|\\
        |
        --
        """,
        """
        +----+
        |    |
        |    O
        |   /|\\
        |   /
        --
        """,
        """
          +----+
          |    |
          |    O
          |   /|\\
          |   / \\
          --
        """]
    return stages[max_attempts - remaining_attempts]
def select_word(words):
    return random.choice(words)
def hangman():
    words = ["apple", "banana", "orange", "mango", "grapes", "strawberry", "guava"]
    word = select_word(words)
    guessed_letters =""
    remaining_attempts = 6
    h=0
    while remaining_attempts != 0:
        if set(word) == set(guessed_letters):
            print(f"Guessed word:'{word}'\nCongratulations!!\nYou win!!")
            return
        print(get_hangman_stage(remaining_attempts))
        print("Guessed letters: ", end="")
        for letter in word:
            if letter in guessed_letters:
                print(letter, end="")
            else:
                print("_", end="")
        print()
        guess = input("Guess a letter: ")
        if guess not in word:
            remaining_attempts -= 1
            print("Wrong guess,",guess," is not in the word.\n",remaining_attempts," guesses left.")
            if h==0:
                hint = input("Would you like a hint? (y/n): ")
                if hint.lower() == "y":
                    print("The word is the name of a fruit.")
                    print(f"The word starts with the letter '{word[0]}'")
                    h=1
        else:
            guessed_letters += guess
    print(get_hangman_stage(remaining_attempts))
    print("Computer wins!!\nYou lose!!\nThe word is:", word)
hangman()


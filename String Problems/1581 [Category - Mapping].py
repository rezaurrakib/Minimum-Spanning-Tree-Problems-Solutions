# Reza, Sr. Software Engineer
# Digital Imaging Group, Samsung Research, Bangladesh

import sys

class Chat:
    def __init__(self):
        self.get_input()

    def get_input(self):
        number = input()
        test_cases = int(number)

        for i in range(test_cases):
            language_map = {}
            num = int(input())
            for j in range(num):
                language = input()
                language_map[language] = True

            if(len(language_map) > 1):
                print("ingles")
            else :
                print(language)
                

if __name__ == '__main__':
    obj = Chat()
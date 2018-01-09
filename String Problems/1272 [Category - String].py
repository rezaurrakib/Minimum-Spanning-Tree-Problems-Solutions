# Reza, Sr. Software Engineer
# Digital Imaging Group, Samsung Research, Bangladesh

import sys

class HiddenMsg : 
    def __init__(self):
        self.get_input()

    def is_alpha(self, ch):
        if((ord(ch) > 64 and ord(ch) < 91) or (ord(ch) > 96 and ord(ch) < 123)):
            return True
        else : 
            return False

    def get_input(self):
        number = input()
        num_of_line = int(number)
        for i in range(num_of_line):
            line = input()
            sz = len(line)
            j = 0
            output = ""
            while(j < sz):
                if(self.is_alpha(line[j])):
                    output = output + line[j]
                    while(j < sz and self.is_alpha(line[j])):
                        j += 1
                j += 1
            print(output)

if __name__ == '__main__':
    obj = HiddenMsg()
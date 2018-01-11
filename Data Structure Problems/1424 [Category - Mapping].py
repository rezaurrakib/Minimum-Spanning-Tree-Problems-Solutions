# Reza, TUM Informatics
# Critical Input : Be careful about an integer which is not present at all in the list. You should handle the exception 

import sys

class MappingData:

    def __init__(self):
        self.get_input()

    def reset(self):
        self.map_numbers = {} # The key will be number and value will be the list containing occuring positions

    def get_input(self):
        for line in sys.stdin:
            self.reset()
            num_elmnts, queries = line.split(' ')
            num_elmnts = int(num_elmnts)
            queries = int(queries)
           
            list_of_numbers = list(map(int, input().split())) # For multiple integer in a single line, map might be better.

            for i in range(num_elmnts):
                n = list_of_numbers[i]
                if(n in self.map_numbers) :
                    self.map_numbers[n].append(i+1) # append the new number to the existing array at this slot    
                else :
                    self.map_numbers[n] = [i+1] # create a new array in this slot
            
            # Run the queries
            for i in range(queries):
                ith_occurence, key_num = map(int, input().strip().split())
                if((key_num not in self.map_numbers) or (len(self.map_numbers[key_num]) < ith_occurence)) :
                    print("0")
                else :
                    print(self.map_numbers[key_num][ith_occurence - 1])


if __name__ == '__main__':
    obj = MappingData() 

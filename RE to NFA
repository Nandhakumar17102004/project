transition_table = [[0]*3 for _ in range(20)]

print ("---------------------------------------")
re = input("Enter the regular expression : ")
print ("---------------------------------------")
re += " "
l=[]
i = 0
j = 1

while i < len(re):
    if re[i] == 'a':
        if i + 1 < len(re) and re[i+1] != '|' and re[i+1] != '*':
            transition_table[j][0] = j+1
            j += 1
            print(transition_table)
            print ("--------------------")
        elif i + 1 < len(re) and re[i+1] == '|' and re[i+2] == 'b':
            transition_table[j][2] = []
            transition_table[j][2].append(j+1)
            transition_table[j][2].append(j+3)
            j += 1
            transition_table[j][0] = j+1
            j += 1
            transition_table[j][2] = []
            transition_table[j][2].append(j+3)
            j += 1
            transition_table[j][1] = j+1
            j += 1
            transition_table[j][2] =[]
            transition_table[j][2].append(j+1)
            j += 1
            i = i+2
            print(transition_table)
            print ("--------------------")
        elif i + 1 < len(re) and re[i+1] == '*':
            transition_table[j][2] =[]
            transition_table[j][2].append(j+1)
            transition_table[j][2].append(j+3)
            j += 1
            transition_table[j][0] = j+1
            j += 1
            transition_table[j][2] = []
            transition_table[j][2].append(j+1)
            transition_table[j][2].append(j-1)
            j += 1 
            print(transition_table)
            print ("--------------------")
    elif re[i] == 'b':
        if i + 1 < len(re) and re[i+1] != '|' and re[i+1] != '*':
            transition_table[j][1] = j+1
            j += 1
            print(transition_table)
            print ("--------------------")
        elif i + 1 < len(re) and re[i+1] == '|' and re[i+2] == 'a':
            transition_table[j][2] =[]
            transition_table[j][2].append(j+1)
            transition_table[j][2].append(j+3)
            j += 1
            transition_table[j][1] = j+1
            j += 1
            transition_table[j][2] = []
            transition_table[j][2].append(j+3)
            j += 1
            transition_table[j][0] = j+1
            j += 1
            
            transition_table[j][2] = []
            transition_table[j][2].append(j+1)
            
            
            j += 1
            i = i+2
            print(transition_table)
            print ("--------------------")
        elif i + 1 < len(re) and re[i+1] == '*':
            
            transition_table[j][2] =[]
            transition_table[j][2].append(j+1)
            transition_table[j][2].append(j+3)
            j += 1
            transition_table[j][1] = j+1
            j += 1
            transition_table[j][2] = []
            transition_table[j][2].append(j+1)
            transition_table[j][2].append(j-1)
            j += 1
            print(transition_table)
            print ("--------------------")

    elif re[i] == 'e' and i + 1 < len(re) and re[i+1] != '|' and re[i+1] != '*':
        transition_table[j][2] = j+1
        j += 1
        print(transition_table)
        print ("--------------------")
    elif re[i] == '(':
        bp = j
        j+=1 
        print(transition_table) 
        print ("--------------------")

    elif re[i] == ')' and i + 1 < len(re) and re[i+1] == '*':
        transition_table[bp][2] = []
        transition_table[bp][2].append(j+1)
        transition_table[bp][2].append(bp+1)
        transition_table[j][2] = []
        transition_table[j][2].append(j+1)
        transition_table[j][2].append(bp+1)
        j += 1
        print(transition_table)
        print ("--------------------")
    i += 1

print ("--------------------")
print ("Transition function:")
print ("--------------------")
for i in range(j):
    if transition_table[i][0] != 0:
        print("q[{0},a] --> q[{1}]".format(i, transition_table[i][0]))
    if transition_table[i][1] != 0:
        print("q[{0},b] --> q[{1}]".format(i, transition_table[i][1]))
    if transition_table[i][2] != 0:
        if len(transition_table[i][2])<2:
            print("q[{0},e] --> q[{1}]".format(i, transition_table[i][2]))
        else:
            print("q[{0},e] --> q[{1}] & q[{2}]".format(i, transition_table[i][2][0], transition_table[i][2][1]))
print ("--------------------")
print(transition_table)
print ("--------------------")
final_state = j
print("Final state: q[{}]".format(final_state))
print ("--------------------")

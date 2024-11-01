import networkx as nx
import matplotlib.pyplot as plt

class Graph:
    #vertices,incoming egdes,the weight b/w vertices and incoming and outgoing no of edges
    def __init__(self):
        self.adj_list = {}
        self.adj_isend = [0] * 27
        self.con_wei = [[0] * 27 for i in range(27)]
        self.cou = [0] * 27

    def insert_string(self, s):
        t = s
        self.add_vertex(0)
        self.adj_isend[convert_ascii(s[len(s) - 1])] += 1
        for i in t:
            u = convert_ascii(i)
            self.add_vertex(u)

        if t[0] in self.adj_list[0]:
            self.con_wei[0][convert_ascii(t[0])] += 1
        else:
            self.con_wei[0][convert_ascii(t[0])] += 1
            self.adj_list[0].append(s[0])
        for i in range(len(t) - 1):
            u = convert_ascii(t[i])
            self.add_edge(u, t[i + 1])

    def add_vertex(self, vertex):
        if vertex not in self.adj_list:#check v1(head node) is the list if not vertex v1 is added to the list
            self.adj_list[vertex] = []

    def add_edge(self, v1, v2):
        if v2 in self.adj_list[v1]:#checks v2 and v1 node are connected with each other
            self.con_wei[v1][convert_ascii(v2)] += 1#converting to asci because time compl will be more if we use char we have calculated v1 asci in insert
            #so we are calling and getting value frm there and for v2 we are calculating here.
            #weight is 
        else:
            self.adj_list[v1].append(v2)
            self.con_wei[v1][convert_ascii(v2)] += 1
        self.cou[v1] += 1
        self.cou[convert_ascii(v2)] += 1

    def print_g(self):
        ch = 0
        for vertex in self.adj_list:
            if ch == 0:
                print(vertex, ":", self.adj_list[vertex])
                ch += 1
                continue
            else:
                print(chr(vertex + 96), ":", self.adj_list[vertex])
                ch += 1

    def find_word(self, string):
        if string[0] not in self.adj_list[0]:
            return False

        u = convert_ascii(string[0])
        for i in range(1, len(string)):
            if string[i] in self.adj_list[u]:
                u = convert_ascii(string[i])
            else:
                return False

        return True

    def delete_str(self, s):
        if self.find_word(s):
            for i in range(0, len(self.adj_list[0])):
                if self.adj_list[0][i] == s[0]:
                    if self.con_wei[0][convert_ascii(s[0])] < 2:
                        self.adj_list[0].pop(i)
                        self.con_wei[0][convert_ascii(s[0])] -= 1
                        break
                    else:
                        self.con_wei[0][convert_ascii(s[0])] -= 1
            u = s[0]
            u = convert_ascii(s[0])
            for i in range(1, len(s)):
                for j in range(0, len(self.adj_list[u])):
                    if self.adj_list[u][j] == s[i]:
                        self.cou[u] -= 1
                        self.cou[convert_ascii(s[i])] -= 1
                        if self.con_wei[u][convert_ascii(s[i])] < 2:
                            self.con_wei[u][convert_ascii(s[i])] -= 1
                            self.adj_list[u].pop(j)
                            break
                        else:
                            self.con_wei[u][convert_ascii(s[i])] -= 1
                u = convert_ascii(s[i])
            u = len(self.adj_list)
            for i in range(0, u):
                for j in self.adj_list:
                    if j == 0:
                        continue
                    if self.cou[j] == 0:
                        self.adj_list.pop(j)
                        break
        else:
            print("The word you're trying to delete is not in the graph")

def convert_ascii(cha):
    x = ord(cha)
    if 97 <= x <= 122:
        return x - 97 + 1
    if 65 <= x <= 90:
        return x - 65 + 1

graphs = Graph()
while True:
    print("Type 1 to insert a string\nType 2 to search for a string\nType 3 to delete a string \nType 4 to print the adjacent list representation of graph\nType 5 to visualize the graph\nType 6 to exit")
    i = int(input())
    if i == 1:
        print("Enter the string to insert")
        s = input()
        graphs.insert_string(s)
        print("After inserting ", s, "the graph is\n")
        graphs.print_g()
    if i == 2:
        print("Enter the string to search")
        s = input()
        print(graphs.find_word(s))
    if i == 3:
        print("Enter the string to delete")
        s = input()
        graphs.delete_str(s)
        print("After deleting ", s, "the graph is\n")
        graphs.print_g()
    if i == 4:
        graphs.print_g()
    if i == 5:
        G = nx.Graph()
        for v1 in graphs.adj_list:
            for v2 in graphs.adj_list[v1]:
                G.add_edge(chr(v1 + 96), v2)
        pos = nx.spring_layout(G)  # position for all nodes
        nx.draw(G, pos, with_labels=True, font_weight='bold')
        plt.show()
    if i == 6:
        break

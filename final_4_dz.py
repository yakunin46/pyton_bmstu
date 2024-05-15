print("Вариант №24 ИУ4-23Б Якунин А.Д.")
print("Визуализация графа, заданного списком рёбер")
print("Найти все рёбра, смежные к вершине с заданной степенью вершины")

import networkx as nx
import matplotlib.pyplot as plt

#класс определяет объект Graph как набор методов(номер,вершины,связь вершин,рёбра)
class Graph():
    
    def __init__(self,number,vertex,connect_vertex,edges):
        Graph.number=number
        Graph.vertex=vertex
        Graph.edges=edges
        Graph.connect=connect_vertex
        
    def output(self):
        print('Граф №'+Graph.number)
        print(f'Вершины: {Graph.vertex}')
        print(f'Рёбра: {Graph.edges}')
        print(f'Связь вершин: {Graph.connect}')
               
#функция считывает исходные данные из текстового файла в строку
def read_txt(name_of_txt):
    string=""
    for i in open(name_of_txt):
        string+=i
    return string

#функция разделяет исходные данные файла по "\n" и " "
def split_string(string):
    list_before=string.split("\n")
    del list_before[-1]

    for i in range(0,len(list_before)):
        list_before[i]=list_before[i].split(" ")
    return list_before

#функция формирует список рёбер
def list__after(list_before):
    list_after1=[]
    list_after2=[]
    for i in range(0,len(list_before)):
        if len(list_before[i])==2:
            list_after1.append(int(list_before[i][0]))
            list_after2.append(int(list_before[i][1]))
             
    list_after=zip(list_after1,list_after2)
    return list(set(list_after))

#функция формирует список одиночных вершин
def list__after3(list_before):
    list_after3=[]
    for i in range(0,len(list_before)):
        if len(list_before[i])==1:
            list_after3.append(int(list_before[i][0]))
    return list_after3

#функция формирует сеписок вершин на основе списка рёбер графа
def list_of_vertex(list_after,list_after3):
    vertex=[] 
    vertex_l=[]
    for i in range(0,len(list_after)):
        vertex.append(list_after[i][0])
        vertex.append(list_after[i][1])
    for i in range(0,len(list_after3)):
        vertex.append(list_after3[i])
    vertex=list(set(vertex))
    return vertex

#функция определяет номер графа (по названию ".txt" файла)
def number_Graph(name_of_txt):
    number_graph=""
    for i in range(0,len(name_of_txt)):
        if name_of_txt[i].isdigit():
            number_graph+=name_of_txt[i]
    return number_graph     
    
#функция определяет связь вершин графа и записывает это в словарь
def connect_of_vertex(list_after,vertex):
    connect_vertex={}
    list_of_vertex=[]
    for i in vertex:
        for k in range(0,len(list_after)):
            if i in list_after[k]:
                list_of_vertex.append(list_after[k][0])
                list_of_vertex.append(list_after[k][1])
                list_of_vertex.remove(i)
        if len(list_of_vertex)==0:
            set_of_vertex={}   
            connect_vertex[i]=set_of_vertex
            list_of_vertex=[]
        else:
            set_of_vertex=set(list_of_vertex) 
            connect_vertex[i]=set_of_vertex
            list_of_vertex=[]
    return connect_vertex

def define_vertex(degree, connect_vertex):
    degree_vertex=[]
    for i in connect_vertex.keys():
        if len(connect_vertex[i])==degree:
            degree_vertex.append(i)
    return degree_vertex

def define_edges(degree_vertex, edges):
    degree_edges=[]
    for i in degree_vertex:
        for j in edges:
            if i in j:
                degree_edges.append(j)       
    return degree_edges

def find_vertex(connect_vertex,edges):
    degree=int(input("Задайте степень вершины: "))
    degree_vertex=define_vertex(degree, connect_vertex)
    degree_edges=define_edges(degree_vertex, edges)
    print("Список вершин с заданной степенью вершины: ", degree_vertex)
    print("Список смежных  рёбер: ", degree_edges)

#функция строит граф, используя его параметры
def draw_graph():
    
    G=nx.Graph()
    exemplar_Graph=Graph(number_graph,vertex,connect_vertex,edges)
    
    G.add_nodes_from(exemplar_Graph.vertex)
    G.add_edges_from(exemplar_Graph.edges)

    exemplar_Graph.output()

    find_vertex(connect_vertex,edges)
    nx.draw(G, with_labels=1)
    plt.show()

name_of_txt="two_var_txt/list_of_edges7.txt"
string=read_txt(name_of_txt)
number_graph=number_Graph(name_of_txt)
list_before=split_string(string)
list_after=list__after(list_before)
list_after3=list__after3(list_before)
vertex=list_of_vertex(list_after,list_after3)
edges=list_after
connect_vertex=connect_of_vertex(list_after,vertex)

draw_graph()
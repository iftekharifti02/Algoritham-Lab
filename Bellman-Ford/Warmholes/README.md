# Bellman-Ford Algorithm in C++ 

The **Bellman-Ford algorithm** is a single-source shortest path algorithm that finds the shortest path from a given source vertex to all other vertices in a graph. Unlike Dijkstra’s algorithm, Bellman-Ford can handle **negative edge weights**, making it useful in scenarios where some paths might reduce the total cost.  

It is widely used in **network routing protocols** and in detecting **negative cycles** in weighted graphs.  

---

## Key Features  

- Can handle **negative edge weights**  
- Detects **negative weight cycles**  
- **Time complexity:** O(V × E), where V = vertices, E = edges  
- **Space complexity:** O(V) for distance and predecessor arrays  

---

## Principle of Relaxation  

Relaxation is the process of updating the shortest path found so far by checking if a shorter path can be obtained by going through the current vertex.  

**Steps:**  
1. Initialize the distance to all vertices as **infinity**  
2. Set the distance of the **source vertex as 0**  
3. For each vertex, apply **relaxation** for all its edges  
4. Repeat the relaxation process **V-1 times**  
5. Check for **negative-weight cycles** by relaxing all edges one more time  

---

## Why N-1 Relaxations Work  

Relaxing edges **V-1 times** ensures the shortest path from the source to any vertex, which can have at most V-1 edges, is correctly calculated.  

If a shorter path is found in the **Vth iteration**, it indicates a **negative cycle**, as distances can decrease indefinitely in such a cycle.  

---

## Pseudo-Code  

```text
function BellmanFord(Graph, source):
    // Step 1: Initialization
    for each vertex v in Graph:
        distance[v] = ∞
        predecessor[v] = NULL
    distance[source] = 0

    // Step 2: Relaxation (V-1 times)
    for i from 1 to V-1:
        for each edge (u, v) with weight w in Graph:
            if distance[u] + w < distance[v]:
                distance[v] = distance[u] + w
                predecessor[v] = u

    // Step 3: Negative Cycle Detection
    for each edge (u, v) with weight w in Graph:
        if distance[u] + w < distance[v]:
            report "Graph contains a negative-weight cycle"

    // Step 4: Return results
    return distance, predecessor
```


## Result of Example


***Consider this ASCII graph:***   
```text
       4
   (A)----->(B)
    | \      |
    |  \     |
   5|   \-2  |3
    |    \   |
   (C)----->(D)
       1
```

Vertices: A, B, C, D

Edges and Weights:

A → B : 4

A → C : 5

A → D : -2

C → D : 1

B → D : 3

Step-by-Step Execution:

Initialize distances: A=0, B=∞, C=∞, D=∞

First relaxation: Update distances using edges

Repeat V-1 = 3 times

Check for negative cycles

Final Distances:

A = 0

B = 4

C = 5

D = -2


 ## Summary

Handles negative edges

Uses relaxation principle

V-1 iterations ensure shortest paths

Extra iteration detects negative cycles

ASCII graph + pseudo-code make it easy to understand
#include<iostream>
#include<iomanip>
#include <stdexcept>

/**
 * File: graph.h
 * Description: This file contains the definition and implementation of the
 *              Graph class and other functions.
 */

#ifndef _GRAPH_H_
#define _GRAPH_H_

using namespace std;
namespace GraphNameSpace
{
  /**
  * Description: A struct representing properties of a edges including 
  * its weight and the associated vertices
  */
    template<class Type>
    struct ConnectedVertices
    {
      int connIndex; // index of the vertex ont he other end of the edge
      int edgeWeight; // weight if its a weighted graph
    };
  /**
  * Description: A struct representing a vertex
  */  
    template<class Type>
    struct Vertex
    {
      Type info;	 // info holded by the vertex
      int vertexIndex; // position in the graph
      int countAdj;	// number of adjacent vertices to this vertex
      ConnectedVertices<Type> edge[100]; // and array of adjuscent vertices
    };
    
    enum Weight{WEIGHTED, UNWEIGHTED};
    enum Direction{DIRECTED, UNDIRECTED};
    
    template<class Type>
    class Graph
    {
    public:
      
      /**
      * Function: Graph - The default constructor.
      * Description: Constructs a new Graph object with no arguments passed.
      * Function input: None.
      * Function output: None.
      * Precondition: none.
      * Postcondition: Graph object created with no size
      */
      Graph();
      
    /**
      * Function: Array - The overloaded constructor with direction and weight
      * Description: Constructs a new Graph object with argument passed to it.
      * Function input: direction and weight of the graph
      * Function output: None.
      * Precondition: none.
      * Postcondition: Graph object created and initialized with
      *                the size passed
      */
      Graph(Direction, Weight);

    /**
      * Function: Array - The overloaded constructor with direction and weight
      * Description: Constructs a new Graph object with argument passed to it.
      * Function input: direction and weight of the graph
      * Function output: None.
      * Precondition: none.
      * Postcondition: Graph object created and initialized with
      *                the size passed
      */
      Graph(Weight, Direction);
      
    /**
      * Function: Array - The overloaded constructor with direction
      * Description: Constructs a new Graph object with argument passed to it.
      * Function input: direction of the graph
      * Function output: None.
      * Precondition: none.
      * Postcondition: Graph object created and initialized with
      *                the size passed
      */
      Graph(Direction);
      
    /**
      * Function: Array - The overloaded constructor with weight
      * Description: Constructs a new Graph object with argument passed to it.
      * Function input: weight of the graph
      * Function output: None.
      * Precondition: none.
      * Postcondition: Graph object created and initialized with
      *                the size passed
      */
      Graph(Weight);
      
    /**
      * the copy constructor
      */
      Graph(const Graph<Type>& otherGraph);
      
      /**
      * overloading the assignment operator
      */
      const Graph& operator=(const Graph<Type>& arg);
      
    /**
      * Function: ~Graph -The destructor
      * Description: detroys the object when it goes out of scope
      * Function input: none
      * Function output: None.
      * Precondition: graph should exist.
      * Postcondition: Graph object is destroyed to prevent memory leak
      */
      ~Graph();
      
    /**
      * Function: destroy 
      * Description: destroy the object when it goes out of scope
      * Function input: none
      * Function output: None.
      * Precondition: graph should exist.
      * Postcondition: Graph object is destroyed to prevent memory leak
      */
      void destroy();
      
    /**
      * Function: isEmpty
      * Description: checks if the graph is empty
      * Function input: none
      * Function output: None.
      * Precondition: graph should exist.
      * Postcondition: returns true is graph is empty or false otherwise
      */
      bool isEmpty() const; // no vertices
      
    /**
      * Function: isFull
      * Description: checks is the graph is full
      * Function input: none
      * Function output: None.
      * Precondition: graph should exist.
      * Postcondition: returns true is graph is full or false otherwise
      */
      bool isFull() const;
      
    /**
      * Function: isAdjacentTo
      * Description: checks if theres is an edge between two vertices
      * Function input: two vertices
      * Function output: None.
      * Precondition: edges should exist
      * Postcondition: returns true if adjancency exist or false otherwise
      */
      bool isAdjacentTo(const Type&,const Type&) const throw (std::logic_error);

    /**
      * Function: edgeWeight
      * Description: returns the weight of the edge between 2 vertices
      * Function input: two vertices
      * Function output: the weight of the edge
      * Precondition: edges should exist
      * Postcondition: the weight of the edge is returned
      */
      int edgeWeight(const Type&,const Type&) const throw (std::logic_error);// precondition: edge exists
      
      /**
      * Function: edgeWeight
      * Description: returns the number of edges in the graph
      * Function input: none
      * Function output: the number of edges in the graph.
      * Precondition: edges should exist
      * Postcondition: the weight of the edge is returned
      */
      int edgeCount() const;
      
      /**
      * Function: vertexCount
      * Description: returns the number of vertices in the graph
      * Function input: none
      * Function output: the number of vertices in the graph.
      * Precondition: edges should exist
      * Postcondition: the number of vertices in the graph is returned
      */
      int vertexCount() const;
      
      /**
      * Function: insertVertex
      * Description: inserts a vertex in the graph
      * Function input: a vertex
      * Function output: none
      * Precondition: a graph should exist
      * Postcondition: a vertex is inserted to the graph
      */
      void insertVertex(const Type&) throw (std::range_error, std::logic_error);
      
      /**
      * Function: insertEdge
      * Description: inserts an edge between 2 vertices
      * Function input: a 2 edges and weight if exists
      * Function output: none
      * Precondition: the vertices should exist
      * Postcondition: a edge is inserted betwen tow vertices
      */
      void insertEdge(const Type&,const Type&, int weight=1);
      
      /**
      * Function: deleteEdge
      * Description: deletes an edge between 2 vertices
      * Function input: 2 vertices
      * Function output: none
      * Precondition: an edge between the passed vertices should exist should exist
      * Postcondition: the edge is deleted betwen the two vertices
      */
      void deleteEdge(const Type&,const Type&) throw (std::logic_error);
      
    /**
      * Function: deleteVertex
      * Description: deletes a vertex
      * Function input: a vertex
      * Function output: none
      * Precondition: the vertex should exist
      * Postcondition: the vertex is deleted
      */
      void deleteVertex(const Type&) throw (std::logic_error);
      
    /**
      * Function: findVertex
      * Description: finds the position  of th evertex in the graph
      * Function input: a vertex
      * Function output: the position of the vertex
      * Precondition: the vertex should exist
      * Postcondition: the vertex position if returned
      */
      int findVertex(const Type& vertex) const;
      
    /**
      * Function: dump
      * Description: prints the whle graph
      * Function input: none
      * Function output: none
      * Precondition: a ghraph object should exist
      * Postcondition: the graph is printed
      */
      void dump() const;
      
      Weight weigh;  // is graph weighted?
      Direction direction; // is the graph directed?
      int edgeCountNum; // the numbr of edges in the graph
      int count; // the number of vertices in the graph

    private:
      Vertex<Type> *node;  // the collection of vertices in the graph
    };
    
    template<class Type>
    Graph<Type>::Graph()
    {
      weigh = UNWEIGHTED;
      direction = UNDIRECTED;
      node = new Vertex<Type>[100];
      count = 0;
      edgeCountNum=0;
    }
    
    template<class Type>
    Graph<Type>::Graph(Direction dir, Weight weight)
    {
      weigh = weight;
      direction = dir;
      node = new Vertex<Type>[100];
      count = 0;
      edgeCountNum=0;
    }
    
    template<class Type>
    Graph<Type>::Graph(Weight weight, Direction dir)
    {
      weigh = weight;
      direction = dir;
      node = new Vertex<Type>[100];
      count = 0;
      edgeCountNum=0;
    }
    
    template<class Type>
    Graph<Type>::Graph(Direction dir)
    {
      weigh = UNWEIGHTED;
      direction = dir;
      node = new Vertex<Type>[100];
      count = 0;
      edgeCountNum=0;
    }
    
    template<class Type>
    Graph<Type>::Graph(Weight weight)
    {
      weigh = weight;
      direction = UNDIRECTED;
      node = new Vertex<Type>[100];
      count = 0;
      edgeCountNum=0;
    }
    
  template<class Type>
  bool Graph<Type>::isEmpty() const
  {
    if(count == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
    
  template<class Type>
  bool Graph<Type>::isFull() const
  {
    if(count == 100)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
    
  template<class Type>
  void Graph<Type>::insertVertex(const Type& itemToInsert) throw (std::range_error, std::logic_error)
  {
    try
    {
      if(isFull() == true)
	throw std::range_error("Graph is full");
      
      int vertexIndexNumDelete;
      bool vertex_exists = false;
      
      int edgeWeightNum;
      
      int deleteIndex;

      for(int i=0; i< count; i++)
      {
	if(vertex_exists == false)
	{
	  if(node[i].info == itemToInsert)
	  {
	    vertex_exists = true;
	    vertexIndexNumDelete = i;
	  }
	}
      }
      if(vertex_exists == true)
	throw std::logic_error("Item already exists in the Graph and will not be inserted");
      
      node[count].info = itemToInsert;
      node[count].vertexIndex = count;
      node[count].countAdj = 0;
      count += 1;
    }
    catch(const std::out_of_range bad_range)
    {
      cerr << "out_of_range: " << bad_range.what() << '\n';
    }
    catch(const std::logic_error item_exists)
    {
      cerr << "logic_error: " << item_exists.what() << '\n';
    }
  }
    
  template<class Type>
  void Graph<Type>::insertEdge(const Type& fromVertex, const Type& toVertex, int weight)
  {    
    if(weigh == 0 && direction == 0) // if(weigh == WEIGHTED && direction == DIRECTED)
    {
      int indexFrom;
      int indexTo;
      
      bool from_exists = false;
      bool to_exists = false;
      
	for(int i=0; i< count; i++)
	{
	  if(from_exists == false)
	  {
	    if(node[i].info == fromVertex)
	    {
	      from_exists = true;
	      indexFrom = i;
	    }
	  }
	  if(to_exists == false)
	  {
	    if(node[i].info == toVertex)
	    {
	      to_exists = true; 
	      indexTo = i;
	    }
	  }
      }
      node[indexFrom].edge[node[indexFrom].countAdj].connIndex = indexTo;
      node[indexFrom].edge[node[indexFrom].countAdj].edgeWeight = weight;
      node[indexFrom].countAdj++;
    }
    else if(weigh == 1 && direction == 1) // if(weigh == UNWEIGHTED && direction == UNDIRECTED)
    {
      int indexFrom;
      int indexTo;
      
      bool from_exists = false;
      bool to_exists = false;
      
	for(int i=0; i< count; i++)
	{
	  if(from_exists == false)
	  {
	    if(node[i].info == fromVertex)
	    {
	      from_exists = true;
	      indexFrom = i;
	    }
	  }
	  if(to_exists == false)
	  {
	    if(node[i].info == toVertex)
	    {
	      to_exists = true; 
	      indexTo = i;
	    }
	  }
      }
      node[indexFrom].edge[node[indexFrom].countAdj].connIndex = indexTo;
      node[indexFrom].edge[node[indexFrom].countAdj].edgeWeight = 0;
      node[indexFrom].countAdj++;
      
      node[indexTo].edge[node[indexTo].countAdj].connIndex = indexFrom;
      node[indexTo].edge[node[indexTo].countAdj].edgeWeight = 0;
      node[indexTo].countAdj++;
    }
    else if(weigh == 1 && direction == 0) // if(weigh == UNWEIGHTED && direction == DIRECTED)
    {
      int indexFrom;
      int indexTo;
      
      bool from_exists = false;
      bool to_exists = false;
      
	for(int i=0; i< count; i++)
	{
	  if(from_exists == false)
	  {
	    if(node[i].info == fromVertex)
	    {
	      from_exists = true;
	      indexFrom = i;
	    }
	  }
	  if(to_exists == false)
	  {
	    if(node[i].info == toVertex)
	    {
	      to_exists = true; 
	      indexTo = i;
	    }
	  }
      }
      node[indexFrom].edge[node[indexFrom].countAdj].connIndex = indexTo;
      node[indexFrom].edge[node[indexFrom].countAdj].edgeWeight = 0;
      node[indexFrom].countAdj++;
    }
    else if(weigh == 0 && direction == 1) // if(weigh == WEIGHTED && direction == UNDIRECTED)
    {
      int indexFrom;
      int indexTo;
      
      bool from_exists = false;
      bool to_exists = false;
      
	for(int i=0; i< count; i++)
	{
	  if(from_exists == false)
	  {
	    if(node[i].info == fromVertex)
	    {
	      from_exists = true;
	      indexFrom = i;
	    }
	  }
	  if(to_exists == false)
	  {
	    if(node[i].info == toVertex)
	    {
	      to_exists = true; 
	      indexTo = i;
	    }
	  }
      }
      node[indexFrom].edge[node[indexFrom].countAdj].connIndex = indexTo;
      node[indexFrom].edge[node[indexFrom].countAdj].edgeWeight = weight;
      node[indexFrom].countAdj++;
      
      node[indexTo].edge[node[indexTo].countAdj].connIndex = indexFrom;
      node[indexTo].edge[node[indexTo].countAdj].edgeWeight = weight;
      node[indexTo].countAdj++;
    }
    edgeCountNum+=1;
  }
    
  template<class Type>
  void Graph<Type>::dump() const
  {
    string type;
    string weight;
//     
    if(weigh == 0)
      weight = "WEIGHTED";
    else
      weight = "UNWEIGHTED";
    
    if(direction == 0)
      weight = "DIRECTED";
    else
      weight = "UNDIRECTED";
//     
    cout << "dumping graph: " << type << "   " << weight  << "    vertices:" << vertexCount() << "    edges:" << edgeCount() << endl;
    cout << left << setw(25) <<  "VERTEX " << setw(50) << "ADJACENT VERTICES" << endl;
    cout << left << setw(25) <<  "-----------------" << setw(50) << "---------------------------------------------------" << endl;
    

    for(int i=0; i <count; i++)
    {
      cout << setw(1) << "[" << setw(1) << i << setw(3) << "]"  << setw(17) << node[i].info;
      for(int j = 0; j< node[i].countAdj; j++)
      {
	cout << "[" << node[i].edge[j].connIndex << "]" << node[node[i].edge[j].connIndex].info << "(" << node[i].edge[j].edgeWeight << ")    ";
      }
      cout << endl;
    }
  }
    
  template<class Type>
  bool Graph<Type>::isAdjacentTo(const Type& fromVertex, const Type& toVertex) const throw (std::logic_error)
  {
    int indexFrom;
    int indexTo;
    
    bool isAdjacent = false;
    
    bool from_exists = false;
    bool to_exists = false;

    for(int i=0; i< count; i++)
      {
	if(from_exists == false)
	{
	  if(node[i].info == fromVertex)
	  {
	    from_exists = true;
	    indexFrom = i;
	  }
	}
	if(to_exists == false)
	{
	  if(node[i].info == toVertex)
	  {
	    to_exists = true; 
	    indexTo = i;
	  }
	}
      }

      try
      {
      if((from_exists == false) || to_exists == false )
	throw std::logic_error("Either or both of the vertices don't exist in the graph. Cannot check adjacency");
      
	for(int i=0; i< node[indexFrom].countAdj; i++)
	{
	  if(indexTo == node[indexFrom].edge[i].connIndex) 
	  {
	    isAdjacent = true;
	    break;
	  }
	}
      }
      catch(const std::logic_error bad_item)
      {
	cerr << "logic_error: " << bad_item.what() << '\n';
      }
      return isAdjacent;
  }

  template<class Type>
  int Graph<Type>::vertexCount() const
  {
    return  count;
  }
  
  template<class Type>
  int Graph<Type>::edgeCount() const
  {
    return  edgeCountNum;
  }
      
  template<class Type>
  int Graph<Type>::edgeWeight(const Type& fromVertex,const Type& toVertex) const throw (std::logic_error)
  {
    int indexFrom;
    int indexTo;
    
    bool isAdjacent = false;
    
    bool from_exists = false;
    bool to_exists = false;
    
    bool edgeExist = false;
    
    int edgeWeightNum = -1;

    for(int i=0; i< count; i++)
    {
      if(from_exists == false)
      {
	if(node[i].info == fromVertex)
	{
	  from_exists = true;
	  indexFrom = i;
	}
      }
      if(to_exists == false)
      {
	if(node[i].info == toVertex)
	{
	  to_exists = true; 
	  indexTo = i;
	}
      }
    }
    try
    {
      for(int i=0; i< node[indexFrom].countAdj; i++)
      {
	if(indexTo == node[indexFrom].edge[i].connIndex) 
	{
	  edgeExist = true;
	  edgeWeightNum = node[indexFrom].edge[i].edgeWeight;
	  break;
	}
      }
    if(edgeExist == false)
      throw std::logic_error("Following edege doesn't exist. -1");
    }
    catch(const std::logic_error bad_item)
    {
      cerr << "logic_error: " << bad_item.what() << '\n';
    }
    return edgeWeightNum;
  } 
       
  template<class Type>
  void Graph<Type>::deleteEdge(const Type& fromVertex, const Type& toVertex) throw (std::logic_error)
  {
    int indexFrom;
    int indexTo;
    
    bool isAdjacent = false;
    
    bool from_exists = false;
    bool to_exists = false;
    
    int edgeWeightNum;
    
    int deleteIndex;

    for(int i=0; i< count; i++)
    {
      if(from_exists == false)
      {
	if(node[i].info == fromVertex)
	{
	  from_exists = true;
	  indexFrom = i;
	}
      }
      if(to_exists == false)
      {
	if(node[i].info == toVertex)
	{
	  to_exists = true; 
	  indexTo = i;
	}
      }
    }
    if(direction == 0)
    {
      try
      {
	if((from_exists == false) || to_exists == false )
	    throw std::logic_error("Either or both of the vertices don't exist in the graph. Couldn't perform deletion");
      
	bool edgeExists = false;
	for(int i = 0; i < node[indexFrom].countAdj; i++)
	{
	  if(node[indexFrom].edge[i].connIndex == indexTo)
	  {
	    deleteIndex = i;
	    edgeExists = true;
	    break;
	  }
	}

	try
	{
	  if(edgeExists == false)
	    throw std::logic_error("Edge don't exist between the 2 vertices. Couldn't perform deletion");
	  
	  int j = 0;
	  while(j != deleteIndex)
	  {
	    j++;
	  }
	  
	  while(j < node[indexFrom].countAdj)
	  {
	    node[indexFrom].edge[j] = node[indexFrom].edge[j +1];
	    j++;
	  }
	  node[indexFrom].countAdj--;
	}
	catch(const std::logic_error bad_item)
	{
	  cerr << "logic_error: " << bad_item.what() << '\n';
	}
      }
      catch(const std::logic_error bad_item)
      {
	cerr << "logic_error: " << bad_item.what() << '\n';
      }
    }
    else if(direction == 1) // it undirected we gotta delete from both
    {
      try
      {
	if((from_exists == false) || to_exists == false )
	    throw std::logic_error("Either or both of the vertices don't exist in the graph. Couldn't perform deletion");
      
	bool edgeExists = false;
	for(int i = 0; i < node[indexTo].countAdj; i++)
	{
	  if(node[indexTo].edge[i].connIndex == indexFrom)
	  {
	    deleteIndex = i;
	    edgeExists = true;
	    break;
	  }
	}
	  
	int j = 0;
	while(j != deleteIndex)
	{
	  j++;
	}
	
	while(j < node[indexTo].countAdj)
	{
	  node[indexTo].edge[j] = node[indexTo].edge[j +1];
	  j++;
	}
	node[indexTo].countAdj--;
	
	bool edgeExistss = false;
	for(int i = 0; i < node[indexFrom].countAdj; i++)
	{
	  if(node[indexFrom].edge[i].connIndex == indexTo)
	  {
	    deleteIndex = i;
	    edgeExistss = true;
	    break;
	  }
	}
	int k = 0;
	while(k != deleteIndex)
	{
	  k++;
	}
	
	while(k < node[indexFrom].countAdj)
	{
	  node[indexFrom].edge[k] = node[indexFrom].edge[k +1];
	  k++;
	}
	node[indexFrom].countAdj--;
      }
      catch(const std::logic_error bad_item)
      {
	cerr << "logic_error: " << bad_item.what() << '\n';
      }
    } 
    edgeCountNum-=1;
  }

  template<class Type>
  void Graph<Type>::deleteVertex(const Type& vertex) throw (std::logic_error)
  {
    int vertexIndexNumDelete;
    bool vertex_exists = false;
    
    int edgeWeightNum;
    
    int deleteIndex;

    for(int i=0; i< count; i++)
    {
      if(vertex_exists == false)
      {
	if(node[i].info == vertex)
	{
	  vertex_exists = true;
	  vertexIndexNumDelete = i;
	}
      }
    }
    try
    {
      if(vertex_exists == false)
	throw std::logic_error("Vertex doesn't exist in the graph. Couldn't perform deletion");
    
      //first delete all the relationships that the vertex has with other vertices
      for(int i=0; i<count; i++)
      {
	for(int j=0; j < node[i].countAdj; j++)
	{
	  if(node[i].edge[j].connIndex == vertexIndexNumDelete)
	  {
	    deleteEdge(node[i].info,node[vertexIndexNumDelete].info);
	  }
	  else{} //do nothing
	}
      }
      
      //then delete the vertex itself
      int j = 0;
      while(j != vertexIndexNumDelete)
      {
	j++;
      }
  
      while(j < count)
      {
	node[j] = node[j +1];
	node[j].vertexIndex = j;
	j++;
      }
      count--;
    }
    catch(const std::logic_error bad_item)
    {
      cerr << "logic_error: " << bad_item.what() << '\n';
    }
  }
    
  template<class Type>
  int Graph<Type>::findVertex(const Type& vertex) const
  {
    int vertexIndex = -1;
    bool exists = false;

    for(int i=0; i< count; i++)
    {
      if(exists == false)
      {
	if(node[i].info == vertex)
	{
	  exists = true;
	  vertexIndex = i;
	}
      }
    }
      return vertexIndex;
  }

  template<class Type>
  void Graph<Type>::destroy()
  {
    delete [] node;
    node = new Vertex<Type>[100];
    count = 0;
    edgeCountNum = 0;
  }

  template<class Type>
  Graph<Type>::~Graph()
  {
    delete [] node;
  }


  template<class Type>
  const Graph<Type>& Graph<Type>::operator= (const Graph<Type>& otherGraph)
  {
    node = new Vertex<Type>[100];
    
    weigh = otherGraph.weigh;
    direction = otherGraph.direction;
    count = otherGraph.count;
    edgeCountNum = otherGraph.edgeCountNum;
    
    for(int i=0; i<otherGraph.count; i++)
    {
      node[i] = otherGraph.node[i];
    }
    return *this;
  }
  
  //copy constructor
  template<class Type>
  Graph<Type>::Graph(const Graph<Type>& otherGraph) 
  {
    node = new Vertex<Type>[100];
    
    weigh = otherGraph.weigh;
    direction = otherGraph.direction;
    count = otherGraph.count;
    edgeCountNum = otherGraph.edgeCountNum;
    
    for(int i=0; i<otherGraph.count; i++)
    {
      node[i] = otherGraph.node[i];
    }
  }
}
#endif

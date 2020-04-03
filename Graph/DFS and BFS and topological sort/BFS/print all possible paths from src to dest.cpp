/* Print all paths from a given source to a destination using BFS
Algorithm :

create a queue which will store path(s) of type vector
initialise the queue with first path starting from src

Now run a loop till queue is not empty
   get the frontmost path from queue
   check if the lastnode of this path is destination
       if true then print the path
   run a loop for all the vertices connected to the
   current vertex i.e. lastnode extracted from path
      if the vertex is not visited in current path
         a) create a new path from earlier path and 
             append this vertex
         b) insert this new path to queue*/

// utility function for finding paths in graph 
// from source to destination 
void findpaths(vector<vector<int> >&g, int src,  
                                 int dst, int v) 
{ 
    // create a queue which stores 
    // the paths 
    queue<vector<int> > q; 
  
    // path vector to store the current path 
    vector<int> path; 
    path.push_back(src); 
    q.push(path); 
    while (!q.empty()) { 
        path = q.front(); 
        q.pop(); 
        int last = path[path.size() - 1]; 
  
        // if last vertex is the desired destination 
        // then print the path 
        if (last == dst)  
            printpath(path);         
  
        // traverse to all the nodes connected to  
        // current vertex and push new path to queue 
        for (int i = 0; i < g[last].size(); i++) { 
            if (isNotVisited(g[last][i], path)) { 
                vector<int> newpath(path); 
                newpath.push_back(g[last][i]); 
                q.push(newpath); 
            } 
        } 
    } 
} 
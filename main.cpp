// ==================== This code is contibuted by David DEGBEY using different sources ==========================

#include <bits/stdc++.h>
#include <iostream>
#include<iomanip>
using namespace std;
#include <vector>
#include <queue>
#define MAX 1000


//=================================begin stack============================
//define a class Stack
class Stack {
	int top;

public:
	int a[MAX]; // Maximum size of Stack
  int stack_capacity; 
	Stack() { top = -1; }
	bool push(int x);
	int pop();
	//int peek();
	bool isEmpty();
	bool isFull();
	bool DisplayStack();
	bool MakeEmpty();
};

//define 6 stack methods 
bool Stack::push(int x)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top] = x;
		cout << " " << x << " pushed into stack\n";
		return true;
	}
}


int Stack::pop()
{
	if (top < 0) {
		cout << "Stack Underflow";
		return 0;
	}
	else {
		int x = a[top--];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}

bool Stack::isFull()
{
	return (top >= (MAX - 1));
}

bool Stack::MakeEmpty()
{
        
        bool temp=false;
        while(top>=0)
          {
                top--;
                temp=true;           
          }        
        return temp;
}

bool Stack::DisplayStack()
{

        bool temp=false;
        if(top>=0)
        {
           cout << "\nThe stack contains the following element\n";
           temp=true;
        
        for (int j=0;j<=top;j++)
		{
		     cout << "\nItem number " << j << " is " << a[j] << endl;
		} 	     
	}
	
return temp;
}
//========================end stack===============================================



// =======================begin queue=============================================
// CPP program for array 
// implementation of queue 

// A structure to represent a queue 
class Queue { 
public: 
	int front, rear, size; 
	unsigned capacity; 
	int* array; 
}; 

// function to create a queue 
// of given capacity. 
// It initializes size of queue as 0 
Queue* createQueue(unsigned capacity) 
{ 
	Queue* queue = new Queue(); 
	queue->capacity = capacity; 
	queue->front = queue->size = 0; 

	// This is important, see the enqueue 
	queue->rear = capacity - 1; 
	queue->array = new int[( 
		queue->capacity * sizeof(int))]; 
	return queue; 
} 

// Queue is full when size 
// becomes equal to the capacity 
int isFull(Queue* queue) 
{ 
	return (queue->size == queue->capacity); 
} 

// Queue is empty when size is 0 
int isEmpty(Queue* queue) 
{ 
	return (queue->size == 0); 
} 


// Function to add an item to the queue. 
// It changes rear and size 
void enqueue(Queue* queue, int item) 
{ 
	if (isFull(queue)) 
		return; 
	queue->rear = (queue->rear + 1) 
				% queue->capacity; //circular queue
	queue->array[queue->rear] = item; 
	queue->size = queue->size + 1; 
	cout << item << " enqueued to queue\n"; 
} 

// Function to remove an item from queue. 
// It changes front and size 
int dequeue(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	int item = queue->array[queue->front]; 
	queue->front = (queue->front + 1) 
				% queue->capacity; 
	queue->size = queue->size - 1; 
	return item; 
} 

//function to make the queue empty
bool MakeEmptyQ(Queue* queue)
{
        
        bool temp=false;
        bool control = isEmpty(queue);
        while(!control)
          {
                temp=true;
                dequeue(queue);
                control=isEmpty(queue);  

          }        
        return temp;
}

//function to display the queue
void DisplayQueue(Queue* queue)
{

      if(!isEmpty(queue))
      {
        cout << "\nThe queue contains the following elements\n";
        for (int j = queue->front; j <=(queue->rear); ++j)
        {
          cout << "\n" << queue->array[j] << "\n";
        }
      }
      else cout << "The queue is empty";

}


// Function to get front of queue 
int front(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->front]; 
} 

 

// Function to get rear of queue 
int rear(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->rear]; 
} 

// ======================= end queue =============================================== 




// ===================== begin selection sort ==========================================

void swap(int *xp, int *yp) 
{ 
  int temp = *xp; 
  *xp = *yp; 
  *yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
  int i, j, min_idx; 

  // One by one move boundary of unsorted subarray 
  for (i = 0; i < n-1; i++) 
  { 
    // Find the minimum element in unsorted array 
    min_idx = i; 
    for (j = i+1; j < n; j++) 
    if (arr[j] < arr[min_idx]) 
      min_idx = j; 

    // Swap the found minimum element with the first element 
    swap(&arr[min_idx], &arr[i]); 
  } 
} 

// ===================== end selection sort ============================================


// ===================== begin merge sort ========================================

void merge(int arr[], int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create temp arrays
  int L[n1], R[n2];

  // Copy data to temp arrays L[] and R[]
  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  // Merge the temp arrays back into arr[l..r]

  // Initial index of first subarray
  int i = 0;

  // Initial index of second subarray
  int j = 0;

  // Initial index of merged subarray
  int k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    }
    else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of
  // L[], if there are any
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of
  // R[], if there are any
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}


// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
  if(l>=r){
    return;//returns recursively
  }
  int m =l+ (r-l)/2;
  mergeSort(arr,l,m);
  mergeSort(arr,m+1,r);
  merge(arr,l,m,r);
}



// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
  cout << "\n";
  for (int i = 0; i < size; i++)
    cout << A[i] << " ";
  cout << "\n";
}

// ===================== end merge sort ==========================================




// ========= begin sequential search =============================================

int Seq_Search()

{
 
  int taille;
  int tableau[MAX];
  int k;
  bool found;

  cout << "Enter the number of elements of your array: ";
  cin >> taille;

for (int j = 0; j < taille; j++) 
 {
  cout << "tableau[" << j << "]: ";
  cin >> tableau[j];
 }

 cout << "Enter the key value to search: ";
 cin >> k;
 for (int j = 0; j < taille; j++) 
    {
      if (k == tableau[j]) 
          {
            found = true;
            cout << "The value is found at index tableau[" << j << "]\n";
          }
    }
 if (!found) {cout << "Key not found!";}

 return 0;
}
// ========= end sequential search =====================

                        
// ========= begin binary search =====================

// A recursive binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1 
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 

        // If the element is present at the middle 
        // itself 
        if (arr[mid] == x) 
            return mid; 

        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 

        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 

    // We reach here when element is not 
    // present in array 
    return -1; 
} 
// ==================== end binary search function ============= 


// ==================== Begin trees ===========================

struct Node 
{ 
  int data; 
  Node* left, * right; 
}; 

/* Helper function that allocates a 
new node */
Node* newNode(int data) 
{ 
  Node* node = (Node*)malloc(sizeof(Node)); 
  node->data = data; 
  node->left = node->right = NULL; 
  return (node); 
} 

// Function to insert nodes in level order 
Node* insertLevelOrder(int arr[], Node* root, 
          int i, int n) 
{ 
  // Base case for recursion 
  if (i < n) 
  { 
    Node* temp = newNode(arr[i]); 
    root = temp; 

    // insert left child 
    root->left = insertLevelOrder(arr, 
        root->left, 2 * i + 1, n); 

    // insert right child 
    root->right = insertLevelOrder(arr, 
        root->right, 2 * i + 2, n); 
  } 
  return root; 
} 

// Function to print tree nodes in 
// InOrder fashion 
void inOrder(Node* root) 
{ 
  if (root != NULL) 
  { 
    
    inOrder(root->left); 
    cout << root->data <<" "; 
    inOrder(root->right); 
  } 
}

/* Given a binary tree, print its nodes according to the 
"bottom-up" postorder traversal. */
void printPostorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(node->left); 
  
    // then recur on right subtree 
    printPostorder(node->right); 
  
    // now deal with the node 
    cout << node->data << " "; 
} 

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    cout << node->data << " "; 
  
    /* then recur on left sutree */
    printPreorder(node->left);  
  
    /* now recur on right subtree */
    printPreorder(node->right); 
} 

// =========== End trees =============================



// =========== Begin Graphs ==========================

//int  visited[100] = {0};


// A function to print the matrix.
void PrintMat(int **mat, int n)
{
  int i, j;
 
  cout<<"\n\n"<<setw(4)<<"";
  for(i = 0; i < n; i++)
    cout<<setw(3)<<"("<<i<<")";
  cout<<"\n\n";
 
  // Print 1 if the corresponding vertexes are connected otherwise 0.
  for(i = 0; i < n; i++)
  {
    cout<<setw(3)<<"("<<i<<")";
    for(j = 0; j < n; j++)
    {
      cout<<setw(4)<<mat[i][j];
    }
    cout<<"\n\n";
  }

}



// Function to perform BFS on the graph
void BFS(int start, vector<bool>& visited1, int** tab1, int nb)
{
    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning
    
    vector<int> q;
    q.push_back(start);
 	
    // Set source as visited
    visited1[start] = true;
 
    int vis;
    while (!q.empty()) {
        vis = q[0];
 
        // Print the current node
        cout << vis << " ";
        q.erase(q.begin());
 
        // For every adjacent vertex to the current vertex
        for (int i = 0; i < nb; i++) {
            if (tab1[vis][i] == 1 && (!visited1[i])) {
 
                // Push the adjacent node to the queue
                q.push_back(i);
 
                // Set
                visited1[i] = true;
            }
        }
    }
}

void DFS(int start_up, vector<bool>& visited, int** tab, int nb) 
{ 
  
 //Print the current node 
    cout << start_up << " "; 
  
    // Set current node as visited 
    visited[start_up] = true; 
  
    // For every node of the graph 
    for (int i = 0; i < nb; i++) { 
  
        // If some node is adjacent to the current node 
        // and it has not already been visited 
        if (tab[start_up][i] == 1 && (!visited[i])) { 
            DFS(i, visited, tab, nb); 
        } 
    } 
    
} 


// =========== End Graphs ============================


//function to show the principal menu


void showmenu(){

  cout<<"\n=================================\n";
  cout<<" Data structure Operations Menu\n";
  cout<<"=================================\n";
  cout<<"1.Managing a Stack\n";
  cout<<"2.Managing a Queue\n";
  cout<<"3.Sorting algorithms\n";
  cout<<"4.Searching algorithms\n";
  cout<<"5.Tree traversals\n";
  cout<<"6.Graph traversals\n";
  cout<<"7.Exit\n";


}


//function to select an option
//Driver of the great program
int main()

{

  int v, el, v1, v2;
  
  int debut, val, pos, ch, res, n, start_BFS, start_DFS;
  int n_q=1, donnee, j=0; // for the queue
  int g, e, compt=0, result; // for the Bin search
  int arr_bin[MAX]; // bin search
  int arr_mer[g]; // merg sort array
  int arr_sel[g]; // sel sort array
  
  int *tab = new int[g]; // for trees 
  Node* root;

  int n_graph, graph1; // for graphs
  std::vector<bool> visit2(MAX, false);
  std::vector<bool> visit(MAX, false);
  //vector<bool>visited(v, false);
  //vector<bool>visited1(v, false);
  
   
  char yes='y';
  
  class Stack s;
  Queue* queue = createQueue(1000); 
  
  main_menu:  
  
  
  while(yes=='y')
        {
            showmenu();
            cout<<"\nEnter your choice (for main menu): ";
            cin>>ch;
            cout << "\n";
            int nbre_ajout=0; // for stack
            
                                    
    switch(ch){
      
       case 1:
                  stack_menu:
                  cout<<"\n=================================\n";
                  cout<<"  Stacks Menu\n";
                  cout<<"=================================\n";
                  cout<<"1.Push a new item\n";
                  cout<<"2.Pop an item\n";
                  cout<<"3.Make the stack empty\n";
                  cout<<"4.Display all items of the stack\n";
                  cout<<"5.Check if the stack is empty\n";
                  cout<<"6.Check if the stack is full\n";
                  cout<<"7. Go back\n";
                  cout<<"\nEnter your stack choice...(for a first run, it is compulsory to choose option 1 or 7): ";
                  
                  cin >> res;
                  
                  switch(res){
                        
                        case 1: 
                        
                        cout << "\n You have chosen to push a new item to the stack\n";
      	                cout << "\n How many values do you want to push?: ";
                        cin >> nbre_ajout;

                        for (int j = 0; j < nbre_ajout; ++j)
                        {
                          cout << "\n Enter the next element to push?: ";
                          cin >> n;
                          s.push(n); 
                          s.stack_capacity++;
                        }
      	                       
                        break;
                        
                        case 2:
                        cout << "\nyou have chosen to pop an item\n";
                        cout << s.pop() << " Popped from stack\n";
                        break;
                        
                        case 3:
                        cout << "\n You have chosen to make the stack empty\n";
                                if(s.MakeEmpty())
                                cout << "\n Make Stack Empty successful \n";
                                else 
                                cout << "\n Make Stack Empty was not succesful check if the stack is \n";
                        break;
                        
                        case 4:
                        cout << "\n You have chosen to display all items of the stack\n";
                        //s.DisplayStack();
                        if(!s.DisplayStack()) cout << "\n the stack is empty\n";

                        break;
                        
                        case 5:
                        cout << "\n You have chosen to check wether if the stack is empty\n";
                        if(s.isEmpty()) 
                          {
                            cout << " The stack is empty\n";
                          }
                        else cout << " The stack is not empty\n";
                        break;
                        
                        case 6:
                        cout << "\n You have chosen to check wether if the stack is full\n";
                        if(s.isFull()) 
                          {
                            cout << " The stack is full\n";
                          }
                        else cout << " The stack is not full\n";
                        break;
                        
                        case 7: goto main_menu;
                             
                             }
          
           break;
           
       case 2:
                  queue_menu:
                  cout<<"\n=================================\n";
                  cout<<"  Queue Menu\n";
                  cout<<"=================================\n";
                  cout<<"1.Insert a new item to the queue \n";
                  cout<<"2.Delete an item from the queue \n";
                  cout<<"3.Make the queue empty\n";
                  cout<<"4.Display all items of the queue\n";
                  cout<<"5.Check if the queue is empty\n";
                  cout<<"6.Check if the queue is full\n";
                  cout<<"7.Exit\n";

                  cout << "Enter your choice for Queue: ";
                                    
                  cin >> res;
                  
                  switch(res){
                                        
                        case 1:
                        cout << "\n You have chosen to insert a new item to the queue \n";
                                
                                cout << "\n How many items do you want to add: ";
                                cin >> n_q;
                                j=0;
                                
                                while(j<n_q)
                                     {
                                        cout << "\n Enter the new item to add to the queue: ";
                                        cin  >> donnee;
                                        enqueue(queue, donnee); 
                                        j++;
                                     }
                        break;
                        
                        case 2:
                        cout << "\n you have chosen to delete an item from the queue \n";
                                        cout << " " << dequeue(queue) << " dequeued from queue \n"; 
                        break;
                        
                        case 3:
                        cout << "\nYou have chosen to make the queue empty \n";
                        MakeEmptyQ(queue);
                        if(MakeEmptyQ(queue)) cout << "operation MakeEmpty successful\n";
                        else cout << "operation MakeEmpty successful\n"; 
                        break;
                        
                        case 4:
                        cout << "\nYou have chosen to display all items of the queue\n";
                        DisplayQueue(queue);
                        break;
                        
                        case 5:
                        cout << "\nYou have chosen to check wether if the queue is empty\n";
                        if(isEmpty(queue)) cout << "The queue is empty";
                        else cout << "\n The queue is not empty \n";
                        break;
                        
                        case 6:
                        cout << "\nYou have chosen to check wether if the queue is full\n";
                        if(isFull(queue)) cout << "The queue is full";
                        else cout << "\n The queue is not full yet ...\n";
                        break;
                        
                        case 7: goto main_menu;
                             
                             }
                 
          break;

       case 3:
                  sorting_menu:
                  cout<<"\n=================================\n";
                  cout<<"  Sorting algorithms menu\n";
                  cout<<"=================================\n";
                  cout<<"1.Selection sort\n";
                  cout<<"2.Merge sort\n";
                  cout<<"3.Exit\n";
                  
                  cout << "\nEnter your Sort option: ";

                  cin >> res;
                  
                  switch(res){
                        
                        case 1:
                        cout << "\nyou have chosen the selection sort algorithm\n";
                        cout << "\nHow many numbers do you want to sort ?: ";
                        cin >> g;
                        for (int j = 0; j < g; ++j)
                        {
                          cout << "\n Element no " << j << ": ";
                          cin >> arr_sel[j];
                        }
                        selectionSort(arr_sel, g);
                        cout << "\n Sorted array: \n"; 
                        cout << "\n";
                        printArray(arr_sel, g);

                        break;
                        
                        case 2:
                        cout << "\nyou have chosen the merge sort algorithm\n";
                        cout << "\nHow many numbers do you want to sort ?: \n";
                        cin >> g;
                        
                        for (int j = 0; j < g; ++j)
                        {
                          cout << " Element no " << j << ": ";
                          cin >> arr_mer[j];
                        }

                        
                        cout << "Given array is \n";
                        printArray(arr_mer, g);

                        mergeSort(arr_mer, 0, g - 1);

                        cout << "\nSorted array is \n";
                        printArray(arr_mer, g);
                        cout << "\n";

                        break;
                        
                        case 3: goto main_menu;
                                                   
                             }
       break;      

       case 4:
                  searching_menu:
                  cout<<"\n=================================\n";
                  cout<<"  Searching algorithms menu\n";
                  cout<<"=================================\n";
                  cout<<"1.Sequential search\n";
                  cout<<"2.Binary search\n";
                  cout<<"3.Exit\n";
                  cout << "Enter your Search option: ";
                  
                  cin >> res;
                  
                  switch(res){
                        
                        case 1:
                        cout << "\nyou have chosen the sequential search algorithm\n";
                        cout << "\n";
                        Seq_Search();
                        
                        break;
                        
                        case 2:
                        cout << "\nyou have chosen the Binary search algorithm\n";
                        cout << "\nEnter the number of elements of your array: ";
                        cin >> g;
                        while(compt<g)
                        {
                            cout << "\n Element no " << compt << ": ";
                            cin >> arr_bin[compt];
                            compt++;
                        }

                        selectionSort(arr_bin,g);

                        cout << "\n Your sorted array is: \n"; 
                        printArray(arr_bin,g);


                        cout << "\nEnter the key element to search: ";
                        cin >> e;

                        //n_bin= sizeof(arr_bin) / sizeof(arr_bin[0]); 
                        result = binarySearch(arr_bin, 0, g - 1, e); 
                        (result == -1) ? cout << "\nElement is not present in array\n"
                                    : cout << "\nElement is present at index " << result <<"\n"; 

                        break;
                        
                        case 3: goto main_menu;
                                                   
                             }
              
        break;

        case 5: 

              tree_menu:
              cout << "\nEnter the number of nodes of your binary tree: ";
              cin >> g;

              // creation of a dynamic array tab which elements are the nodes of the tree
              for (int j = 0; j < g; ++j)
                        {
                          cout << "\n Node no " << j << ": ";
                          cin >> tab[j];
                        }

              

              // printing the corresponding array
              cout << "\nYou have entered a binary tree with the following list: \n";
                         for (int j = 0; j < g; ++j)
                        {
                          cout << "--" << tab[j];
                        }
              cout << "\n";
       
              cout<<"\n=================================\n";
              cout<<"  Trees traversals menu\n";
              cout<<"=================================\n";
              cout<<"1.InOrder traversal\n";
              cout<<"2.PreOrder traversal\n";
              cout<<"3.PostOrder traversal\n";
              cout<< "\nEnter your tree traversal option: ";

              cin >> res;

                    switch(res) {

                    case 1:
                    cout << "\nInOrder traversal result: ";
                    root = insertLevelOrder(tab, root, 0, g);
                    inOrder(root);
                    delete [] tab;
                    break;

                    case 2:
                    cout << "\nPreOrder traversal result: ";
                    root = insertLevelOrder(tab, root, 0, g);
                    printPreorder(root);
                    delete [] tab;                    
                    break;

                    case 3:
                    cout << "\nPostOrder traversal result: ";
                    root = insertLevelOrder(tab, root, 0, g);
                    printPostorder(root);
                    delete [] tab;
                    break;

                    }


        break;
      
      case 6:
            cout << "\nYou have chosen to work on graphs: \n";
            //cout << "\nEnter the number of vertices of your graph: ";
            //cin >> n_graph;
             

             // take the input of the number of edges.
			  cout<<"Enter the number of vertices of the graph: ";
			  cin>>v;
			 
			  // Dynamically declare graph.
			  int **graph, **graph1, st;
			  graph = new int*[v];
			  graph1 = new int*[v];

			  
			  for(int i = 0; i < v; i++)
			  {
			    graph[i] = new int[v];
			    for(int j = 0; j < v; j++)graph[i][j] = 0;
			  }
			 
			  cout<<"\nEnter the number of edges of the graph: ";
			  cin>>el;
			 
			 
			  // Take the input of the adjacent vertex pairs of the given graph.
			  for(int i = 0; i < el; i++)
			  {
			    cout<<"\nEnter the vertex pair for edge "<<i+1;
			    cout<<"\nV(1): ";
			    cin>>v1;
			    cout<<"V(2): ";
			    cin>>v2;
			 
			    graph[v1-1][v2-1] = 1;
			    graph[v2-1][v1-1] = 1;
			  }
			 
			  // Print the 2D array representation of the graph.
			  PrintMat(graph, v);


			  cout << "\n Enter the vertex Start to perform BFS algorithms: ";
			  cin >> start_BFS;
			  cout << "\nBFS traversal result: ";
			  BFS(start_BFS, visit, graph, v);

			  cout << "\n";

			  cout << "\n Enter the vertex Start to perform DFS algorithms: ";
			  cin >> debut;
			  cout << "\nDFS traversal result: ";
			  DFS(debut, visit2, graph, v);
			  
           
            
            cout << "\n";
                                              
            cout << "\n";
            cout << "\n";


      break;

      case 7: exit(0);

      default: cout<<"\nInvalid choice\nt";

       }
       
   cout<<"\nContinue? [y/n]: ";
   cin>>yes;
   }
   
   return 0;

}


      
        
        
       


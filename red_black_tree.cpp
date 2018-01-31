/****************************************************************************************************************************************
Author: Venkata Sai Vamsi Komaravolu

Date: 25th December 2017

File Name: red_black_tree.h

Algorithm:
Algorithm of the Red Black Tree behavior is obtained from "Introduction to Algorithms" textbook by Thomas H. Cormen, Charles E. Leiserson,
Ronald L. Rivest, Clifford Stein

Coding Style:
Coding Style is based on the experience gained from working on the header files of the Simple-Scalar processor for "Segmented-LRU" project.

Description:

Red Black Tree:
Red-Black Tree is a self-balancing Binary Search Tree (BST). Most of the BST operations (e.g., search, max, min, insert, delete.. etc)
take O(h) time where h is the height of the BST. The cost of these operations may become O(n) for a skewed Binary tree.
If we make sure that height of the tree remains O(Logn) after every insertion and deletion, then we can guarantee an upper bound 
of O(Logn) for all these operations. The height of a Red Black tree is always O(Logn) where n is the number of nodes in the tree.

Following are the rules followed by a Red-Black Tree:

1. Each node is either red or black.

2. The root is black. This rule is sometimes omitted. Since the root can always be changed from red to black, 
   but not necessarily vice versa, this rule has little effect on analysis.

3. All leaves (NIL) are black.

4. If a node is red, then both its children are black.

5. Every path from a given node to any of its descendant NIL nodes contains the same number of black nodes. 


Program Description:

This C++ implementation of the R-B Tree performs a variety of operations. They are:

1. Insertion of a node in the Red-Black Tree.

2. Deletion of a node in the Red-Black Tree.

3. Finding a node in the Red-Black Tree.

4. Minimum node of the Red-Black Tree.

5. Maximum node of the Red-Black Tree.

8***************************************************************************************************************************************/

/**********************************************************************************************************
This C++ implementation uses template class because various data-types can be passed as arguments to it, 
i.e., this Red-Black Tree behavior can be extended for different data-types, say for int, double, char, etc.

For this program, there are two access modifiers namely "public" and "private"

Functions under "public" can be accessed by the user directly - Here, They are Insert_Node, Delete Node,  
Find_Node, Maximum_Node, Minimum Node and Display functions.

Functions under "private" cannot be accessed by the user directly, but can be accessed by the functions
in the public section. Here, the functions in the private section are left_rotate, right_rotate, Display,
structures Node, minimum, Tree_Successor and enum Node_colour.

**********************************************************************************************************/

#include <iostream>
using namespace std;																	//namespace for standard library functions 

template<typename Node_key, typename Node_value>  										//Template with the data-types passed as arguments 
class Red_Black_Tree							
{
    public:																				 
    Red_Black_Tree() : root(NULL)														//constructor performs this operation when the object is first created
    {																					//Here it sets the root to NULL
    }

/***********************************************************************************************	
	Insert_Node()- This function performs the insertion of the node in the red-black tree.
				   Firstly, it finds the location to Insert the node based on the key value
				   provided by the user. Later, based on the several conditions based on the 
				   algorithm, locations and colors of the nodes in the tree are adjusted.
***********************************************************************************************/				   
	
  void Insert_Node(const Node_key& key, const Node_value& value)						//key and value of the node to be inserted are provided
    {
        Node *node, *parent, *z, *u;						
        parent = NULL;									
        node = root;									
        
        while (node)																	//Finding the locations for the node to be inserted					
        {
            parent = node;								
            if (key < node->key) 							
            {												
                node = node->left;								
            }
            else if (key > node->key)						
            {
                node = node->right;
            }
        }

        if (!parent)																	//If parent does not exist, the node to be inserted is the root of the tree									
        {
            z = root = new Node;							
            z->key = key;									
            z->value = value;								
            z->colour = BLACK;							
            z->parent = z->left = z->right = NULL;		
        }
        
        else																			//Else, new node is inserted at the appropriate location										
        {
            z = new Node;									
            z->key = key;									
            z->value = value;								
            z->colour = RED;								
            z->parent = parent;							
            z->left = z->right = NULL;					

            if (z->key < parent->key)						
            {												
                parent->left = z;
            }
            else											
            {												
                parent->right = z;
            }
         }

    									
        while (z->parent && z->parent->colour == RED)	
        {
            if (z->parent == z->parent->parent->left) 									//If the parent of the newly inserted node is to the left of its parent
            {																			//u is placed to the right of its parent and this block of code is executed.
                u = z->parent->parent->right;					
    
                if (u && u->colour == RED)					
                {
                    z->parent->colour = BLACK;							
                    u->colour = BLACK;								
                    z->parent->parent->colour = RED;					
                    z = z->parent->parent;								
                }
                else													
                {
                    if (z == z->parent->right)
                    {														
                        z = z->parent;									
                        left_rotate(z);			
                    }

                z->parent->colour = BLACK;							
                z->parent->parent->colour = RED;
                right_rotate(z->parent->parent); 
                }
        
            }
   
            else 																		//Else if the parent of the newly inserted node is to the right of its parent
            {																			//u is placed to the left of its parent and this block of code is executed.
                u = z->parent->parent->left;					
    
                if (u && u->colour == RED)					
                {
                    z->parent->colour = BLACK;							
                    u->colour = BLACK;								
                    z->parent->parent->colour = RED;					
                    z = z->parent->parent;								
                }
                else													
                {
                    if (z == z->parent->left)
                    {														
                        z = z->parent;									
                        right_rotate(z);			
                    }

                    z->parent->colour = BLACK;							
                    z->parent->parent->colour = RED;
                    left_rotate(z->parent->parent); 
                }
        
            }

            root->colour = BLACK;														//Finally, the root color is made black						
        }

    }
    
/***********************************************************************************************	
	Delete_Node()- This function performs the deletion of the node in the red-black tree.
				   Firstly, it finds the location to deletes the node based on the key value
				   provided by the user. Later, based on the several conditions based on the 
				   algorithm, locations and colors of the nodes in the tree are adjusted.
***********************************************************************************************/				   
   
  void Delete_Node(const Node_key& key)													//key of the node to be inserted are provided
    {
        Node *node = root;								
        Node *y, *x;
     
        while (node)																	//Finding the location of the node to be deleted
        {
            if (key < node->key)							
            {
                node = node->left;							
            }
            else if (key > node->key)						
            {
                node = node->right;
            }
            else
            {
                break;
            }
        }

        cout << "Node to be deleted : " << node->key <<endl;

        if (!node || node->key != key)													//If the node is not found or invalid key is entered, then a run_time error is thrown
        {
            throw runtime_error("Cannot Delete: Node_key not found");
        }
  
        if (!node->left || !node->right )												//From here, the appropriate substitute to the replace the location of the deleted node is found 
        {
            y=node;																		//if the node to be deleted, has no left and right children, then
        }																				// the y is taken as the node itself
  
        else																			//else the tree successor is found and it is taken as y
        {
            y = Tree_Successor(node);							
            y->colour = node->colour;
        }

        if (y->left)																	// if the y has a left child, then it is taken as x
        {
            x = y->left;
        }

        else 																			//else, right child is taken as x
        {
            x = y->right;
        }
   
        if(x)
            x->parent = y->parent;

        if(!y->parent)
        {
            root = x;
        }

        else if (y == y->parent->left)													//if y is the left child of its parent, then it is assigned the value x
        {
            y->parent->left = x;
        }
        
        else																			//else, the right child of y is assigned the value of x
        {
            y->parent->right = x;
        }

        if(y!= node)																	// If y is not equal to node, then copy the satellite of y to the node
        {
            node->key = y->key;
            node->colour = y->colour;
            node->value = y->value;
        }

        if (y->colour == BLACK && x!=NULL)												//if y colour is black and x exists, then this block of code is executed
        {
            Node *w;
            while (x != root && x->colour == BLACK)
            {
                if (x == x->parent->left)												//if x is the left child of its parent, this block of code is executed
                {
                    w = x->parent->right;
        
                    if (w->colour == RED)
                    {
                        w->colour = BLACK;
                        x->parent->colour = RED;
                        left_rotate(x->parent);
                        w =  x->parent->right;
                    }
                    
                    if (w->left->colour == BLACK && w->right->colour == BLACK)
                    {
                        w->colour = RED;
                        x = x->parent;
                    }
        
                    else if (w->right->colour == BLACK)
                    {
                        w->left->colour = BLACK;
                        w->colour = RED;
                        right_rotate(w);
                        w = x->parent->right;
                    }
          
                    w->colour = x->parent->colour;
                    x->parent->colour = BLACK;
                    w->right->colour = BLACK;
                    left_rotate(x->parent);
          
                    x = root;
          
                }
        
                else																	//else, this block of code is executed
                {
                    w = x->parent->left;
    
                    if (w->colour == RED)
                    {
                        w->colour = BLACK;
                        x->parent->colour = RED;
                        right_rotate(x->parent) ;
                        w =  x->parent->left;
                    }


                    if (w->right->colour == BLACK && w->left->colour == BLACK)
                    {
                        w->colour = RED;
                        x = x->parent;
                    }
        
                    else if (w->left->colour == BLACK)
                    {
                        w->right->colour = BLACK;
                        w->colour = RED;
                        left_rotate(w);
                        w = x->parent->left;
                    }
          
                    w->colour = x->parent->colour;
                    x->parent->colour = BLACK;
                    w->left->colour = BLACK;
                    right_rotate(x->parent);
          
                    x = root;
          
                }
        
                x->colour = BLACK;    												//Finally, the colour of x is made black

            }
        }
 
    }



/***********************************************************************************************	
	Find_Node()- This function performs the finding of the node in the red-black tree.
				   Firstly, it finds the value of node based on the key value  provided by the user. 
***********************************************************************************************/	
   
  Node_value& Find_Node(const Node_key& key)											//Key value provided by the user	
    {
        Node *node = root;																//Root of the tree is taken as the starting point
       
        while (node)																	//Node location is found based on the key value
        {
            if (key < node->key  )							
            {
                node = node->left;								
            }
            else if (key > node->key )						
            {
                node = node->right;
            }
        
           else												
           {
               cout << "Node_value found for the key number " << key << " is " << node->value << endl; 
                return node->value;
           }
        
            
        }

        throw runtime_error("Cannot Find: Node_key not found");							//if the node is not found, a runtime error is thrown
    }

	
/***********************************************************************************************	
	Minimum_Node()- This function finds the minimum node of the red-black tree. 
***********************************************************************************************/	

  void Minimum_Node ()
    {
        Node *x =root;																	//root of the tree is taken as the starting point			
    
        while (x->left)																	//the left most node of the tree is located
        {																				//which is nothing but the minimum node of the tree
            x = x->left;
        }

        cout << "Minimum value of the tree is key " << x->key << " and with value " << x->value << endl;
    }

/***********************************************************************************************	
	Maximum_Node()- This function finds the maximum node of the red-black tree. 
***********************************************************************************************/	

  void Maximum_Node ()
    {
        Node *x =root;																	//root of the tree is taken as the starting point
    
        while (x->right)																//the right most node of the tree is located						
        {																				//which is nothing but the maximum node of the tree
            x = x->right;
        }

        cout << "Maximum value of the tree is key " << x->key << " and with value " << x->value << endl;
    }

/***********************************************************************************************	
	Display()- This function displays the red-black tree. 
***********************************************************************************************/	

  void Display()
    {
        Display(root, 0);
    }

//"private" part of the template class which cannot be accessed by outside functions  	
	
private:
  enum Node_colour																			//enum for colour where 0 indicates red and 1 indicates Black
    {
        RED,
        BLACK
    };

  struct Node																			//Node structure with satellite data of colour, key and node value
    {																					//and also information about parent , left child and right child
        Node_colour colour;
        Node_key key;
        Node_value value;
        Node *parent;
        Node *left;
        Node *right;
    };

    Node *root;

  void left_rotate(Node *x)																//Rotates the nodes left based on the conditions of the algorithm
    {
        Node *y;

        y = x->right;
        x->right = y->left;
        
        if (y->left)
        {
            y->left->parent = x;
        }

        y->parent = x->parent;

        if (!x->parent)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
	   
        y->left = x;
        x->parent = y;
    }

 void right_rotate(Node *x)																//Rotates the nodes right based on the conditions of the algorithm
    {
        Node *y;														

        y = x->left;											
        x->left = y->right;
        
        if (y->right)
        {
            y->right->parent = x;
        }

        y->parent = x->parent;

        if (!x->parent)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
	    
	    y->right = x;
        x->parent = y;
  }
  
 Node *Tree_Successor(Node *x) 															//Find the successor of the node in the red black tree
    {
        Node *y;
      
        if(x->right)
        {
            return Minimum(x->right);
        }
         
        y = x->parent;
      
        while(y && x==y->right) 
        {
            x = y;
            y = y->parent;
        }    
     
        return y;
    }    
 
  Node *Minimum(Node *tree)																// Returns the minimum node of the tree
    {
        while (tree->left)											
        {															
            tree = tree->left;
        }

        return tree;
    }


  void Display(Node *node, int spaces)													//Displays the entire red black tree when the function is called
    {
        if (!node)																		//If node does not exist, returns from the function
        {
            return;
        }

        Display(node->left, spaces + 1);													//Displays the left nodes first									

        for (int i = 0; i < spaces; ++i)
        {
            cout << "\t";																//Distance from the root depends on the level of nodes
        }
    
        cout << node->key << (node->colour ? "B" : "R") << endl;						//Displays the key of the node along with its colour

        Display(node->right, spaces + 1);													//Displays the right nodes last
    }

    
};
/***********************************************************************************************
Author: Venkata Sai Vamsi Komaravolu

Date: 25th December 2017

File Name: main.cpp

Description:

Main()- The main function works on the red black tree with the public functions of the 
		template class. We can insert, delete and find nodes and also find the minimum and 
		maximum of the red black tree
***********************************************************************************************/				   

#include "red_black_tree.cpp"                                 							//including the red_black_tree file

int main()														
{
     
    int tree_select = 0;
    
    while(tree_select<10)                           									//looping through multiple types of red black trees
        {
        
        if(tree_select==0)
        {
            cout << "\n" << "***************************************************Tree-0**************************************************************" << "\n" <<endl;
            
            cout << "\n\t\t" << "***********************Tree-0 After Insertion of All Nodes***********************" << "\t\t\n" <<endl; 
            
            Red_Black_Tree<int, int> tree_0;											//passing "int" and "int" data-types for key and values of the node to the template class  
																						//Similarly, several combinations of data-types are passed as arguments below
            for (int i = 1; i <10; ++i)
            {
                tree_0.Insert_Node(i, i);
            }
  
            tree_0.Display();
            
            tree_0.Minimum_Node();
  
            tree_0.Maximum_Node();
  
            cout << "\n\t\t" << "***********************Tree-0 After Deletion of Requested Nodes***********************" << "\t\t\n" <<endl; 
  
            tree_0.Delete_Node(8);
    
            tree_0.Display();
  
            tree_0.Minimum_Node();
  
            tree_0.Maximum_Node();
    
            tree_0.Find_Node(7);
  
        } 
    
        
        if(tree_select==1)
        {
            cout << "\n" << "***************************************************Tree-1**************************************************************" << "\n" <<endl;
            
            cout << "\n\t\t" << "***********************Tree-1 After Insertion of All Nodes***********************" << "\t\t\n" <<endl; 
            
            Red_Black_Tree<float, float> tree_1;										
  
            for (float i = 1.0; i <15.0; ++i)
            {
                tree_1.Insert_Node(i, i+1.5);
            }
  
            tree_1.Display();
            
            tree_1.Minimum_Node();
  
            tree_1.Maximum_Node();
  
            cout << "\n\t\t" << "***********************Tree-1 After Deletion of Requested Nodes***********************" << "\t\t\n" <<endl; 
  
            tree_1.Delete_Node(6);
            tree_1.Delete_Node(3);
    
            tree_1.Display();
  
            tree_1.Minimum_Node();
  
            tree_1.Maximum_Node();
    
            tree_1.Find_Node(7);
  
        } 
    
        if(tree_select==2)
        {
            cout << "\n" << "***************************************************Tree-2**************************************************************" << "\n" <<endl;
            
            cout << "\n\t\t" << "***********************Tree-2 After Insertion of All Nodes***********************" << "\t\t\n" <<endl; 
            
            Red_Black_Tree<int, float> tree_2;									
  
            for (float i = 20; i>0; --i)
            {
                tree_2.Insert_Node(i, i+2.5);
            }
  
            tree_2.Display();
            
            tree_2.Minimum_Node();
  
            tree_2.Maximum_Node();
  
            cout << "\n\t\t" << "***********************Tree-2 After Deletion of Requested Nodes***********************" << "\t\t\n" <<endl; 
  
            tree_2.Delete_Node(2);
            tree_2.Delete_Node(4);
            tree_2.Delete_Node(5);
    
            tree_2.Display();
  
            tree_2.Minimum_Node();
  
            tree_2.Maximum_Node();
    
            tree_2.Find_Node(15);
  
        } 
    
        
        if(tree_select==3)
        {
            cout << "\n" << "***************************************************Tree-3**************************************************************" << "\n" <<endl;
            
            cout << "\n\t\t" << "***********************Tree-3 After Insertion of All Nodes***********************" << "\t\t\n" <<endl; 
            
            Red_Black_Tree<double, double> tree_3;									
  
            for (double i = 25; i >0; --i)
            {
                tree_3.Insert_Node(i+1, i*2);
            }
  
            tree_3.Display();
            
            tree_3.Minimum_Node();
  
            tree_3.Maximum_Node();
  
            cout << "\n\t\t" << "***********************Tree-3 After Deletion of Requested Nodes***********************" << "\t\t\n" <<endl; 
  
            tree_3.Delete_Node(11);
    
            tree_3.Display();
  
            tree_3.Minimum_Node();
  
            tree_3.Maximum_Node();
    
            tree_3.Find_Node(12);
  
        } 
        
        
        if(tree_select==4)
        {
            cout << "\n" << "***************************************************Tree-4**************************************************************" << "\n" <<endl;
            
            cout << "\n\t\t" << "***********************Tree-4 After Insertion of All Nodes***********************" << "\t\t\n" <<endl; 
            
            Red_Black_Tree<int, char> tree_4;									
  
            for (int i = 100; i >65; --i)
            {
                tree_4.Insert_Node(i+1, i-1);
            }
  
            tree_4.Display();
            
            tree_4.Minimum_Node();
  
            tree_4.Maximum_Node();
  
            cout << "\n\t\t" << "***********************Tree-4 After Deletion of Requested Nodes***********************" << "\t\t\n" <<endl; 
  
            tree_4.Delete_Node(70);
    
            tree_4.Display();
  
            tree_4.Minimum_Node();
  
            tree_4.Maximum_Node();
    
  
        } 
    
        
        if(tree_select==5)
        {
            cout << "\n" << "***************************************************Tree-5**************************************************************" << "\n" <<endl;
            
            cout << "\n\t\t" << "***********************Tree-5 After Insertion of All Nodes***********************" << "\t\t\n" <<endl; 
            
            Red_Black_Tree<int, bool> tree_5;									
  
            for (int i = 1; i <35; ++i)
            {
                tree_5.Insert_Node(i*2, 0);
            }
  
            tree_5.Display();
            
            tree_5.Minimum_Node();
  
            tree_5.Maximum_Node();
  
            cout << "\n\t\t" << "***********************Tree-5 After Deletion of Requested Nodes***********************" << "\t\t\n" <<endl; 
  
            tree_5.Delete_Node(8);
    
            tree_5.Display();
  
            tree_5.Minimum_Node();
  
            tree_5.Maximum_Node();
    
  
        } 
        
        
        if(tree_select==6)
        {
            cout << "\n" << "***************************************************Tree-6**************************************************************" << "\n" <<endl;
            
            cout << "\n\t\t" << "***********************Tree-6 After Insertion of All Nodes***********************" << "\t\t\n" <<endl; 
            
            Red_Black_Tree<int, bool> tree_6;									
  
            for (int i = 40; i >0; --i)
            {
                tree_6.Insert_Node(i, 1);
            }
  
            tree_6.Display();
            
            tree_6.Minimum_Node();
  
            tree_6.Maximum_Node();
  
            cout << "\n\t\t" << "***********************Tree-6 After Deletion of Requested Nodes***********************" << "\t\t\n" <<endl; 
  
            tree_6.Delete_Node(12);
    
            tree_6.Display();
  
            tree_6.Minimum_Node();
  
            tree_6.Maximum_Node();
    
            tree_6.Find_Node(4);
  
        } 
    
        
        if(tree_select==7)
        {
            cout << "\n" << "***************************************************Tree-7**************************************************************" << "\n" <<endl;
            
            cout << "\n\t\t" << "***********************Tree-7 After Insertion of All Nodes***********************" << "\t\t\n" <<endl; 
            
            Red_Black_Tree<int, long int> tree_7;									
  
            for (int i = 1; i <45; ++i)
            {
                tree_7.Insert_Node(i*4, i*2000-1);
            }
  
            tree_7.Display();
            
            tree_7.Minimum_Node();
  
            tree_7.Maximum_Node();
  
            cout << "\n\t\t" << "***********************Tree-7 After Deletion of Requested Nodes***********************" << "\t\t\n" <<endl;
  
            tree_7.Delete_Node(8);
    
            tree_7.Display();
  
            tree_7.Minimum_Node();
  
            tree_7.Maximum_Node();
    
  
        } 
        
        
        if(tree_select==8)
        {
            cout << "\n" << "***************************************************Tree-8**************************************************************" << "\n" <<endl;
            
            cout << "\n\t\t" << "***********************Tree-8 After Insertion of All Nodes***********************" << "\t\t\n" <<endl; 
            
            Red_Black_Tree<int, double> tree_8;									
  
            for (int i = 50; i <100; ++i)
            {
                tree_8.Insert_Node(i*2, i*22222.5-1);
            }
  
            tree_8.Display();
            
            tree_8.Minimum_Node();
  
            tree_8.Maximum_Node();
  
            cout << "\n\t\t" << "***********************Tree-8 After Deletion of Requested Nodes***********************" << "\t\t\n" <<endl;
  
            tree_8.Display();
  
            tree_8.Minimum_Node();
  
            tree_8.Maximum_Node();
    
  
        } 
    
        
        if(tree_select==9)
        {
            cout << "\n" << "***************************************************Tree-9**************************************************************" << "\n" <<endl;
            
            cout << "\n\t\t" << "***********************Tree-9 After Insertion of All Nodes***********************" << "\t\t\n" <<endl; 
            
            Red_Black_Tree<int, short int> tree_9;									
  
            for (short int i = 1; i <55; ++i)
            {
                tree_9.Insert_Node(i+1, i+2);
            }
  
            tree_9.Display();
            
            tree_9.Minimum_Node();
  
            tree_9.Maximum_Node();
  
            cout << "\n\t\t" << "***********************Tree-9 After Deletion of Requested Nodes***********************" << "\t\t\n" <<endl;
  
            tree_9.Delete_Node(34);
    
            tree_9.Display();
  
            tree_9.Minimum_Node();
  
            tree_9.Maximum_Node();
    
            tree_9.Find_Node(41);
  
        } 
        
            tree_select++;
        }
    
    return 0;
    
}

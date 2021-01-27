# Functionalities implemented:
* <b>isEmpty:</b> The function to  know if our Queue is empty or not right now. 
* <b>enqueue:</b> Pushes data into the Queue. 
* <b>peek:</b> Returns the element at top of the Queue. Just shows use the element and does not remove it.
* <b>dequeue:</b> removes an element from the queue. 
* <b>displayQueue:</b> Displays all the elements in a space separated manner of the queue to a given out file, "cout" if you want to write to standard out. 

# Some important points:
* There are two options for you. <b> You can either have a queue of fixed size or queue of variable size.</b>
* For the queue with fixed size. We use a round robin type storage to effectively use the queue. The code will not resize the queue if it has a fixed size.
* For the queue with variable size: <b>If the first half storage of the queue gets empty, we just remove it and shorten our queue for memory management. </b>
* pop returns nothing so if you want to use something like <b>a = q.dequeue();</b>, it will throw errors. You should first use peek in that case and than use pop.
* The default separator for the displayQueue is " " but you can use whatever you want. 

# Code Snippets for Examples:
* To make a fixed size queue:
  
        Queue<int, true> qu(1000);
        // Makes a queue qu of size 1000, has fixed size.
* To make a variable size queue:
        
        Queue<int, false> qu;
        // Makes a queue of variable size.       
* To insert something in queue:

        qu.enqueue(key);

* To see the peek(element that will be dequeued.):
        
        int p = qu.peek();
 
* Dequeue an element:
    
        qu.dequeue();
        
 * Display Queue:
 
        qu.displayQueue(cout); // With default separation of " "
        // OR
        qu.displayQueue(cout, "\n"); // With user defined sparation.

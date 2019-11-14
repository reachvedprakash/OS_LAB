#!/usr/bin/env python
# coding: utf-8

# In[17]:


import threading 
x = 0


# In[28]:


def increment(): 
    global x 
    x += 5


# In[29]:


def thread_task(lock): 
    for _ in range(100): 
        lock.acquire() 
        increment() 
        lock.release() 


# In[30]:


def main_task(): 
    global x 
    x = 0
  
    lock = threading.Lock() 
  
    t1 = threading.Thread(target=thread_task, args=(lock,)) 
    t2 = threading.Thread(target=thread_task, args=(lock,)) 
  
    t1.start() 
    t2.start() 

    t1.join() 
    t2.join() 


# In[31]:


if __name__ == "__main__": 
    for i in range(10): 
        main_task() 
        print("Iteration {0}: x = {1}".format(i,x))


# In[ ]:





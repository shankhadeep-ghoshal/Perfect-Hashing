# Perfect Hashing


<h3><a href="https://en.wikipedia.org/wiki/Perfect_hash_function#Construction">Introduction</a></h3>

  A perfect hash function for a specific set S that can be evaluated in constant time, and with values in a small range, can be found by a randomized algorithm in a number of operations that is proportional to the size of S. The original construction of Fredman, Komlós & Szemerédi (1984) uses a two-level scheme to map a set S of n elements to a range of O(n) indices, and then map each index to a range of hash values. The first level of their construction chooses a large prime p (larger than the size of the universe from which S is drawn), and a parameter k, and maps each element x of S to the index: <img src="https://wikimedia.org/api/rest_v1/media/math/render/svg/0eed5c339f42fdccc1685d8d3b1af928e2a3be01"/>

If k is chosen randomly, this step is likely to have collisions, but the number of elements n<sub>i</sub> that are simultaneously mapped to the same index i is likely to be small. The second level of their construction assigns disjoint ranges of <i>O</i>(<i>n<sub>i</sub></i><sup>2</sup>) integers to each index i. It uses a second set of linear modular functions, one for each index i, to map each member x of S into the range associated with g(x).


____


### Algorithm 

```
prime = nearest prime number after the max element of inputSet
a = Generate a random number between 1 and nearest prime after inputSet.maxElement(exclusive)
b = Generate a random number between 0 and nearest prime after inputSet.maxElement(exclusive)
for i = 0 to inputSet.size
  hashValue = g(inputSet[i], a , b , prime , inputSet.size)
  hashTable[hashValue].add(inputSet[i])
  endfor

for i =  0 to inputSet.size
  temp = hashTable[i]
  if(temp.size == 1)hashTable[i] = temp
  else
      new_m = temp.size^2
      hashTable[i].resize(new_m)
      flag = true
      while(flag)
        generate new_a, new_b 
        for j = 0 to temp.size
          newHashValue = g(temp[j] , new_a , new_b , prime , new_m)
          if !(hashTable[i][newHashValue] == temp[j])
            placeHolder[hashValue] = temp[j]
            hashTable[i]  = placeHolder;
          else 
            flag = false;
            break;      
```


---



### Usage

* Clone the repository. Navigate to the file **Test.cpp**  
* Generate a set of keys and put it inside ```std::vector``` collection
* Create a parameterised constructor with the class name ```PerfectHash``` and the  ```std::vector``` as the parameter
* Call the ```createTable()``` method on the ```PerfectHash``` object 




### Results
##### Input Set
{ 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 }

##### Parameters:

* prime : 11
* a : 8
* b : 0

##### Output Set

4: 1-th row 1-th column  </br>
7: 2-th row 1-th column  </br>
3: 3-th row 1-th column  </br>
10: 4-th row 1-th column </br>
6: 5-th row 1-th column  </br>
2: 6-th row 1-th column  </br>
9: 7-th row 1-th column  </br>
5: 8-th row 1-th column  </br>
1: 9-th row 1-th column  </br>
8: 10-th row 1-th column </br>




### Acknowledgements
* Dmitry Gribanov : Teacher, Algorithm Analysis 
* [Introduction to Algorithms](https://en.wikipedia.org/wiki/Introduction_to_Algorithms) : CLRS, MIT Press
* [Cppreference.com](http://en.cppreference.com/w/)
* [Cplusplus.com](http://www.cplusplus.com/)
* Heineken Lager Beer

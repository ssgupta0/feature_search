# feature_search



Introduction
This project uses a wrapper of a feature search around K-folding forwards search and backwards elimination of a nearest neighbor algorithm to find which feature sets are most applicable to determining what class one of the given objects is. Input files must have classification on left most collumn, and each feature set for n collumns.



![Image 1](https://github.com/ssgupta0/feature_search/blob/master/Figure1.png)

Overview of Algorithm
The text file inputted into the program uses the first column to depict what class the objects are, and uses the next n columns for n features that it has. An analogy to this problem could be if class were binary gender and features were height at weight. Given that an object is 6’2” and 200lb, we can likely say that they are a male as there was also a 6’3” 215lb male. This is fundamentally what our program attempts to do. It checks the accuracy of several combinations of features of an object by checking how often another object of similar features were of the same class ie. the nearest neighbor algorithm.

Nearest neighbor
From our previous example, if we plot both of our objects on a 2 dimensional xy plot, we can measure the distance between them by using the distance formula: sqrt( (x2-x1)^2 + (y2-y1)^2 ).
This 2 dimensional plot works very well for our feature set of 2. We can extend this logic for feature sets of higher magnitude. While difficult to draw a n-dimensional plot where n is greater than 3, we can still use our distance formula for many dimensions. Our distance formula becomes instead: sqrt( (x2-x1)^2 + (y2-y1)^2 + … + (n2-n1)^2 ).

Forwards Selection
Forwards selection is our wrapper on the nearest neighbor algorithm, which is one of our methods for finding our optimal set of features. Our algorithm works by calculating the accuracy of all sets of size 1. It then chooses the one with the best accuracy to add to its permanent feature set. It then creates subsets of the permanent set along with every other feature. This loops for n(n-1)/2 times, where we keep track of the best accuracy. Because our set always chooses the most accurate subset to expand on, we are more likely to approach our best set of features. Once all combinations of sets from that instance are parsed through, we can output our best feature and its respective best accuracy. 

Backwards Elimination
Backwards Elimination uses a very similar principle as forwards selection, but in reverse. In forwards selection we started with an empty set, and attempted to add a single feature for every depth, till we ended the algorithm. Instead, for backwards elimination, we start with a set of all features and attempt to find the accuracy of subsets in which a single feature is removed at every depth. While these algorithms can approach the same runtime and same solution, they can also diverge in niche cases. A reason to choose one or the other depends on the number of features we expect to be relevant to determining our case. If there are more features needed for a case, then backwards elimination will generally be more advantageous, as it would start with a greater number of features before removing unnecessary ones. Likewise, if only a few features are needed for determining case, then forwards selection would be more attractive as we could first choose our best features.

Small data


![Image 2](https://github.com/ssgupta0/feature_search/blob/master/figure2.png)

At the beginning of the search, we have no features, this the empty set {}. This is the default rate of our set: 77%. Adding 9 increases the accuracy of our classes to 83.3%. Adding 7 to our subset so {9,7}, once again increases our accuracy to 96.7%, but when we add 10 for {9,7,10}, our accuracy goes down to 94.7%. We parse through this incase of a local maxima, but in the end our best features were 9 and 7 as the best subset was {9,7} with accuracy 96.7%.




Next in figure 3, we attempt backwards elimination on the same subset to see how our algorithms compare.

![Image 3](https://github.com/ssgupta0/feature_search/blob/master/figure3.png)

At the beginning of the search, we have all features, this the full set {All}. This is the default rate of our set: 77%. Removing 3 increases the accuracy of our classes to 79.0%. We gradually remove more and more features until we are at set {1,9,7}, with accuracy 92.3%. We remove 1 for {9,7} and get a higher accuracy of 96.7%, but when we remove 7 for {9}, our accuracy goes down to 83.3%. 

Conclusion for small dataset
Although forwards selection and backwards elimination resulted in the same final best subset of features, they approached this solution in different ways. We can see that while forwards selection went to set {9,7,10} after {9,7}, backwards went from {1,9,7} to {9,7}. Because the solution was a smaller subset of the 10 features (2), forwards selection was favorable here.

Large data


![Image 4](https://github.com/ssgupta0/feature_search/blob/master/figure4.png)

At the beginning of the search, we have no features, this the empty set {}. This is the default rate of our set: 67%. Adding 48 increases the accuracy of our classes to 86%. Adding 54 to our subset so {48,54}, once again increases our accuracy to 94.2%, but when we add any other, our accuracy goes down. We parse through this incase of a local maxima, but in the end our best features were 48 and 54 as the best subset was {48,54} with accuracy 94.2%.




There is no figure 5, as I ran out of time to run a 5 hour test for backwards elimination.

Conclusion for large dataset
The large dataset performs similarly to the small data set, where because our solution was of size 2, forwards selection is attractive. 


Computational effort for search
I implemented search in C++, natively on macos using Xcode as my ide. My 10 year old mac has an i5-3000 series chip with 8 gigs of RAM, but was only allowed 10mb inside of the ide. I was not able to accurately time the large data set, as I went to bed, but the small data set was roughly 13.2 seconds for both backwards and forwards.






















Below I will show a trace of my algorithm in Forwards Selection for the small data set:

 
(Middle of output skipped for sake of space)
 







Below I will show a trace of my algorithm in Forwards Selection for the largedata set:


(I have left out middle for space)



# k-means-algorithm
This project is one of my first ever made. I created an implementation of machine learning algorithm called k-means algorithm. The idea behind it is to give it a set of objects that are needed to be clustered, but you don't want to sort it on your own. You just want to give a set of points and number of clusters to be created. 

Steps of algorithm:
- randomize k starting points (where k is the number of clusters), these points will be centres of clusters
- calculate group of every point (based on how far from centre of each cluster it is)
- calculate arithmetic average of every points position from each cluster
- update center point of each cluster (the one that is closiest to arithmetic average will be new point)
- repeat from 2-4 until centre points will not be changed

If you want to know more about this algorithm here is source i've based on during my work: http://itcraftsman.pl/algorytm-k-srednich-uczenie-nienadzorowane/?fbclid=IwAR2Q_mfp66o8gowMAWFIzVmaD51t8oAtQ0_YnaZPEizokxFg8mUDRVes19w

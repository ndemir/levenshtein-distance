# levenshtein-distance

##Compile && Install
```
WORKDIR=`pwd`/workdir
mkdir -p $WORKDIR

mkdir -p $WORKDIR/supergetopt
git clone git@github.com:ndemir/supergetopt.git $WORKDIR/supergetopt
cd $WORKDIR/supergetopt
make

mkdir -p $WORKDIR/levenshtein-distance
git clone git@github.com:ndemir/levenshtein-distance.git $WORKDIR/levenshtein-distance
mkdir $WORKDIR/levenshtein-distance/build
cd $WORKDIR/levenshtein-distance/build
cmake -DSUPERGETOPT_DIR=$WORKDIR/supergetopt ..
make

sudo cp levenshtein_distance /usr/local/bin/
```
##Usage

###Example 1
Calculate distance of string1 to the strings in the string2-file with max-distance 2.
```
levenshtein_distance --string1 "str1" --string2-file file --max-distance 2
```

###Example 2
Calculate distance of string1 to the strings in the string2-file with max-distance 2 and write to file.
```
levenshtein_distance --string1 "str1" --string2-file file --max-distance 2 --output-file output
```

###Example 3
Calculate distance of string1 to the strings in the string2-file with max-distance-ratio 50.

When max-distance-ratio is used, max-distance is calculate by using this value by using the following formula:

maxDistance = round(strlen(str1)*distanceRatio/100.0)

```
levenshtein_distance --string1 "str1" --string2-file file --max-distance-ratio 50
```

##Example 4
Calculate distance of string1 to the strings in the string2-file with max-distance-ratio 50 and include string1 in output.
```
levenshtein_distance --string1 "str1" --string2-file file --max-distance-ratio 50 --include-string1
```

##Example 5
Calculate distance of strings to each other in the file by using [gnu parallel](http://www.gnu.org/software/parallel/) and write to result file.

In this example using max-distance-ratio is much more useful than max-distance because we do not know the length of each string, so we let the application to calculate it.

```
cat file | parallel --eta -I xxx levenshtein_distance --string1 xxx --string2-file file --max-distance-ratio 25 --include-string1 > result
```




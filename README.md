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

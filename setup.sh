# use `source setvars.sh` in here to setup

# recover split files due to github filesize limitation
FILES="flint2-2.9.0/lib/libflint.a mkl-2021a/lib/libmkl_core.a mkl-2021a/lib/libmkl_core.so.1"
for FILE in $FILES
do
if [[ ! -f "$FILE" ]]; then
    cat ${FILE}-split-* > $FILE
fi
done

source ../SLISC0/make/lib_append.sh $PWD/arb-*
source ../SLISC0/make/lib_append.sh $PWD/arpack-ng-*
source ../SLISC0/make/lib_append.sh $PWD/flint2-*
source ../SLISC0/make/lib_append.sh $PWD/gmp-*
source ../SLISC0/make/lib_append.sh $PWD/gsl-*
source ../SLISC0/make/lib_append.sh $PWD/lapack64-shared-*
source ../SLISC0/make/lib_append.sh $PWD/lapack64-static-*
source ../SLISC0/make/lib_append.sh $PWD/lapack-shared-*
source ../SLISC0/make/lib_append.sh $PWD/lapack-static-*
source ../SLISC0/make/lib_append.sh $PWD/mkl-*
source ../SLISC0/make/lib_append.sh $PWD/mpfr-*
source ../SLISC0/make/lib_append.sh $PWD/sqlite-*
source ../SLISC0/make/lib_append.sh $PWD/boost-filesystem-*


# use `source setvars.sh` in here to setup

# recover split files due to github filesize limitation
FILES="flint-2.9.0/lib/libflint.a mkl-2021a/lib/libmkl_core.a mkl-2021a/lib/libmkl_core.so.1"
for FILE in $FILES
do
if [[ ! -f "$FILE" ]]; then
    cat ${FILE}-split-* > $FILE
fi
done

source ../SLISC0/make/lib_append.sh arb-*
source ../SLISC0/make/lib_append.sh arpack-ng-*
source ../SLISC0/make/lib_append.sh flint2-*
source ../SLISC0/make/lib_append.sh gmp-*
source ../SLISC0/make/lib_append.sh gsl-*
source ../SLISC0/make/lib_append.sh lapack64-shared-*
source ../SLISC0/make/lib_append.sh lapack64-static-*
source ../SLISC0/make/lib_append.sh lapack-shared-*
source ../SLISC0/make/lib_append.sh lapack-static-*
source ../SLISC0/make/lib_append.sh mkl-*
source ../SLISC0/make/lib_append.sh mpfr-*

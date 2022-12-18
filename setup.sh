# use `source setvars.sh` in here to setup

echo ":: initializing SLISC0-libs-x64-centos7.9.2009"

# recover split files due to github filesize limitation
FILES="flint2-2.9.0/lib/libflint.a mkl-2021a/lib/libmkl_core.a mkl-2021a/lib/libmkl_core.so.1"
for FILE in $FILES
do
if [[ ! -f "$FILE" ]]; then
    cat ${FILE}-split-* > $FILE
fi
done

ADD="source ../SLISC0/make/lib_prepend.sh $PWD"

$ADD/arb-2.23.0
$ADD/arpack-ng-3.8.0
$ADD/arpackpp-2.3.0
# $ADD/boost-1.76.0-GCC-10.3.0
$ADD/boost-1.80.0
$ADD/eigen-3.4.0
$ADD/flint2-2.9.0
$ADD/gmp-6.1.2
$ADD/gsl-2.7.1
$ADD/lapack64-shared-3.10.1
$ADD/lapack64-static-3.10.1
$ADD/lapack-shared-3.10.1
$ADD/lapack-static-3.10.1
$ADD/mkl-2021a
$ADD/mpfr-4.1.0
$ADD/mplapack-2.0.1
$ADD/sqlite-3.40.0
# $ADD/boost-filesystem-*
# $ADD/boost-1.76.0*

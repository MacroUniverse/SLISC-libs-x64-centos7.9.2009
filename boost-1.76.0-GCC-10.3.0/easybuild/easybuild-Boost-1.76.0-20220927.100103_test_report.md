#### Test result
Successfully built /opt/beocat/easyconfigs/easybuild/easyconfigs/b/Boost/Boost-1.76.0-GCC-10.3.0.eb

#### Overview of tested easyconfigs (in order)
 * **SUCCESS** _Boost-1.76.0-GCC-10.3.0.eb_ 

#### Time info
 * start: Tue, 27 Sep 2022 14:40:20 +0000 (UTC)
 * end: Tue, 27 Sep 2022 15:01:03 +0000 (UTC)

#### EasyBuild info
 * easybuild-framework version: 4.6.0
 * easybuild-easyblocks version: 4.6.0
 * command line:
```
eb --robot --minimal-toolchains AutoDock-Vina-1.2.3-foss-2021a.eb
```
 * full configuration (includes defaults):
```
--accept-eula-for=''
--accept-eula=''
--allow-loaded-modules='EasyBuild'
--buildpath='/tmp/easybuild'
--check-ebroot-env-vars='warn'
--cleanup-builddir
--cleanup-easyconfigs
--cleanup-tmpdir
--color='auto'
--container-type='singularity'
--containerpath='/opt/software/containers'
--default-opt-level='defaultopt'
--detect-loaded-modules='warn'
--disable-add-dummy-to-minimal-toolchains
--disable-add-system-to-minimal-toolchains
--disable-allow-modules-tool-mismatch
--disable-allow-use-as-root-and-accept-consequences
--disable-avail-cfgfile-constants
--disable-avail-easyconfig-constants
--disable-avail-easyconfig-licenses
--disable-avail-easyconfig-params
--disable-avail-easyconfig-templates
--disable-avail-hooks
--disable-avail-module-naming-schemes
--disable-avail-modules-tools
--disable-avail-repositories
--disable-backup-patched-files
--disable-check-conflicts
--disable-check-contrib
--disable-check-eb-deps
--disable-check-github
--disable-check-style
--disable-consider-archived-easyconfigs
--disable-container-build-image
--disable-containerize
--disable-copy-ec
--disable-debug
--disable-debug-lmod
--disable-devel
--disable-dry-run
--disable-dry-run-short
--disable-dump-autopep8
--disable-dump-env-script
--disable-enforce-checksums
--disable-experimental
--disable-extended-dry-run
--disable-fetch
--disable-fix-deprecated-easyconfigs
--disable-force
--disable-group-writable-installdir
--disable-hidden
--disable-ignore-checksums
--disable-ignore-index
--disable-ignore-locks
--disable-ignore-osdeps
--disable-ignore-test-failure
--disable-info
--disable-insecure-download
--disable-install-github-token
--disable-install-latest-eb-release
--disable-job
--disable-last-log
--disable-list-toolchains
--disable-logtostdout
--disable-missing-modules
--disable-module-depends-on
--disable-module-extensions
--disable-module-only
--disable-new-branch-github
--disable-new-pr
--disable-package
--disable-parallel-extensions-install
--disable-pretend
--disable-preview-pr
--disable-quiet
--disable-read-only-installdir
--disable-rebuild
--disable-regtest
--disable-remove-ghost-install-dirs
--disable-rpath
--disable-sanity-check-only
--disable-sequential
--disable-set-default-module
--disable-set-gid-bit
--disable-show-config
--disable-show-default-configfiles
--disable-show-default-moduleclasses
--disable-show-ec
--disable-show-full-config
--disable-show-system-info
--disable-skip
--disable-skip-extensions
--disable-skip-test-cases
--disable-skip-test-step
--disable-sticky-bit
--disable-terse
--disable-trace
--disable-try-ignore-versionsuffixes
--disable-try-update-deps
--disable-unit-testing-mode
--disable-update-modules-tool-cache
--disable-upload-test-report
--disable-use-existing-modules
--disable-verify-easyconfig-filenames
--env-for-shebang='/usr/bin/env'
--envvars-user-modules='HOME'
--extended-dry-run-ignore-errors
--fixed-installdir-naming-scheme
--from-pr=''
--generate-devel-module
--hooks='/opt/beocat/easyhooks/openmpi-config.py'
--ignore-dirs='.git,.svn'
--include-easyblocks-from-pr=''
--include-easyblocks='/opt/beocat/easyblocks/*'
--include-module-naming-schemes=''
--include-toolchains='/opt/beocat/toolchains/*'
--index-max-age='604800'
--installpath='/opt/software'
--job-backend='GC3Pie'
--job-eb-cmd='eb'
--job-max-jobs='0'
--job-max-walltime='24'
--job-output-dir='/homes/easybuilder'
--job-polling-interval='30.0'
--lib-lib64-symlink
--lib64-fallback-sanity-check
--lib64-lib-symlink
--local-var-naming-check='warn'
--logfile-format='easybuild,easybuild-%(name)s-%(version)s-%(date)s.%(time)s.log'
--map-toolchains
--max-fail-ratio-adjust-permissions='0.5'
--minimal-build-env='CC:gcc,CXX:g++'
--minimal-toolchains
--module-naming-scheme='EasyBuildMNS'
--module-syntax='Lua'
--moduleclasses='base,astro,bio,cae,chem,compiler,data,debugger,devel,geo,ide,lang,lib,math,mpi,numlib,perf,quantum,phys,system,toolchain,tools,vis'
--modules-tool-version-check
--modules-tool='Lmod'
--mpi-tests
--output-format='txt'
--output-style='auto'
--package-naming-scheme='EasyBuildPNS'
--package-release='1'
--package-tool-options=''
--package-tool='fpm'
--package-type='rpm'
--packagepath='/opt/software/packages'
--pr-target-account='easybuilders'
--pr-target-branch='develop'
--pre-create-installdir
--prefix='/opt/software'
--recursive-module-unload
--repository='FileRepository'
--repositorypath='/opt/software/ebfiles_repo'
--robot-paths='/opt/beocat/easyconfigs/easybuild/easyconfigs'
--robot='/opt/beocat/easyconfigs/easybuild/easyconfigs'
--show-progress-bar
--sourcepath='/opt/beocat/sources'
--strict='warn'
--subdir-modules='modulefiles'
--subdir-software='software'
--suffix-modules-path='all'
--use-ccache='False'
--use-f90cache='False'
--wait-on-lock-interval='60'
--wait-on-lock-limit='0'
````

#### System info
 * _core count:_ 8
 * _cpu arch:_ x86_64
 * _cpu arch name:_ UNKNOWN
 * _cpu model:_ Intel Xeon E312xx (Sandy Bridge)
 * _cpu speed:_ 2399.996
 * _cpu vendor:_ Intel
 * _gcc version:_ Using built-in specs.; COLLECT_GCC=gcc; COLLECT_LTO_WRAPPER=/usr/libexec/gcc/x86_64-redhat-linux/4.8.5/lto-wrapper; Target: x86_64-redhat-linux; Configured with: ../configure --prefix=/usr --mandir=/usr/share/man --infodir=/usr/share/info --with-bugurl=http://bugzilla.redhat.com/bugzilla --enable-bootstrap --enable-shared --enable-threads=posix --enable-checking=release --with-system-zlib --enable-__cxa_atexit --disable-libunwind-exceptions --enable-gnu-unique-object --enable-linker-build-id --with-linker-hash-style=gnu --enable-languages=c,c++,objc,obj-c++,java,fortran,ada,go,lto --enable-plugin --enable-initfini-array --disable-libgcj --with-isl=/builddir/build/BUILD/gcc-4.8.5-20150702/obj-x86_64-redhat-linux/isl-install --with-cloog=/builddir/build/BUILD/gcc-4.8.5-20150702/obj-x86_64-redhat-linux/cloog-install --enable-gnu-indirect-function --with-tune=generic --with-arch_32=x86-64 --build=x86_64-redhat-linux; Thread model: posix; gcc version 4.8.5 20150623 (Red Hat 4.8.5-44) (GCC) ; 
 * _glibc version:_ 2.17
 * _hostname:_ clymene
 * _os name:_ CentOS Linux
 * _os type:_ Linux
 * _os version:_ 7.9.2009
 * _platform name:_ x86_64-unknown-linux
 * _python version:_ 2.7.5 (default, Jun 28 2022, 15:30:04) ; [GCC 4.8.5 20150623 (Red Hat 4.8.5-44)]
 * _system gcc path:_ /usr/bin/gcc
 * _system python path:_ /usr/bin/python
 * _total memory:_ 15884

#### List of loaded modules
 * EasyBuild/4.6.0

#### Environment
```
BASH_ENV = /usr/share/lmod/lmod/init/bash
BASH_FUNC_ml() = () {  eval "$($LMOD_DIR/ml_cmd "$@")"
}
BASH_FUNC_module() = () {  if [ -z "${LMOD_SH_DBG_ON+x}" ]; then
 case "$-" in 
 *v*x*)
 __lmod_sh_dbg='vx'
 ;;
 *v*)
 __lmod_sh_dbg='v'
 ;;
 *x*)
 __lmod_sh_dbg='x'
 ;;
 esac;
 fi;
 if [ -n "${__lmod_sh_dbg:-}" ]; then
 set +$__lmod_sh_dbg;
 echo "Shell debugging temporarily silenced: export LMOD_SH_DBG_ON=1 for Lmod's output" 1>&2;
 fi;
 eval "$($LMOD_CMD $LMOD_SHELL_PRGM "$@")" && eval "$(${LMOD_SETTARG_CMD:-:} -s sh)";
 __lmod_my_status=$?;
 if [ -n "${__lmod_sh_dbg:-}" ]; then
 echo "Shell debugging restarted" 1>&2;
 set -$__lmod_sh_dbg;
 fi;
 unset __lmod_sh_dbg;
 return $__lmod_my_status
}
CMAKE_PREFIX_PATH = /opt/software/software/EasyBuild/4.6.0
EBDEVELEASYBUILD = /opt/software/software/EasyBuild/4.6.0/easybuild/EasyBuild-4.6.0-easybuild-devel
EBROOTEASYBUILD = /opt/software/software/EasyBuild/4.6.0
EBVERSIONEASYBUILD = 4.6.0
EB_INSTALLPYTHON = /usr/bin/python
EB_SCRIPT_PATH = /opt/software/software/EasyBuild/4.6.0/bin/eb
FANCYLOGGER_IGNORE_MPI4PY = 1
HISTCONTROL = ignoredups
HISTSIZE = 1000
HOME = /homes/easybuilder
HOSTNAME = clymene
LANG = en_US.utf8
LESSOPEN = ||/usr/bin/lesspipe.sh %s
LMOD_CMD = /usr/share/lmod/lmod/libexec/lmod
LMOD_DIR = /usr/share/lmod/lmod/libexec
LMOD_IGNORE_CACHE = 1
LMOD_PACKAGE_PATH = /etc/lmod
LMOD_PKG = /usr/share/lmod/lmod
LMOD_ROOT = /usr/share/lmod
LMOD_SETTARG_FULL_SUPPORT = no
LMOD_SHELL_PRGM = bash
LMOD_SYSTEM_DEFAULT_MODULES = StdEnv/default
LMOD_VERSION = 8.7.7
LMOD_sys = Linux
LOADEDMODULES = EasyBuild/4.6.0
LOGNAME = easybuilder
LS_COLORS = rs=0:di=38;5;27:ln=38;5;51:mh=44;38;5;15:pi=40;38;5;11:so=38;5;13:do=38;5;5:bd=48;5;232;38;5;11:cd=48;5;232;38;5;3:or=48;5;232;38;5;9:mi=05;48;5;232;38;5;15:su=48;5;196;38;5;15:sg=48;5;11;38;5;16:ca=48;5;196;38;5;226:tw=48;5;10;38;5;16:ow=48;5;10;38;5;21:st=48;5;21;38;5;15:ex=38;5;34:*.tar=38;5;9:*.tgz=38;5;9:*.arc=38;5;9:*.arj=38;5;9:*.taz=38;5;9:*.lha=38;5;9:*.lz4=38;5;9:*.lzh=38;5;9:*.lzma=38;5;9:*.tlz=38;5;9:*.txz=38;5;9:*.tzo=38;5;9:*.t7z=38;5;9:*.zip=38;5;9:*.z=38;5;9:*.Z=38;5;9:*.dz=38;5;9:*.gz=38;5;9:*.lrz=38;5;9:*.lz=38;5;9:*.lzo=38;5;9:*.xz=38;5;9:*.bz2=38;5;9:*.bz=38;5;9:*.tbz=38;5;9:*.tbz2=38;5;9:*.tz=38;5;9:*.deb=38;5;9:*.rpm=38;5;9:*.jar=38;5;9:*.war=38;5;9:*.ear=38;5;9:*.sar=38;5;9:*.rar=38;5;9:*.alz=38;5;9:*.ace=38;5;9:*.zoo=38;5;9:*.cpio=38;5;9:*.7z=38;5;9:*.rz=38;5;9:*.cab=38;5;9:*.jpg=38;5;13:*.jpeg=38;5;13:*.gif=38;5;13:*.bmp=38;5;13:*.pbm=38;5;13:*.pgm=38;5;13:*.ppm=38;5;13:*.tga=38;5;13:*.xbm=38;5;13:*.xpm=38;5;13:*.tif=38;5;13:*.tiff=38;5;13:*.png=38;5;13:*.svg=38;5;13:*.svgz=38;5;13:*.mng=38;5;13:*.pcx=38;5;13:*.mov=38;5;13:*.mpg=38;5;13:*.mpeg=38;5;13:*.m2v=38;5;13:*.mkv=38;5;13:*.webm=38;5;13:*.ogm=38;5;13:*.mp4=38;5;13:*.m4v=38;5;13:*.mp4v=38;5;13:*.vob=38;5;13:*.qt=38;5;13:*.nuv=38;5;13:*.wmv=38;5;13:*.asf=38;5;13:*.rm=38;5;13:*.rmvb=38;5;13:*.flc=38;5;13:*.avi=38;5;13:*.fli=38;5;13:*.flv=38;5;13:*.gl=38;5;13:*.dl=38;5;13:*.xcf=38;5;13:*.xwd=38;5;13:*.yuv=38;5;13:*.cgm=38;5;13:*.emf=38;5;13:*.axv=38;5;13:*.anx=38;5;13:*.ogv=38;5;13:*.ogx=38;5;13:*.aac=38;5;45:*.au=38;5;45:*.flac=38;5;45:*.mid=38;5;45:*.midi=38;5;45:*.mka=38;5;45:*.mp3=38;5;45:*.mpc=38;5;45:*.ogg=38;5;45:*.ra=38;5;45:*.wav=38;5;45:*.axa=38;5;45:*.oga=38;5;45:*.spx=38;5;45:*.xspf=38;5;45:
MAIL = /var/spool/mail/easybuilder
MANPATH = /usr/share/lmod/lmod/share/man:
MODULEPATH = /opt/software/modulefiles/all:/opt/beocat/custom_modules
MODULEPATH_ROOT = /usr/share/modulefiles
MODULESHOME = /usr/share/lmod/lmod
PATH = /opt/software/software/EasyBuild/4.6.0/bin:/homes/easybuilder/.yarn/bin:/homes/easybuilder/.config/yarn/global/node_modules/.bin:/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/homes/easybuilder/.local/bin:/homes/easybuilder/bin
PWD = /homes/easybuilder
PYTHONOPTIMIZE = 1
PYTHONPATH = /opt/software/software/EasyBuild/4.6.0/lib/python2.7/site-packages
SHELL = /bin/bash
SHLVL = 2
SSH_ASKPASS = /usr/libexec/openssh/gnome-ssh-askpass
SSH_CLIENT = 10.5.1.20 46994 22
SSH_CONNECTION = 10.5.1.20 46994 10.5.1.7 22
SSH_TTY = /dev/pts/1
TERM = screen-256color
USER = easybuilder
XDG_DATA_DIRS = /homes/easybuilder/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/usr/local/share:/usr/share
XDG_RUNTIME_DIR = /run/user/3010
XDG_SESSION_ID = 1272
_ = /usr/bin/python
_LMFILES_ = /opt/software/modulefiles/all/EasyBuild/4.6.0.lua
_ModuleTable001_ = X01vZHVsZVRhYmxlXyA9IHsKTVR2ZXJzaW9uID0gMywKY19yZWJ1aWxkVGltZSA9IGZhbHNlLApjX3Nob3J0VGltZSA9IGZhbHNlLApkZXB0aFQgPSB7fSwKZmFtaWx5ID0ge30sCm1UID0gewpFYXN5QnVpbGQgPSB7CmZuID0gIi9vcHQvc29mdHdhcmUvbW9kdWxlZmlsZXMvYWxsL0Vhc3lCdWlsZC80LjYuMC5sdWEiLApmdWxsTmFtZSA9ICJFYXN5QnVpbGQvNC42LjAiLApsb2FkT3JkZXIgPSAxLApwcm9wVCA9IHt9LApzdGFja0RlcHRoID0gMCwKc3RhdHVzID0gImFjdGl2ZSIsCnVzZXJOYW1lID0gIkVhc3lCdWlsZCIsCndWID0gIjAwMDAwMDAwNC4wMDAwMDAwMDYuKnpmaW5hbCIsCn0sCn0sCm1wYXRoQSA9IHsKIi9vcHQvc29mdHdhcmUvbW9kdWxlZmlsZXMvYWxsIiwg
_ModuleTable002_ = Ii9vcHQvYmVvY2F0L2N1c3RvbV9tb2R1bGVzIiwKfSwKc3lzdGVtQmFzZU1QQVRIID0gIi9vcHQvc29mdHdhcmUvbW9kdWxlZmlsZXMvYWxsOi9vcHQvYmVvY2F0L2N1c3RvbV9tb2R1bGVzIiwKfQo=
_ModuleTable_Sz_ = 2
__Init_Default_Modules = 1
__LMOD_REF_COUNT_CMAKE_PREFIX_PATH = /opt/software/software/EasyBuild/4.6.0:1
__LMOD_REF_COUNT_MODULEPATH = /opt/software/modulefiles/all:1;/opt/beocat/custom_modules:1
__LMOD_REF_COUNT_PATH = /opt/software/software/EasyBuild/4.6.0/bin:1;/homes/easybuilder/.yarn/bin:1;/homes/easybuilder/.config/yarn/global/node_modules/.bin:1;/usr/local/bin:1;/usr/bin:1;/usr/local/sbin:1;/usr/sbin:1;/homes/easybuilder/.local/bin:1;/homes/easybuilder/bin:1
__LMOD_REF_COUNT_PYTHONPATH = /opt/software/software/EasyBuild/4.6.0/lib/python2.7/site-packages:1
```
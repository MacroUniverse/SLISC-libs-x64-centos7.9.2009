from easybuild.tools.run import run_cmd
from distutils.version import LooseVersion
import socket

def pre_configure_hook(self, *args, **kwargs):
    if self.name == 'OpenMPI':
        if '--disable-dlopen' in self.cfg['configopts']:
            self.log.info("[pre_configure_hook] Removing --disable-dlopen")
            self.cfg['configopts'] = self.cfg['configopts'].replace('--disable-dlopen', '')
        if LooseVersion(self.version) < LooseVersion('3'):
            self.log.info("[pre_configure_hook] enabling cxx bindings")
            self.cfg['configopts'] += ' --enable-mpi-cxx'
        self.log.info("[pre_configure_hook] enabling pmi and slurm")
        self.cfg['configopts'] += ' --with-pmi --with-slurm'
        if 'wizard' in socket.gethostname() or 'warlock' in socket.gethostname():
            if LooseVersion(self.version) < LooseVersion("4.1.1"):  # needs newer psm2 than provided with centos 7
                self.log.info("[pre_configure_hook] enabling psm2")
                self.cfg['configopts'] += ' --with-psm2'
            else:
                self.log.info("[pre_configure_hook] disabling psm2 because openmpi needs a newer version")
                self.cfg['configopts'] += ' --without-psm2'
        else:
            self.log.info("[pre_configure_hook] disabling psm2")
            self.cfg['configopts'] += ' --without-psm2'
        self.log.info("[pre_configure_hook] disabling psm")
        self.cfg['configopts'] += ' --without-psm'
        self.log.info("[pre_configure_hook] disabling mxm")
        self.cfg['configopts'] += ' --without-mxm'
    if self.name == 'libfabric':
        self.log.info("[pre_configure_hook] disable psm3 because it is broken")
        self.cfg['configopts'] += ' --enable-psm3=no'

def post_install_hook(self, *args, **kwargs):
    if self.name == 'OpenMPI':
        self.log.info("[post_install_hook] Adding local configuration options to openmpi-mca-params.conf")
        cmds = [
            "echo 'oob_tcp_listen_mode = listen_thread' >> {}/etc/openmpi-mca-params.conf".format(self.installdir),
            "echo 'hwloc_base_binding_policy = none' >> {}/etc/openmpi-mca-params.conf".format(self.installdir),
            #"echo 'btl = self,vader,openib,tcp,sm' >> {}/etc/openmpi-mca-params.conf".format(self.installdir),
            "echo 'btl_tcp_if_include = 10.5.0.0/16' >> {}/etc/openmpi-mca-params.conf".format(self.installdir),
            "echo 'btl_openib_receive_queues = P,128,64,32,32,32:S,2048,1024,128,32:S,12288,1024,128,32:S,65536,1024,128,32' >> {}/etc/openmpi-mca-params.conf".format(self.installdir),
        ]
        if LooseVersion(self.version) < LooseVersion("4.0.6"):  # slurm bug 10383
            cmds.append("echo 'plm_slurm_args = --whole' >> {}/etc/openmpi-mca-params.conf".format(self.installdir))
        for cmd in cmds:
            run_cmd(cmd, simple=True, log_ok=True, log_all=True)
    if self.name == "R":
        self.log.info("[post_install_hook] Removing -march=native from Makeconfs")
        cmds = [
            "sed -i 's/-march=native/-march=x86-64/g' {}/lib64/R/etc/Makeconf".format(self.installdir)
        ]
        for cmd in cmds:
            run_cmd(cmd, simple=True, log_ok=True, log_all=True)

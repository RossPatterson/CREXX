#!/usr/bin/bash
# Fix up *.h files for building in CMS.

# Exit if there is an error
set -euo pipefail

# Show the commands
set -x

cd src

# Rename the long- or badly-named files to better names.
mv avl_tree.h                  avltree.h
mv crexx_license.h             crexxlic.h
mv crexx_version.h             crexxver.h
mv rxcp_ast_rewrite.h          rcarewrt.h
mv rxcp_emit.h                 rxcpemit.h
mv rxcp_exit.h                 rxcpexit.h
mv rxcp_highlight_controller.h rchictl.h
mv rxcp_source_tree.h          rcsrctr.h
mv rxcp_token.h                rctoken.h
mv rxcp_types.h                rctypes.h
mv rxcp_util.h                 rcutil.h
mv rxvmplugin.h                rxpl.h
mv rxvmplugin_framework.h      rxplfr.h

# Fix all the references to the renamed files.
for FILE in *.c *.h ; do
	sed -i "$FILE" \
		-e "s@avl_tree\.h@avltree\.h@" \
		-e "s@crexx_license\.h@crexxlic\.h@" \
		-e "s@crexx_version\.h@crexxver\.h@" \
		-e "s@rxcp_ast_rewrite\.h@rcarewrt\.h@" \
		-e "s@rxcp_emit\.h@rxcpemit\.h@" \
		-e "s@rxcp_exit\.h@rxcpexit\.h@" \
		-e "s@rxcp_highlight_controller\.h@rchictl\.h@" \
		-e "s@rxcp_source_tree\.h@rcsrctr\.h@ " \
		-e "s@rxcp_token\.h@rctoken\.h@" \
		-e "s@rxcp_types\.h@rctypes\.h@" \
		-e "s@rxcp_util\.h@rcutil\.h@" \
		-e "s@rxvmplugin\.h@rxpl\.h@" \
		-e "s@rxvmplugin_framework\.h@rxplfr\.h@" \
		-e "s@\.\./avl_tree/avl_tree\.h@avltree\.h@" \
		-e "s@#include \".\./binutils/include/@#include \"@" \
		-e "s@#include \".\./\.\./inc@#include \"@" \
		-e "s@#include \".\./@#include \"@" 
done

# Fix all the references to the files CMS doesn't provide
for FILE in *.c *.h ; do
	sed -i "$FILE" \
		-e "s@Security/SecBase\.h@cmssecbs\.h@" \
		-e "s@Security/SecProtocolOptions\.h@cmssecop\.h@" \
		-e "s@arpa/inet\.h@cmsarpa\.h@" \
		-e "s@dispatch/dispatch\.h@cmsdspch\.h@" \
		-e "s@netinet/in\.h\.h@cmsnetin\.h\.h@" \
		-e "s@netinet/tcp\.h@cmstcp\.h@" \
		-e "s@openssl/err\.h@cmsssler\.h@" \
		-e "s@openssl/ssl\.h@cmsssl\.h@" \
		-e "s@openssl/x509_vfy\.h@cmssslvf\.h@" \
		-e "s@sys/ioctl\.h@cmsioctl\.h@" \
		-e "s@sys/random\.h@cmsrand\.h@" \
		-e "s@sys/resource\.h@cmsresrc\.h@" \
		-e "s@sys/socket\.h@cmssock\.h@" \
		-e "s@sys/stat\.h@cmsstat\.h@" \
		-e "s@sys/sysctl\.h@cmssysct\.h@" \
		-e "s@sys/sysinfo\.h@cmssysif\.h@" \
		-e "s@sys/time\.h@cmstime\.h@" \
		-e "s@sys/types\.h@cmstypes\.h@" \
		-e "s@sys/utime\.h@cmsutime\.h@" \
		-e "s@sys/wait\.h@cmswait\.h@" \
		-e "s@fcntl\.h@cmsfcntl\.h@"
#		-e "s@dlfcn\.h@cmsdlfcn\.h@"

done
